@echo off
echo -- String of parameters: %*
echo -- Parameter 1: %~1
echo -- Parameter 2: %~2
echo -- Parameter 3: %~3
set /a result1=%~1 + %~2
set /a result2=%~1 * %~2
set /a result3=%~3 / %~2
set /a result4=%~2 - %~1
set /a result5=(%~2 - %~1) * (%~1 - %~2)
echo Parameter 1 + Parameter 2 = %result1%
echo Parameter 1 * Parameter 2 = %result2%
echo Parameter 3 / Parameter 2 = %result3%
echo Parameter 2 - Parameter 1 = %result4%
echo (Parameter 2 - Parameter 1) * (Parameter 1 - Parameter 2) = %result5%
