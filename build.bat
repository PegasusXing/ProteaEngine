@echo off
setlocal enabledelayedexpansion

:: Colors ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
set COLOR_RESET=[0m
set COLOR_GREEN=[32m
set COLOR_RED=[31m
set COLOR_CYAN=[36m
set COLOR_YELLOW=[33m
set COLOR_WHITE=[37m
set COLOR_BLUE=[34m

:: ANSI ESCAPE CODES :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
for /f "tokens=2 delims=: " %%i in ('ver') do set ver=%%i
if %ver% GEQ 10 (
    reg query HKCU\Console | find "VirtualTerminalLevel" >nul 2>&1 || (
        reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1 /f >nul
    )
)

:MAIN_MENU
cls
echo -----------------------------------------------------------------------------
echo ------------------------  %COLOR_GREEN%ProteaEngine Build System%COLOR_RESET%  ------------------------
echo -----------------------------------------------------------------------------
echo --------------- %COLOR_YELLOW%NOTE: GCC MAY FAIL IF PROJECT REQUIRES C++20+%COLOR_RESET% ---------------
echo -----------------------------------------------------------------------------
echo 1. %COLOR_GREEN%Clang%COLOR_RESET%   (with Ninja)
echo 2. %COLOR_GREEN%GCC%COLOR_RESET%     (with Ninja)
echo 3. %COLOR_GREEN%MSVC%COLOR_RESET%    (Visual Studio 2022)
echo.
echo 4. %COLOR_RED%Exit%COLOR_RESET%
echo.

set /p choice="Enter your choice (1-4): "

if "%choice%"=="1" goto CLANG_BUILD
if "%choice%"=="2" goto GCC_BUILD
if "%choice%"=="3" goto MSVC_BUILD
if "%choice%"=="4" exit /b

echo Invalid choice, please try again.
pause
goto MAIN_MENU

:CHOOSE_CONFIG
echo.
echo Choose build configuration:
echo 1. Debug
echo 2. Release
echo 3. Dist
echo.
set /p config_choice="Enter your choice (1-3): "
if "%config_choice%"=="1" set BUILD_TYPE=Debug
if "%config_choice%"=="2" set BUILD_TYPE=Release
if "%config_choice%"=="3" set BUILD_TYPE=Dist

if not defined BUILD_TYPE (
    echo Invalid build configuration!
    pause
    goto MAIN_MENU
)
goto :eof

:CLANG_BUILD
cls
echo [Clang] Configuring and Building with Clang and Ninja...
call :CHOOSE_CONFIG
set BUILD_DIR=build-clang
set GENERATOR="Ninja"
set COMPILER_FLAGS=-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
set SINGLE_CONFIG=1
goto CONFIGURE_BUILD

:GCC_BUILD
cls
echo [GCC] Configuring and Building with GCC and Ninja...
call :CHOOSE_CONFIG
set BUILD_DIR=build-gcc
set GENERATOR="Ninja"
set COMPILER_FLAGS=-DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
set SINGLE_CONFIG=1
goto CONFIGURE_BUILD

:MSVC_BUILD
cls
echo [MSVC] Configuring and Building with Visual Studio 2022...
call :CHOOSE_CONFIG
set BUILD_DIR=build-msvc
set GENERATOR="Visual Studio 17 2022"
set COMPILER_FLAGS=-A x64
set SINGLE_CONFIG=0
goto CONFIGURE_BUILD

:CONFIGURE_BUILD
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
cd %BUILD_DIR%

echo [%COLOR_CYAN%Configuring %COLOR_RESET%] %BUILD_TYPE%
if %SINGLE_CONFIG%==1 (
    cmake -G %GENERATOR% %COMPILER_FLAGS% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ..
) else (
    cmake -G %GENERATOR% %COMPILER_FLAGS% ..
)

if %errorlevel% neq 0 (
    echo %COLOR_RED%CMake configuration failed!%COLOR_RESET%
    pause
    cd ..
    exit /b
)

echo [%COLOR_GREEN%Building %COLOR_RESET%] %BUILD_TYPE%
if %SINGLE_CONFIG%==1 (
    cmake --build .
) else (
    cmake --build . --config %BUILD_TYPE%
)

if %errorlevel% neq 0 (
    echo %COLOR_RED%Build failed!%COLOR_RESET%
    pause
    cd ..
    exit /b
)

echo %COLOR_GREEN%Build completed successfully in %BUILD_DIR%\%BUILD_TYPE%_x64 (MSVC) or directly in %BUILD_DIR% (others).%COLOR_RESET%
cd ..
pause
goto MAIN_MENU
