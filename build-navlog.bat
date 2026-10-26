
@echo off
setlocal enabledelayedexpansion

echo ======================================
echo Compilation NavLog - Windows 32 bits
echo ======================================

set "CONFIGURATION=Release"

REM Installation des dependances Windows
call "%~dp0buildwin\win_deps.bat"
if errorlevel 1 exit /b 1

REM Configuration CMake
cmake -S . -B build ^
  -G "Visual Studio 17 2022" ^
  -A Win32 ^
  -DCMAKE_BUILD_TYPE=%CONFIGURATION% ^
  -DwxWidgets_LIB_DIR="!wxWidgets_LIB_DIR!" ^
  -DwxWidgets_ROOT_DIR="!wxWidgets_ROOT_DIR!" ^
  "-DOCPN_TARGET_TUPLE=msvc-wx32;10;x86"

if errorlevel 1 exit /b 1

REM Compilation du paquet OpenCPN
cmake --build build --target tarball --config %CONFIGURATION%

if errorlevel 1 exit /b 1

echo ======================================
echo Compilation terminee
echo ======================================
