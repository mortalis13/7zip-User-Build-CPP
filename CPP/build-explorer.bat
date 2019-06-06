@echo off
rem -- Run from VS dev console

rem set PLATFORM=x64
set PLATFORM=x86

del /Q "7zip/UI/Explorer/%PLATFORM%"

cd "7zip/UI/Explorer"
call nmake PLATFORM=%PLATFORM%
cd ../../..
