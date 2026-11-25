@echo off
setlocal EnableExtensions

set "CURRENT_DIR=%~dp0"
set "GIT_COMPRESSION_DIR=%CURRENT_DIR%GitCompression"
set "PYTHON_PATH=python"
set "RESULT=0"

if not exist "%GIT_COMPRESSION_DIR%\RestoreLFS.py" (
    echo GitCompression scripts not found.
    exit /b 1
)

echo Choose an action:
echo 0. Compress files
echo 1. Restore files
set /p "choice=Enter 0 or 1: "

if "%choice%"=="0" (
    "%PYTHON_PATH%" "%GIT_COMPRESSION_DIR%\CompressLFS.py" "%CURRENT_DIR%"
    if errorlevel 1 (
        echo Compression failed.
        set "RESULT=1"
    ) else (
        echo Compression completed successfully.
    )
) else if "%choice%"=="1" (
    "%PYTHON_PATH%" "%GIT_COMPRESSION_DIR%\RestoreLFS.py" "%CURRENT_DIR%"
    if errorlevel 1 (
        echo Restore failed.
        set "RESULT=1"
    ) else (
        echo Restore completed successfully.
    )
) else (
    echo Invalid choice. Please enter 0 or 1.
    set "RESULT=1"
)

pause
exit /b %RESULT%
