# Microsoft Developer Studio Generated NMAKE File, Based on demo.dsp
!IF "$(CFG)" == ""
CFG=demo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to demo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "demo - Win32 Release" && "$(CFG)" != "demo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "demo.mak" CFG="demo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "demo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "demo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "demo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\demo.exe"


CLEAN :
	-@erase "$(INTDIR)\ChildView.obj"
	-@erase "$(INTDIR)\demo.obj"
	-@erase "$(INTDIR)\demo.res"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\demo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\demo.pch" /YX"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\demo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\demo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\demo.pdb" /machine:I386 /out:"$(OUTDIR)\demo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildView.obj" \
	"$(INTDIR)\demo.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\demo.res"

"$(OUTDIR)\demo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "demo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\demo.exe"


CLEAN :
	-@erase "$(INTDIR)\ChildView.obj"
	-@erase "$(INTDIR)\demo.obj"
	-@erase "$(INTDIR)\demo.res"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\demo.exe"
	-@erase "$(OUTDIR)\demo.ilk"
	-@erase "$(OUTDIR)\demo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\demo.pch" /YX"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\demo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\demo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\demo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\demo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ChildView.obj" \
	"$(INTDIR)\demo.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\demo.res"

"$(OUTDIR)\demo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("demo.dep")
!INCLUDE "demo.dep"
!ELSE 
!MESSAGE Warning: cannot find "demo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "demo - Win32 Release" || "$(CFG)" == "demo - Win32 Debug"
SOURCE=.\ChildView.cpp

"$(INTDIR)\ChildView.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\demo.cpp

"$(INTDIR)\demo.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdAfx.cpp

"$(INTDIR)\StdAfx.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\demo.rc

!IF  "$(CFG)" == "demo - Win32 Release"


"$(INTDIR)\demo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\demo.res" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "demo - Win32 Debug"


"$(INTDIR)\demo.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\demo.res" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 


!ENDIF 

