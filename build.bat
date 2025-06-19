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

:: Menu :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:MAIN_MENU
cls
echo -----------------------------------------------------------------------------
echo ------------------------  %COLOR_GREEN%ProteaEngine Build System%COLOR_RESET%  ------------------------
echo -----------------------------------------------------------------------------
echo ------- %COLOR_YELLOW%NOTE: GCC MAY FAIL IF ABOVE C++17 IS REQUIRED%COLOR_RESET% -------
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

:: Build Definitions ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:CLANG_BUILD
set COMPILER_NAME=clang
set C_COMPILER=clang
set CXX_COMPILER=clang++
set GENERATOR=Ninja
goto SINGLE_CONFIG_BUILD

:GCC_BUILD
set COMPILER_NAME=gcc
set C_COMPILER=gcc
set CXX_COMPILER=g++
set GENERATOR=Ninja
goto SINGLE_CONFIG_BUILD

:SINGLE_CONFIG_BUILD
for %%C in (Debug Release Dist) do (
    set BUILD_DIR=build-%COMPILER_NAME%-%%C
    echo [%COMPILER_NAME% / %%C] Configuring in !BUILD_DIR!...
    if not exist !BUILD_DIR! mkdir !BUILD_DIR!
    pushd !BUILD_DIR!
    cmake -G %GENERATOR% -DCMAKE_C_COMPILER=%C_COMPILER% -DCMAKE_CXX_COMPILER=%CXX_COMPILER% -DCMAKE_BUILD_TYPE=%%C ..
    if !errorlevel! neq 0 (
        echo %COLOR_RED%CMake configuration failed for %%C!%COLOR_RESET%
        popd
        pause
        goto MAIN_MENU
    )
    cmake --build .
    if !errorlevel! neq 0 (
        echo %COLOR_RED%Build failed for %%C!%COLOR_RESET%
        popd
        pause
        goto MAIN_MENU
    )
    popd
)
echo %COLOR_GREEN%All builds completed for %COMPILER_NAME%.%COLOR_RESET%
pause
goto MAIN_MENU

:MSVC_BUILD
set BUILD_DIR=build-msvc
echo [MSVC] Configuring in %BUILD_DIR%...
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
pushd %BUILD_DIR%
cmake -G "Visual Studio 17 2022" -A x64 ..
if !errorlevel! neq 0 (
    echo %COLOR_RED%CMake configuration failed for MSVC!%COLOR_RESET%
    popd
    pause
    goto MAIN_MENU
)

for %%C in (Debug Release Dist) do (
    echo [MSVC / %%C] Building...
    cmake --build . --config %%C
    if !errorlevel! neq 0 (
        echo %COLOR_RED%Build failed for %%C!%COLOR_RESET%
        popd
        pause
        goto MAIN_MENU
    )
)
popd
echo %COLOR_GREEN%All builds completed for MSVC.%COLOR_RESET%
pause
goto MAIN_MENU
