@echo off
rem First set up the helper batch files

cd batfiles
copy mingobj.bat obj.bat
copy minglib.bat lib.bat
copy mingexe.bat exe.bat

rem Now do the generic build
if "%1"=="" goto all
goto %1


:all
call makeall
goto end

:lib
call makelib
goto end

:tests
call maketest
goto end

:examples
call makeex
goto end


:end
cd ..

