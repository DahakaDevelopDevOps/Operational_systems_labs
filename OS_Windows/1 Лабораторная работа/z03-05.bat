@echo off
setlocal enabledelayedexpansion
set num1=%~1
set num2=%~2
set operator=%~3
if "!operator!"=="+" (
    set /a result=!num1! + !num2!
) else if "!operator!"=="-" (
    set /a result=!num1! - !num2!
) else if "!operator!"=="*" (
    set /a result=!num1! * !num2!
) else if "!operator!"=="/" (
    set /a result=!num1! / !num2!
) else (
    echo Invalid operator
    exit /b 1
)
echo !result!
endlocal
