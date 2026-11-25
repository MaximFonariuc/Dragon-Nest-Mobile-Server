import os
import ntpath
import shutil
import sys
import tempfile
import zipfile


def _safe_relative_path(root, value):
    value = value.replace("\\", os.sep).replace("/", os.sep)
    if os.path.isabs(value) or ntpath.isabs(value) or ntpath.splitdrive(value)[0]:
        raise ValueError(f"Absolute paths are not allowed in the restore log: {value}")
    target = os.path.realpath(os.path.join(root, value))
    if os.path.commonpath((root, target)) != root:
        raise ValueError(f"Path escapes the restore directory: {value}")
    return target


def _part_numbers(archive_base):
    directory = os.path.dirname(archive_base)
    prefix = os.path.basename(archive_base) + ".part"
    numbers = []
    for name in os.listdir(directory):
        if name.startswith(prefix):
            suffix = name[len(prefix):]
            if suffix.isdigit():
                numbers.append(int(suffix))
    return sorted(numbers)


def _assemble_parts(archive_base):
    numbers = _part_numbers(archive_base)
    if not numbers:
        raise FileNotFoundError(f"No archive parts found for {archive_base}")
    if numbers != list(range(1, numbers[-1] + 1)):
        raise ValueError(f"Archive parts are missing or out of order for {archive_base}")

    temp_fd, temp_path = tempfile.mkstemp(
        prefix=".restore-", suffix=".zip", dir=os.path.dirname(archive_base)
    )
    try:
        with os.fdopen(temp_fd, "wb") as output:
            for part_number in numbers:
                part_path = f"{archive_base}.part{part_number}"
                with open(part_path, "rb") as source:
                    shutil.copyfileobj(source, output)
        return temp_path
    except Exception:
        if os.path.exists(temp_path):
            os.remove(temp_path)
        raise


def _restore_archive(archive_path, original_path):
    expected_name = os.path.basename(original_path)
    target_dir = os.path.dirname(original_path)
    os.makedirs(target_dir, exist_ok=True)

    with zipfile.ZipFile(archive_path, "r") as archive:
        bad_member = archive.testzip()
        if bad_member is not None:
            raise zipfile.BadZipFile(f"Corrupt ZIP member: {bad_member}")

        members = [item for item in archive.infolist() if not item.is_dir()]
        if len(members) != 1 or members[0].filename != expected_name:
            raise ValueError(
                f"Unexpected ZIP contents; expected exactly {expected_name!r}"
            )

        member = members[0]
        unix_mode = (member.external_attr >> 16) & 0o170000
        if unix_mode == 0o120000:
            raise ValueError("Symbolic links are not allowed in restore archives")

        fd, temp_target = tempfile.mkstemp(
            prefix=".restore-", dir=target_dir
        )
        try:
            with os.fdopen(fd, "wb") as output, archive.open(member, "r") as source:
                shutil.copyfileobj(source, output)
            os.replace(temp_target, original_path)
        except Exception:
            if os.path.exists(temp_target):
                os.remove(temp_target)
            raise


def _remove_parts(archive_base):
    for part_number in _part_numbers(archive_base):
        os.remove(f"{archive_base}.part{part_number}")


def restore_files(directory):
    root = os.path.realpath(directory)
    log_file = os.path.join(root, "compression_log.txt")
    if not os.path.isfile(log_file):
        print("No compression log found; nothing to restore.")
        return True

    with open(log_file, "r", encoding="utf-8-sig") as log:
        entries = [line.strip() for line in log if line.strip()]

    for line_number, entry in enumerate(entries, start=1):
        if "|" not in entry:
            raise ValueError(f"Invalid log entry on line {line_number}: missing '|'")

        original_rel, archive_rel = entry.split("|", 1)
        original_path = _safe_relative_path(root, original_rel.strip())
        archive_rel = archive_rel.strip()
        is_split = archive_rel.endswith(".part*")
        archive_base_rel = archive_rel[:-6] if is_split else archive_rel
        archive_path = _safe_relative_path(root, archive_base_rel)

        if os.path.exists(original_path):
            artifacts_exist = (
                os.path.exists(archive_path)
                if not is_split
                else os.path.exists(f"{archive_path}.part1")
            )
            if artifacts_exist:
                raise FileExistsError(
                    f"Refusing to overwrite existing file: {original_rel}"
                )
            print(f"Already restored: {original_rel}")
            continue

        temporary_archive = None
        try:
            if is_split:
                temporary_archive = _assemble_parts(archive_path)
                source_archive = temporary_archive
            else:
                source_archive = archive_path

            print(f"Restoring {original_rel}...")
            _restore_archive(source_archive, original_path)

            if is_split:
                _remove_parts(archive_path)
            else:
                os.remove(archive_path)
        finally:
            if temporary_archive and os.path.exists(temporary_archive):
                os.remove(temporary_archive)

    os.remove(log_file)
    print("All files restored successfully.")
    return True


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python RestoreLFS.py <directory>")
        sys.exit(2)

    directory_to_restore = sys.argv[1]
    if not os.path.isdir(directory_to_restore):
        print(f"Error: {directory_to_restore} is not a valid directory.")
        sys.exit(2)

    try:
        restore_files(directory_to_restore)
    except Exception as error:
        print(f"Restore failed: {error}", file=sys.stderr)
        sys.exit(1)
