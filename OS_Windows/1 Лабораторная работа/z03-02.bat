@echo off
echo Name Of file: %~nx0
for /f "delims=" %%a in ('powershell -Command "& {Get-Item -Path '%~f0' | ForEach-Object { $_.CreationTime.ToString('yyyy-MM-dd HH:mm:ss') }}"') do set "filedate=%%a"
echo Date of Creation: %filedate%
echo Path to file: %~dp0
pause
