@echo off

:: Setting compiler path
where >nul 2>nul g++.exe
if %errorlevel% neq 0 if [%1] == [] (
	echo Command "g++" not found in PATH
	exit /b 0
)

if [%1] == [] (set compiler_path=g++) else (set compiler_path=%1)

:: Creating build folder
if not exist ./build mkdir build

:: Generating *.o files
if exist buildignore.txt (
    for /f "delims=" %%G in ('dir /b /s *.cpp ^|findstr /v /i /g:"buildignore.txt"') do (
    	%compiler_path% -c -Isrc -o build/%%~nG.o %%G
    )
) else (
    for /R %%f in (*.cpp) do (
    	%compiler_path% -c -Isrc -o build/%%~nf.o %%f
    )
)

:: Generating .exe
%compiler_path% -o build/main.exe build/*.o

:: Cleaning variable
set "compiler_path="

:: Running .exe
.\build\main.exe
