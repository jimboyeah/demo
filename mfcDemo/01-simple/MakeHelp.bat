@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by DEMO.HPJ. >"hlp\demo.hm"
echo. >>"hlp\demo.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\demo.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\demo.hm"
echo. >>"hlp\demo.hm"
echo // Prompts (IDP_*) >>"hlp\demo.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\demo.hm"
echo. >>"hlp\demo.hm"
echo // Resources (IDR_*) >>"hlp\demo.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\demo.hm"
echo. >>"hlp\demo.hm"
echo // Dialogs (IDD_*) >>"hlp\demo.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\demo.hm"
echo. >>"hlp\demo.hm"
echo // Frame Controls (IDW_*) >>"hlp\demo.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\demo.hm"
REM -- Make help for Project DEMO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\demo.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\demo.hlp" goto :Error
if not exist "hlp\demo.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\demo.hlp" Debug
if exist Debug\nul copy "hlp\demo.cnt" Debug
if exist Release\nul copy "hlp\demo.hlp" Release
if exist Release\nul copy "hlp\demo.cnt" Release
echo.
goto :done

:Error
echo hlp\demo.hpj(1) : error: Problem encountered creating help file

:done
echo.
