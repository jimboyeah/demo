#
#  Nmake makefile demo by Jimbowhy @ 2016/3/20 1:58:36
#  Usage:
#      nmake BUILD=RELEASE mouse
#      nmake BUILD=RELEASE all
#      nmake all

CC=@cl -c /ZI /Yd /MLd /Od /D "DEBUG" /nologo -c -GX /D "_MBCS"
CL=@link /nologo
MC=@mc.exe
RC=@rc.exe

CFLAGS=/I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include"
LFLAGS=/LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\VC98\lib"
libs=winmm.lib gdi32.lib user32.lib advapi32.lib kernel32.lib msimg32.lib

#CFLAGS=$(CFLAGS) /I"C:\sdks\PSDK2k3SP1\Include"
#LFLAGS=$(LFLAGS) /LIBPATH:"C:\sdks\PSDK2k3SP1\Lib" 

!IF	"$(BUILD)" == "RELEASE"
CC=@cl -c /D "NDEBUG" /nologo -GX /D "_MBCS"
!ENDIF

all : array base64 bitmap hanoi mouse rc4 record resource runtime Serializer setTimer vector wildcard

array:
	$(CC) $(CFLAGS) -o array array.cpp
    $(CL) $(LFLAGS) array.obj $(libs)
base64:
	$(CC) $(CFLAGS) -o base64 base64.cpp
    $(CL) $(LFLAGS) base64.obj $(libs)
bitmap:
	$(CC) $(CFLAGS) -o bitmap bitmap.cpp
    $(CL) $(LFLAGS) bitmap.obj $(libs)
hanoi:
	$(CC) $(CFLAGS) -o hanoi hanoi.cpp
    $(CL) $(LFLAGS) hanoi.obj $(libs)
mouse:
	$(CC) $(CFLAGS) -o mouse mouse.cpp
    $(CL) $(LFLAGS) mouse.obj $(libs)
rc4:
	$(CC) $(CFLAGS) -o rc4 rc4.cpp
    $(CL) $(LFLAGS) rc4.obj $(libs)
record:
	$(CC) $(CFLAGS) -o record record.cpp
    $(CL) $(LFLAGS) record.obj $(libs)
resource:
	$(MC) -u -U -r .\res -h .\res res\resource.mc
	$(RC) /w /fo .\res.obj res\res.rc
	$(CC) $(CFLAGS) -o resource resource.cpp
    $(CL) $(LFLAGS) resource.obj res.obj $(libs)
runtime:
	$(CC) $(CFLAGS) -o runtime runtime.cpp
    $(CL) $(LFLAGS) runtime.obj $(libs)
Serializer:
	$(CC) $(CFLAGS) Serializer.cpp
    $(CL) $(LFLAGS) Serializer.obj
setTimer:
	$(CC) $(CFLAGS) -o setTimer setTimer.cpp
    $(CL) $(LFLAGS) setTimer.obj $(libs)
vector:
	$(CC) $(CFLAGS) -o vector vector.cpp
    $(CL) $(LFLAGS) vector.obj $(libs)
wildcard:
	$(CC) $(CFLAGS) -o wildcard wildcard.cpp
    $(CL) $(LFLAGS) wildcard.obj $(libs)

clean:
	del *.obj *.idb *.pdb *.res
    
