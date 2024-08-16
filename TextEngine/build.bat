@echo off
REM Navigate to the src directory
cd src

REM Compile the source files and link them into an executable
gcc -o main main.c view.c engine.c input.c game.c -I ../include

REM Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b %errorlevel%
)

echo Compilation successful!

REM Navigate back to the root directory
cd ..

REM Run the executable
src\main.exe

pause