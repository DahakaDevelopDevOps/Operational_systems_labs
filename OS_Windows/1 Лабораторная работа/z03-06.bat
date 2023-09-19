@echo off
setlocal enabledelayedexpansion

:menu
cls
echo Available modes:
echo 1. Create file
echo 2. Delete file
echo p. Display available modes
echo q. Quit
set /p input=Enter your choice: 

if "!input!"=="1" (
    set /p filename=Enter filename: 
    if not "!filename!"=="" (
        if not exist "!filename!" (
            type nul > "!filename!"
            echo File created successfully
        ) else (
            echo This file already exists
        )
    ) else (
        echo Invalid filename
    )
    pause
    goto :menu
) else if "!input!"=="2" (
    set /p filename=Enter filename: 
    if not "!filename!"=="" (
        if exist "!filename!" (
            del "!filename!"
            echo File deleted successfully
        ) else (
            echo The file does not exist
        )
    ) else (
        echo Invalid filename
    )
    pause
    goto :menu
) else if "!input!"=="p" (
    goto :menu
) else if "!input!"=="q" (
    echo Exiting...
) else (
    echo Invalid choice
    pause
    goto :menu
)

endlocal
