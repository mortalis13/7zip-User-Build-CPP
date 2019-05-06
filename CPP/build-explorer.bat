@echo off
rem -- Run from VS dev console

set PLATFORM=x64
rem set PLATFORM=x86

rem del /Q "7zip/UI/Explorer/%PLATFORM%"

cd "7zip/UI/Explorer"
call nmake PLATFORM=%PLATFORM%
cd ../../..
