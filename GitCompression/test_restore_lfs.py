import os
import tempfile
import unittest
import zipfile

import RestoreLFS


class RestoreLFSTests(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory()
        self.root = self.temp_dir.name

    def tearDown(self):
        self.temp_dir.cleanup()

    def _make_archive(self, archive_path, member_name, payload):
        with zipfile.ZipFile(archive_path, "w", zipfile.ZIP_DEFLATED) as archive:
            archive.writestr(member_name, payload)

    def test_restores_regular_archive(self):
        payload = b"regular restore payload"
        self._make_archive(os.path.join(self.root, "data.bin.zip"), "data.bin", payload)
        with open(os.path.join(self.root, "compression_log.txt"), "w") as log:
            log.write("data.bin|data.bin.zip\n")

        self.assertTrue(RestoreLFS.restore_files(self.root))
        with open(os.path.join(self.root, "data.bin"), "rb") as restored:
            self.assertEqual(restored.read(), payload)
        self.assertFalse(os.path.exists(os.path.join(self.root, "data.bin.zip")))
        self.assertFalse(os.path.exists(os.path.join(self.root, "compression_log.txt")))

    def test_restores_split_archive(self):
        payload = b"split restore payload" * 200
        archive_path = os.path.join(self.root, "data.bin.zip")
        self._make_archive(archive_path, "data.bin", payload)
        with open(archive_path, "rb") as source:
            archive_bytes = source.read()
        os.remove(archive_path)

        split_at = len(archive_bytes) // 2
        for index, chunk in enumerate(
            (archive_bytes[:split_at], archive_bytes[split_at:]), start=1
        ):
            with open(f"{archive_path}.part{index}", "wb") as part:
                part.write(chunk)

        with open(os.path.join(self.root, "compression_log.txt"), "w") as log:
            log.write("data.bin|data.bin.zip.part*\n")

        self.assertTrue(RestoreLFS.restore_files(self.root))
        with open(os.path.join(self.root, "data.bin"), "rb") as restored:
            self.assertEqual(restored.read(), payload)
        self.assertFalse(os.path.exists(f"{archive_path}.part1"))
        self.assertFalse(os.path.exists(f"{archive_path}.part2"))

    def test_rejects_zip_path_traversal(self):
        archive_path = os.path.join(self.root, "data.bin.zip")
        self._make_archive(archive_path, "../outside.txt", b"unsafe")
        with self.assertRaises(ValueError):
            RestoreLFS._restore_archive(archive_path, os.path.join(self.root, "data.bin"))
        self.assertFalse(os.path.exists(os.path.join(os.path.dirname(self.root), "outside.txt")))

    def test_rejects_path_traversal_in_log(self):
        with self.assertRaises(ValueError):
            RestoreLFS._safe_relative_path(self.root, "../outside.txt")
        with self.assertRaises(ValueError):
            RestoreLFS._safe_relative_path(self.root, "C:\\outside.txt")

    def test_rejects_missing_split_part(self):
        archive_path = os.path.join(self.root, "data.bin.zip")
        with open(f"{archive_path}.part1", "wb") as part:
            part.write(b"part one")
        with open(f"{archive_path}.part3", "wb") as part:
            part.write(b"part three")
        with self.assertRaises(ValueError):
            RestoreLFS._assemble_parts(archive_path)


if __name__ == "__main__":
    unittest.main()
