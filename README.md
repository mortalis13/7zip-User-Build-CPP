
# 7zip User-Build

Based on **7zip build 1900**: https://www.7-zip.org/a/7z1900-src.7z.

## Changes

- added numbers for some context menu commands (**0-Compress, 1-Extract Here, 2-Extract to \***) for faster navigation
- added **"Extract to Folder or Plain"** menu, extracts an archive contents to a folder if it has more than 1 element in the root or extracts the contents directly into the current folder
- added **"Compress to \*"** menu to create separate archives for each selected file (currently it opens multiple compress dialogs, though it should be done using some sort of operations queue)
- updated **FileManager** context menu options to be able to enable/disable the added menu items

## Build

- Visual Studio 2017
- open **VS Dev Console**: `Start -> Visual Studio 2017 -> Visual Studio Tools -> VC -> x64 Native Tools Command Prompt for VS 2017`
- or execute the next command from the default console to load VS build environment:
  ```
  %comspec% /k "[PROGRAM_FILES]\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
  ```
- execute commands inside the command prompt:
  ```
  cd [PATH_TO_7Z_SOURCE]\CPP\7zip\UI\Explorer
  nmake PLATFORM=x64
  ```
- there are also `.bat` scripts inside the **CPP** folder to build **FileManager** and **Explorer** modules

## Installation

- download a [release](https://github.com/mortalis13/7zip-User-Build-CPP/releases) and copy **7-zip.dll** and **7zFM.exe** to the **7-Zip** installation folder
- you may have to kill the **explorer.exe** process in the **Task Manager** to unlock the existing **7-zip.dll**, then execute **explorer.exe** from the **"Task Manager -> File -> Run new task"** to restore the **Windows Explorer** shell
- **7zFM.exe** should have the changed context menu items in the **"Tools -> Options -> 7-Zip"**
