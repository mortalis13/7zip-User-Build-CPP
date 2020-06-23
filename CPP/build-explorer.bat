@echo off
rem -- Run from VS dev console

rem set PLATFORM=x86
set PLATFORM=x64

echo.
echo --- Building for %PLATFORM%
echo.
echo.

del /Q "7zip/UI/Explorer/%PLATFORM%"

cd "7zip/UI/Explorer"
call nmake PLATFORM=%PLATFORM%
cd ../../..
