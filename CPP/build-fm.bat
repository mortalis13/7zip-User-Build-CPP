@echo off
rem -- Run from VS dev console

rem set PLATFORM=x64
set PLATFORM=x86

del /Q "7zip/UI/FileManager/%PLATFORM%"

cd "7zip/UI/FileManager"
call nmake PLATFORM=%PLATFORM%
cd ../../..
