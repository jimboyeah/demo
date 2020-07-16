# NMake自动化编译工具-微软版

- MD DoCumEnT: 3/19/2016 6:08:42 PM  by Jimbowhy

上一篇相关文章讲了 [GNU make 自动化编译工具][1]，而这一次就来学习一下微软平台的 NMAKE 自动化编译工具。管，NMake 许多功能都不同，但目的是一样的，而且规则定义格式也都相似，所以会 GNU MAKE 后可以很快掌握 NMAKE 的使用。

The syntax for NMAKE is:

NMAKE [option...] [macros...] [targets...] [@commandfile...]


参考案例：

    #
    #  Nmake makefile demo by Jimbowhy @ 2016/3/20 1:58:36
    #  Usage:
    #      nmake BUILD=RELEASE mouse
    #      nmake BUILD=RELEASE all
    #      nmake all

    CC=cl -c /ZI /Yd /MLd /Od /D "DEBUG" /nologo -c -GX /D "_MBCS"
    CL=link /nologo
    CFLAGS=/I"C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include"
    LFLAGS=/LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\VC98\lib"
    libs=winmm.lib gdi32.lib user32.lib

    !IF	"$(BUILD)" == "RELEASE"
    CC=cl -c /D "NDEBUG" /nologo -GX /D "_MBCS"
    !ENDIF

    all : array base64 bitmap hanoi mouse rc4 record Serializer setTimer vector wildcard

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
        del *.obj


[1]: http://blog.csdn.net/winsenjiansbomber/article/details/50758180