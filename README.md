
# 7zip User-Build

Based on **7zip build 1900**: https://www.7-zip.org/a/7z1900-src.7z.

## Changes

- added numbers for some context menu commands (Compress, Extract) for faster navigation
- new menu "Extract to Folder or Plain", extracts an archive contents to a folder if it has more than 1 element in the root or extracts the contents directly into the current folder
- updated FileManager context menu options to be able to enable/disable the added menu items

## Build

- Visual Studio 2017
- open **VS Dev Console**
  - Start -> Visual Studio 2017 -> Visual Studio Tools -> VC -> x64 Native Tools Command Prompt for VS 2017
  - %comspec% /k "[PROGRAM_FILES]\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
- execute commands inside the command prompt:
  ```
  cd 7z-src\CPP\7zip\UI\Explorer
  nmake PLATFORM=x64
  ```

## Installation

- copy **7-zip.dll** and **7zFM.exe** to the **7-Zip** folder
- you may have to kill the **explorer.exe** process in the **Task Manager** to unlock the existing **7-zip.dll**, then execute **explorer.exe** from the **Task Manager -> File -> Run new task** to restore the **Windows Explorer** shell
- **7zFM.exe** should have the changed context menu items in the **Tools -> Options -> 7-Zip**
