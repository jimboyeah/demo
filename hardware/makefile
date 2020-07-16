#
#  Nmake makefile demo by Jimbowhy @ 2016/3/20 1:58:36
#  Usage:
#      nmake DEBUG=1 all
#      nmake all

CC=@cl -c /D "NDEBUG" /nologo -GX
CL=@link /nologo
MC=@mc.exe
RC=@rc.exe

CFLAGS=/I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include"
LFLAGS=/LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\VC98\lib"
libs=winmm.lib gdi32.lib user32.lib advapi32.lib kernel32.lib msimg32.lib

#CFLAGS=$(CFLAGS) /I"C:\sdks\PSDK2k3SP1\Include"
#LFLAGS=$(LFLAGS) /LIBPATH:"C:\sdks\PSDK2k3SP1\Lib" 

!IF	"$(DEBUG)" == "1"
CC=@cl -c /ZI /Yd /MLd /Od /D "DEBUG" /nologo -c -GX
!ENDIF

all : cpuid int1a

cpuid:
	$(CC) $(CFLAGS) -o cpuid cpuid.cpp
    $(CL) $(LFLAGS) cpuid.obj $(libs)
int1a:
	$(CC) $(CFLAGS) -o int1a int1a.cpp
    $(CL) $(LFLAGS) int1a.obj $(libs)

clean:
	del *.obj *.idb *.pdb *.res
    
