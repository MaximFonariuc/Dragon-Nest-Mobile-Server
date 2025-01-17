@echo off
REM Настройки
set MYSQL_USER=root
set MYSQL_PASSWORD=
set MYSQL_HOST=127.0.0.1
set SQL_FILES_DIR=DataBaseInits

echo Running SQL files to create databases...

REM Проверка наличия папки с SQL-файлами
if not exist "%SQL_FILES_DIR%" (
    echo Error: Directory "%SQL_FILES_DIR%" does not exist.
    pause
    exit /b 1
)

REM Проверка наличия SQL-файлов в папке
set file_count=0
for %%f in ("%SQL_FILES_DIR%\*.sql") do set /a file_count+=1

if %file_count% == 0 (
    echo Error: No SQL files found in "%SQL_FILES_DIR%".
    pause
    exit /b 1
)

REM Выполнение SQL-файлов
for %%f in ("%SQL_FILES_DIR%\*.sql") do (
    echo Executing the file: %%f
    mysql -h %MYSQL_HOST% -u %MYSQL_USER% -p%MYSQL_PASSWORD% < %%f
    if errorlevel 1 (
        echo Error: Failed to execute the file: %%f
        pause
        exit /b 1
    )
)

echo All SQL scripts have been executed successfully.
pause