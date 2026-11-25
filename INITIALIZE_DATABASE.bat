@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "MYSQL_USER=root"
set "MYSQL_PASSWORD="
set "MYSQL_HOST=127.0.0.1"
set "SQL_FILES_DIR=DataBaseInits"

echo Running SQL files to create databases...

if not exist "%SQL_FILES_DIR%\" (
    echo Error: Directory "%SQL_FILES_DIR%" does not exist.
    exit /b 1
)

set /a FILE_COUNT=0
for %%F in ("%SQL_FILES_DIR%\*.sql") do (
    if exist "%%~fF" set /a FILE_COUNT+=1
)

if !FILE_COUNT! EQU 0 (
    echo Error: No SQL files found in "%SQL_FILES_DIR%".
    exit /b 1
)

for %%F in ("%SQL_FILES_DIR%\*.sql") do (
    if exist "%%~fF" (
        echo Executing: %%~nxF
        mysql --host="%MYSQL_HOST%" --user="%MYSQL_USER%" --password="%MYSQL_PASSWORD%" < "%%~fF"
        if errorlevel 1 (
            echo Error: Failed to execute %%~nxF
            exit /b 1
        )
    )
)

echo All SQL scripts executed successfully.
exit /b 0
