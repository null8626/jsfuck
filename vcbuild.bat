@echo off
setlocal
set JSFUCK_PADDING=0xfff

cd src

for /f %%I in ('dir /s /b *.c') do cl.exe /nologo /O2 /I ..\include /D JSFUCK_PADDING=%JSFUCK_PADDING% /c "%%~nxI"

lib.exe /nologo /OUT:..\jsfuck.lib *.obj

del /s /q *.obj > nul
cd ..

cl.exe /nologo /O2 /I .\include .\transpiler\*.c .\jsfuck.lib /Fe"jsfuck.exe"

endlocal