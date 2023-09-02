@echo off
setlocal enabledelayedexpansion
:menu
echo Press 'p' to display available modes
set /p input=Enter your choice: 
if "!input!"=="p" (
    echo Available modes:
    echo 1. Create file
    echo 2. Delete file
    goto :menu
) else if "!input!"=="1" (
    set /p filename=Enter filename: 
    type nul > !filename!
    echo File created successfully
    goto :menu
) else if "!input!"=="2" (
    set /p filename=Enter filename: 
    del !filename!
    echo File deleted successfully
    goto :menu
) else (
    echo Invalid choice
    goto :menu
)
endlocal
