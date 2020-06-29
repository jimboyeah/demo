
# GCC - GNU Compiler Collection
- [MinGW](http://www.mingw.org/)
- [GCC 参数详解](https://www.runoob.com/w3cnote/gcc-parameter-detail.html)
- [GCC 5 Release Series](https://gcc.gnu.org/gcc-5/)
- [GCC - the GNU Compiler Collection](https://gcc.gnu.org/)
- [mingw-w64 GCC for Windows 64 & 32 bits](http://mingw-w64.org/doku.php)
- [GCC Invocation](https://gcc.gnu.org/onlinedocs/gcc-5.5.0/cpp/Invocation.html)


GNU 编译器套件 GNU Compiler Collection 包括 C、C++、Objective-C、Fortran、Java、Ada 和 Go 语言的前端，也包括了这些语言的库，如 libstdc++、libgcj 等等。GCC 的初衷是为GNU操作系统专门编写的一款编译器。GNU 系统是彻底的自由软件。此处，自由的含义是它尊重用户的自由。

此外，TCC - Tiny C Compiler 是一个小巧的编译器，用来研究编译原理是不错的目标。

MinGW 就是 GCC 的 Windows 移植版。

MinGW - Minimalist GNU on Windows 是将经典的开源 C/C++ 语言编译器 GCC 移植到了 Windows 平台下，并且包含了 Win32API ，因此可以将源代码编译为可在 Windows 中运行的可执行程序。而且还可以使用一些 Windows 不具备的，Linux 平台下的开发工具。

MinGW 包含 32-bit 和 64-bit 两种，MinGW-w64 可以编译生成 64-bit 或 32-bit 可执行程序。
正因为如此，MinGW 32-bit 版本现已被 MinGW-w64 所取代，且 MinGW 也早已停止了更新，内置的 GCC 停滞在了 4.8.1 版本，而 MinGW-w64 内置的 GCC 则持续更新。

使用 MinGW-w64 的优势：

- MinGW-w64 是开源软件，可以免费使用。
- MinGW-w64 由一个活跃的开源社区在持续维护，因此不会过时。
- MinGW-w64 支持最新的 C/C++ 语言标准。
- MinGW-w64 使用 Windows 的 C 语言运行库，因此，可以编译出无 DLL 依赖的 Windows 程序。
- 许多开源 IDE 集成 MinGW-w64，如 CodeBlocks，使它拥有友好的图形化界面。

MinGW-w64 是稳定可靠的、持续更新的 C/C++ 编译器，使用它可以免去很多麻烦，不用担心跟不上时代，也不用担心编译器本身有bug，可以放心的去编写程序。

GCC 有多个 Windows 移植版本，比较出名的就是 MinGW 和 TDM-GCC：

- MinGW：http://www.mingw.org/
- TDM-GCC: http://tdm-gcc.tdragon.net/download
- Cygwin：http://www.cygwin.com/

gcc 命令的常用选项：

| 选项        | 解释    |
| :-------  | :-------  |
| -ansi     | 只支持 ANSI 标准的 C 语法。这一选项将禁止 GNU C 的某些特色， 例如 asm 或 typeof 关键词。 |
| -c        | 只编译并生成目标文件。 |
| -DMACRO   | 以字符串"1"定义 MACRO 宏。 |
| -DMACRO   | DEFN    以字符串"DEFN"定义 MACRO 宏。 |
| -E        | 只运行 C 预编译器。 |
| -g        | 生成调试信息。GNU 调试器可利用该信息。 |
| -IDIRECTORY   | 指定 DIRECTORY 为额外的头文件搜索路径。 |
| -LDIRECTORY   | 指定 DIRECTORY 为额外的函数库搜索路径。 |
| -lLIBRARY     | 连接时搜索指定的函数库LIBRARY。 |
| -m486     | 针对 486 进行代码优化。 |
| -o        | FILE 生成指定的输出文件。用在生成可执行文件时。 |
| -O0       | 不进行优化处理。 |
| -O        | 或 -O1    优化生成代码。 |
| -O2       | 进一步优化。 |
| -O3       | 比 -O2 更进一步优化，包括 inline 函数。 |
| -shared   | 生成共享目标文件。通常用在建立共享库时。 |
| -static   | 禁止使用共享连接。 |
| -UMACRO   | 取消对 MACRO 宏的定义。 |
| -w        | 不生成任何警告信息。 |
| -Wall     | 生成所有警告信息。 |


# DLL with MinGW
- [Building Windows DLLs with MinGW](https://www.transmissionzero.co.uk/computing/building-dlls-with-mingw/)
- [MinGW-w64 GCC for Windows](https://zhuanlan.zhihu.com/p/76613134)
- [Advanced MinGW DLL Topics](https://www.transmissionzero.co.uk/computing/advanced-mingw-dll-topics/)

在 Windows 下用 MinGW 编译 DLL：

    /* add_basic.c
       Demonstrates creating a DLL with an exported function, the inflexible way.
    */

    __declspec(dllexport) int __cdecl Add(int a, int b)
    {
      return (a + b);
    }

只需要添加 `-shared` 链接选项：

    >gcc -c -o add_basic.o add_basic.c
    >gcc -o add_basic.dll -s -shared add_basic.o -Wl,--subsystem,windows

以上分步演示了编译和链接两个过程，但是 GCC 可以一步执行：

    gcc -o add_basic.dll -s -shared add_basic.c -Wl,--subsystem,windows

其中 `-Wl,--subsystem,windows` 不是必要的参数，因为不是编译窗口程序。注意 `-s` 选项，它清理导出的 DLL 符号，通过在发布 DLL 时使用。

对于动态链接库，用户在程序中使用时，为了程序能正确链接，就需要`导入库` Import Library，即链接程序中使用的 `.lib` 文件。

下面，试着写一个程序来调用动态链接库的 Add(a, b) 方法：

    /* addtest_basic.c
       Demonstrates using the function imported from the DLL, the inelegant way.
    */

    #include <stdlib.h>
    #include <stdio.h>

    /* Declare imported function so that we can actually use it. */
    __declspec(dllimport) int __cdecl Add(int a, int b);

    int main(int argc, char** argv)
    {
      printf("%d\n", Add(6, 23));

      return EXIT_SUCCESS;
    }

现在，执行编译链接：

    >gcc -c -o addtest_basic.o addtest_basic.c
    >gcc -o addtest_basic.exe -s addtest_basic.o -L. -ladd_basic
    >addtest_basic.exe

其它 DLL 使用的高级知识点：

- Displaying functions exported from a DLL.
- The DllMain function.
- Using a module definition file.
- Exporting undecorated stdcall functions.
- Exporting C++ functions and variables from a DLL.
- Creating JNI DLLs.
- P/Invoking MinGW DLLs in .NET
- Setting the DLL base address.
- Loading and unloading DLLs at runtime.


## Exported Funtion Information

使用 GNU binutils objdump 查看 DLL 导出函数符号：

    >objdump -p AddLib.dll
    
    There is an export table in .edata at 0x6da46000

    The Export Tables (interpreted .edata section contents)

    Export Flags                    0
    Time/Date stamp                 4da9a500
    Major/Minor                     0/0
    Name                            00006046 AddLib.dll
    Ordinal Base                    1
    Number in:
            Export Address Table            00000003
            [Name Pointer/Ordinal] Table    00000003
    Table Addresses
            Export Address Table            00006028
            Name Pointer Table              00006034
            Ordinal Table                   00006040

    Export Address Table -- Ordinal Base 1
            [   0] +base[   1] 1280 Export RVA
            [   1] +base[   2] 2004 Export RVA
            [   2] +base[   3] 2000 Export RVA

    [Ordinal/Name Pointer] Table
            [   0] Add
            [   1] bar
            [   2] foo

    >dumpbin -exports AddLib.dll
    Microsoft (R) COFF/PE Dumper Version 9.00.30729.01
    Copyright (C) Microsoft Corporation.  All rights reserved.


    Dump of file AddLib.dll

    File Type: DLL

      Section contains the following exports for AddLib.dll

        00000000 characteristics
        4DA9A500 time date stamp Sat Apr 16 15:17:36 2011
            0.00 version
               1 ordinal base
               3 number of functions
               3 number of names

        ordinal hint RVA      name

              1    0 00001280 Add
              2    1 00002004 bar
              3    2 00002000 foo

      Summary

            1000 .CRT
            1000 .bss
            1000 .data
            1000 .edata
            1000 .eh_fram
            1000 .idata
            1000 .rdata
            1000 .reloc
            1000 .rsrc
            1000 .text
            1000 .tls

## The DllMain function.

DllMain 是 DLL 入口函数，在加载或卸载时被系统调用：

    #include <windows.h>

    BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
    {
      switch (fdwReason)
      {
        case DLL_PROCESS_ATTACH:
          /* Code path executed when DLL is loaded into a process's address space. */
          break;

        case DLL_THREAD_ATTACH:
          /* Code path executed when a new thread is created within the process. */
          break;

        case DLL_THREAD_DETACH:
          /* Code path executed when a thread within the process has exited *cleanly*. */
          break;

        case DLL_PROCESS_DETACH:
          /* Code path executed when DLL is unloaded from a process's address space. */
          break;
      }

      return TRUE;
    }

## Using a module definition file.

除了 `__declspec(dllexport)` 标记一个导出函数，更方便的做法是使用模块定义文件 module definition file，它可以定义 DLL 中导出的变量、函数等等，如下 `AddLib.def`：

    LIBRARY AddLib.dll
    EXPORTS
      Add
      foo
      bar

对应的 C 文件头：

    /* Define calling convention in one place, for convenience. */
    #define ADDCALL __cdecl

    /* Make sure functions are exported with C linkage under C++ compilers. */
    #ifdef __cplusplus
    extern "C"
    {
    #endif

    /* Declare our Add function using the above definitions. */
    int ADDCALL Add(int a, int b);

    /* Exported variables. */
    extern int foo;
    extern int bar;

    #ifdef __cplusplus
    } // __cplusplus defined.
    #endif

头文件中的导出变量、函数依然使用了 extern 关键字，确保它们在使用中能正确链接，函数实现代码如下：

    #include "add.h"

    int ADDCALL Add(int a, int b)
    {
      return (a + b);
    }

    /* Assign value to exported variables. */
    int foo = 7;
    int bar = 41;

在编译链接命令中使用模块定义文件 `AddLib.def`：

    >gcc -O3 -std=c99 -Wall -c add.c -o add.o
    >gcc -o AddLib.dll add.o AddLib.def -shared -s -Wl,--subsystem,windows,--out-implib,libaddlib.a

## Exporting Undecorated stdcall Functions

导出函数意味着 stdcall 调用转换，即 `int Add(int, int)` 这样的函数签名会导出变成 `Add@8` 类似格式，`@` 符号后面跟着的数字表示参数占据的空间，而 Microsoft’s Visual C++ 还会使用其它前缀，如下划线 `_Add@8`。正因为 MSVC 和 MinGW 不同编译器之间的转换不一致，当开发出来的 DLL 被多用户使用时，他们使用什么编译器就受到约束了。

解决办法就是避免导出时，编译器对函数的重命名，传递 `--kill-at` 选项给链接程序，同时，需要重建导入库 import library，否则用户不能正确链接特殊处理过的导出函数。此时，`--out-implib` 创建的导入库无效，需要使用 `dlltool.exe` 工具，还有模块定义文件，它包含了函数正确的导出名字：

    >gcc -o AddLib.dll add.o -shared -s -Wl,--subsystem,windows,--output-def,AddLib.def
    >gcc -o AddLib.dll add.o -shared -s -Wl,--subsystem,windows,--kill-at
    >dlltool --kill-at -d AddLib.def -D AddLib.dll -l libaddlib.a

上面的命令首先会创建修饰过函数名称的 DLL，使用了 `--output-def,AddLib.def` 链接参数生成模块定义文件，它包含了修饰过的函数名称。

第二步还是创建 DLL，但是传入了 `--kill-at` 链接参数，导出的函数名是未修饰过的，这一步不能创建模块定义文件。

最后，基于模块定义文件创建导入库，如果你关心不同编译器的表现，这一步会很有趣。事实上，Win32 API 函数都是以这种方式导出的，没有任何修饰。

## Exporting C++ functions and variables

在 C++ DLL 的导出符号中，不同编译器之间是不通用的，甚至同一个编译器不同版本也不通用。因为 C++ 的复杂性，要处理异常、虚函数实现、或 STL 类型的不同内存模型等等。为了明确不兼容，编译器还会使用名称变形 `name mangling` 来处理导出符号。

导出全局符号，函数和变量，C/C++ 的做法都是一样的，不同的是 C 语言导出全局变量时，可以作为 C++ 对象实例导出，导出函数时可以重载。还可以导出 C++ 的类对象，这个导出的类对象所有静态方法和成员不区分 public、protected、private 访问修饰。

示例 Point 头文件：

    #ifndef POINT_HPP
    #define POINT_HPP

    #ifdef POINT_EXPORTS
      #define POINTAPI __declspec(dllexport)
    #else
      #define POINTAPI __declspec(dllimport)
    #endif

    #include <ostream>

    using std::ostream;

    class POINTAPI Point
    {
      public:
        // Constructors.
        Point();
        Point(int x, int y);

        // Getters and setters.
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);

        // Friend the overloaded operators, so they can access private Point data.
        friend Point operator+(const Point& lhs, const Point& rhs);
        friend ostream& operator<<(ostream& os, const Point& pt);

      private:
        int x, y;
    };

    // Overloaded operators.
    POINTAPI Point operator+(const Point& lhs, const Point& rhs);
    POINTAPI ostream& operator<<(ostream& os, const Point& pt);

    extern POINTAPI Point foo;
    extern POINTAPI Point bar;

    #endif

实现代码：

    #include "point.hpp"

    Point::Point()
      : x(0), y(0)
    { }

    Point::Point(int x, int y)
      : x(x), y(y)
    { }

    int Point::getX() const { return this->x; }

    int Point::getY() const { return this->y; }

    void Point::setX(int x) { this->x = x; }

    void Point::setY(int y) { this->y = y; }

    Point operator+(const Point& lhs, const Point& rhs)
    {
      return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    ostream& operator<<(ostream& os, const Point& pt)
    {
      return os << "(" << pt.x << ", " << pt.y << ")";
    }

    Point foo(9, 6);
    Point bar(3, 19);

编译生成 C++ 代码的 DLL，和 C 语言的 DLL 没有区别：

    >g++ -c -o point.o point.cpp -D POINT_EXPORTS
    >g++ -o point.dll point.o -s -shared -Wl,--subsystem,windows,--out-implib,libpoint.a 

或者生成静态库，链接成无动态链接依赖的程序：

    >gcc -c src\*.cpp -Iinclude
    >ar rcs libpoint.a *.o
    >gcc pointTest.cpp -I include/ -L lib/ -l point -o testPoint.exe


打包归档命令 ar 将所有 .o 文件打包为静态库，r 将文件插入静态库中，c 创建静态库，不管库是否存在，s 写入一个目标文件索引到库中，或者更新一个存在的目标文件索引。

这时创建了导入库 libpoint.a，这是可选的，因为除了链接程序，还有其它方法调用 DLL 中的 API。

使用 `objdump -p` 命令查看导出符号，可以我发现类似 `_ZN5Point4setXEi`、`_ZlsRSoRK5Point` 这样的符号。使用 c++filt 可以将导出的 C++ 符号还原 demangling：

    >c++filt -n _ZlsRSoRK5Point
    operator<<(std::basic_ostream<char, std::char_traits<char> >&, Point const&)

    >c++filt -n _ZN5Point4setXEi
    Point::setX(int)
    _ZN5Point4setYEi

    Point::setY(int)
    _ZN5PointC1Eii
    Point::Point(int, int)
    _ZN5PointC1Ev
    Point::Point()
    _ZN5PointC2Eii
    Point::Point(int, int)
    _ZN5PointC2Ev
    Point::Point()
    _ZNK5Point4getXEv
    Point::getX() const
    _ZNK5Point4getYEv
    Point::getY() const
    _ZlsRSoRK5Point
    operator<<(std::basic_ostream<char, std::char_traits<char> >&, Point const&)
    _ZplRK5PointS1_
    operator+(Point const&, Point const&)

创建 DLL 后，就可以写测试程序：

    #include <iostream>
    #include "point.hpp"

    using namespace std;

    int main(int argc, char** argv)
    {
      Point a;
      Point b(2, 7);
      Point c;
      
      c.setX(85);
      c.setY(24);
      
      cout << "a = " << a << endl;
      cout << "b = " << b << endl;
      cout << "c = (" << c.getX() << ", " << c.getY() << ")\n";

      cout << "foo + bar = " << foo << " + " << bar << " = " << (foo + bar) << endl;

      return 0;
    }

编译链接测试程序 testPoint.cpp：

    >g++ -c -o pointtest.o pointtest.cpp
    >g++ -o pointtest.exe -s pointtest.o -L. -lpoint
    >pointtest.exe a = (0, 0)

    b = (2, 7)
    c = (85, 24)
    foo + bar = (9, 6) + (3, 19) = (12, 25)

发布 DLL 时，需要注意避免破坏其它程序的正常运行，应该给 DLL 附加一个版本号后缀以区别，如下：

    point-mingw-4.5.2.dll
    point-msvc-2010.dll


这个工程目录结构：

    ─ ${application}
      ├── example
      │   ├── CMakeLists.txt 
      │   └── testPoint.cpp
      ├── include
      │   └── point.hpp
      ├── src
      │   └── point.cpp
      ├── CMakeLists.txt 
      └── DllDemo.sublime-project 

为了使用 CMake 自动化编译，在工程顶级目录设置 CMakeLists.txt：

    cmake_minimum_required(VERSION 2.8)

    project( dllDemo )

    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -Wall -O2")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -g -Wall -O2 -std=c++11")

    set(CMAKE_CXX_FLAGS "-w" )
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

    if (POLICY CMP0054)
        cmake_policy(SET CMP0015 NEW)
    endif()

    include_directories( "./include/" )

    # Static Libs
    # set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    set(BUILD_SHARED_LIBS ON)

    set(ENV{PATH} C:/CodeBlocks/MinGW/bin)
    message($ENV{PATH})
    execute_process(COMMAND where g++ )
    execute_process(COMMAND where make )

    aux_source_directory("src/" src)
    add_library( point ${src} )

    # message( ${CMAKE_INSTALL_LIBDIR} )
    install(TARGETS point DESTINATION "/lib")
    install(TARGETS point DESTINATION "${PROJECT_SOURCE_DIR}/bin")

    add_subdirectory(example bin EXCLUDE_FROM_ALL)
    # add_subdirectory(example bin)

在 example 子目录下设置 CMakeLists.txt：

    cmake_minimum_required(VERSION 2.8)

    include_directories("${PROJECT_SOURCE_DIR}/include/")
    link_directories( 
        "${PROJECT_BINARY_DIR}/lib/"
        "${PROJECT_SOURCE_DIR}/lib/"
        )

    # set(CMAKE_CXX_FLAGS "-Wl,-Bstatic" )
    # set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    # link_libraries(point)

    add_executable(PointTest pointTest.cpp)

    # dynamic link
    add_executable(PointTest pointTest.cpp)
    target_link_libraries( PointTest point )

    # static linke
    # set_property(TARGET point PROPERTY IMPORTED_LOCATION libpoint.a)
    # add_executable(PointTest pointTest.cpp)
    # target_link_libraries( PointTest libpoint.a )


作为小巧、功能强大的 SublimeText，用它来编写 C++ 工程是组好的选择，工程文件配置如下，Ctrl-Shift-B 调用设置好的命令，先执行 CMake 生成 MinGW Makefiles 编译脚本，再执行 Make 或 Make install 生成动态链接库，然后生成 PointTest 程序：

    {
        "build_systems":
        [
            {
                "env":{
                    "PATH":"c:/CodeBlocks/MinGW/bin/;%PATH%"
                },
                "encoding": "utf8",
                "file_regex": "^  (.+)\\((\\d+)\\)(): ((?:fatal )?(?:error|warning) \\w+\\d\\d\\d\\d: .*) \\[.*$",
                "name": "MinGW Build (Windows)",
                "quiet": true,
                "shell_cmd": "cmake --build .",
                "variants":
                [
                    {
                        "name": "Make help",
                        "shell_cmd": "make help"
                    }, {
                        "name": "MinGW Makefiles",
                        "shell_cmd": "cmake .. -G \"MinGW Makefiles\""
                    }, {
                        "name": "clean",
                        "shell_cmd": "make clean"
                    }, {
                        "name": "clear all",
                        "shell_cmd": "del * /s /q"
                    }, {
                        "name": "Make",
                        "shell_cmd": "make -j 4 all"
                    }, {
                        "name": "Make install",
                        "shell_cmd": "make install"
                    }, {
                        "name": "Make PointTest",
                        "shell_cmd": "make PointTest"
                    }
                ],
                "working_dir": "${project_path}/build"
            }
        ],
        "folders":
        [
            {
                "path": ".",
                "binary_file_patterns":["*.noting"],
                "name": "Dll Demo Project",
            }
        ],
        "settings":
        {
            "cmake":
            {
                "build_folder": "${project_path}/build"
            }
        }
    }



## Creating JNI DLLs

## P/Invoking MinGW DLLs in .NET

## Setting the DLL base address

## Loading and unloading DLLs at runtime


