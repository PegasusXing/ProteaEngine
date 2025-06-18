@echo off
setlocal enabledelayedexpansion

rem Store the current script directory and switch to root directory
pushd "%~dp0\.."

:MAIN_MENU
cls
echo -----------------------------------------------------
echo --- ProteaEngine Build System - Compiler Selector ---
echo -----------------------------------------------------
echo.
echo 1. Clang   (with Ninja)
echo NOTE: DOESN'T GCC WORK DUE TO CXX STANDARD 17 due to
echo (EventFormatter.h) conflicts... Will fix.
echo 2. GCC     (with Ninja)
echo 3. MSVC    (Visual Studio 2022)
echo.
echo 4. Exit
echo.

set /p choice="Enter your choice (1-4): "

if "%choice%"=="1" goto CLANG_BUILD
if "%choice%"=="2" goto GCC_BUILD
if "%choice%"=="3" goto MSVC_BUILD
if "%choice%"=="4" goto END

echo Invalid choice, please try again.
pause
goto MAIN_MENU

:CLANG_BUILD
cls
echo [Clang] Configuring and Building with Clang and Ninja...
set BUILD_DIR=build-clang
set GENERATOR="Ninja"
set COMPILER_FLAGS=-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
goto CONFIGURE_BUILD

:GCC_BUILD
cls
echo [GCC] Configuring and Building with GCC and Ninja...
set BUILD_DIR=build-gcc
set GENERATOR="Ninja"
set COMPILER_FLAGS=-DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
goto CONFIGURE_BUILD

:MSVC_BUILD
cls
echo [MSVC] Configuring and Building with Visual Studio 2022...
set BUILD_DIR=build-msvc
set GENERATOR="Visual Studio 17 2022"
set COMPILER_FLAGS=-A x64 -DCMAKE_CONFIGURATION_TYPES="Debug;Release"
goto CONFIGURE_BUILD

:CONFIGURE_BUILD
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
cd %BUILD_DIR%

cmake -G %GENERATOR% %COMPILER_FLAGS% -DCMAKE_BUILD_TYPE=Debug ..
if %errorlevel% neq 0 (
    echo CMake configuration failed!
    pause
    goto MAIN_MENU
)

cmake --build .
if %errorlevel% neq 0 (
    echo Build failed!
    pause
    goto MAIN_MENU
)

echo Build completed successfully in %BUILD_DIR% directory.
cd ..
pause
goto MAIN_MENU

:END
popd
exit /b
