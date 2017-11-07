@ECHO OFF
setlocal ENABLEDELAYEDEXPANSION

SET GITBRANCH=
	for /f "tokens=2" %%I in ('git.exe branch 2^> NUL ^| findstr /b "* "') do set GITBRANCH=%%I
SET CWD=%CD%

ECHO BRANCH=%GITBRANCH%
ECHO CWD=%CWD%

:VCVARSALL_CHECK
@ECHO FINDING CL.EXE ...
CALL WHERE cl.exe /q

IF %ERRORLEVEL% EQU 0 (	
	WHERE cl.exe
	GOTO :CLEAR_BUILD
	
) ELSE (
    @ECHO CL.EXE MISSING, FINDING VCVARSALL.BAT ...
	REM RESET ERROR LEVEL
	VER > NUL
	
	IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvarsall.bat" (
		@ECHO FOUND VCVARSALL.BAT ^(2017 Professional^)		
		CALL "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvarsall.bat" x86
		CD %CWD%
		GOTO :VCVARSALL_READY
	) ELSE IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" (
		@ECHO FOUND vcvarsall.bat ^(2017 Community^)		
		CALL "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
		CD %CWD%
		GOTO :VCVARSALL_READY
	) ELSE (
		@ECHO VCVARSALL NOT FOUND! EXITING
		GOTO :DONE
	)	
)

:VCVARSALL_READY
REM FINAL CHECK
VER > NUL
CALL WHERE cl.exe /q
if %ERRORLEVEL% EQU 0 (
	WHERE cl.exe
	GOTO :CLEAR_BUILD
) ELSE (
	@ECHO VCVARSALL FAILED!
	GOTO :DONE
)

:CLEAR_BUILD
IF EXIST "_Build" (
 	del /f/s/q _Build > nul
 	rmdir /s/q _Build
)
IF EXIST "_Build" (
 	del /f/s/q _Build > nul
 	rmdir /s/q _Build
)
 
MD _Build && CD _Build
CALL CMake -D BUILD_PLATFORM:string=Win32 -G "Visual Studio 15" ..

:DONE
@ECHO DONE!