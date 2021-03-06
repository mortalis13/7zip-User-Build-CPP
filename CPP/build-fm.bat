@echo off
rem -- Run from VS dev console

rem set PLATFORM=x86
set PLATFORM=x64
if not "%1"=="" (
  set PLATFORM=%1
)

echo.
echo --- Building for %PLATFORM%
echo.
echo.

del /Q "7zip/UI/FileManager/%PLATFORM%"

cd "7zip/UI/FileManager"
call nmake PLATFORM=%PLATFORM%
cd ../../..
