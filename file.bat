@echo off
set BuildDir=Build
set Generator="Visual Studio 17 2022"

if not exist %BuildDir% (
    mkdir %BuildDir%
)

cd %BuildDir%

cmake -G %Generator% ..

if %errorlevel% neq 0 (
    echo Ошибка конфигурации проекта
    pause
    exit /b %errorlevel%
)

cmake --build . --config Release

if %errorlevel% neq 0 (
    echo Ошибка сборки проекта
    pause
    exit /b %errorlevel%
)

cd ..

echo Сборка завершена. Проект находится в директории %BuildDir%
pause