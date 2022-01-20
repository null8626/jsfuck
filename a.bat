@echo off
setlocal

set STR=

for /f %%I in ('dir /a:-d-h /s /b src\*.c') do (
	set STR=%STR% %%~nxI
)

echo %STR%
endlocal