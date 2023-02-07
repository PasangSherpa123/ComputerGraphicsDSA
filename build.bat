@ echo off
where g++ >NUL 2>NUL
if %ERRORLEVEL% neq 0 GOTO :END
g++ main.cpp -o build/main.exe
:END
./build/main.exe
