# 仓库说明

此分支演示 CPP 程序，还有 CMake + Ninja + GNU Make 自动编译，及 CMake Test 的使用。

![gitchat](https://github.com/jimboyeah/demo/blob/cppDemos/sublime-cmake-ninja.jpg)

使用 Sublime 工程管理，Ctrl-Shift-B 选择编译命令，要求安装 MinGW 编译器。

初始运行，首先生成 MinGW Makefile，再执行 Make 编译生成程序。执行 Make Test 命令会自动生成程序并进行测试：

     "C:\Program Files (x86)\CMake\bin\cmake.exe" -SC:\cppDemos -BC:\cppDemos\build --check-build-system CMakeFiles\Makefile.cmake 0
    -- AddDemo=string-funcs.cpp
    -- AddDemo=string-null-tm.cpp
    -- Configuring done
    -- Generating done
    -- Build files have been written to: C:/coding/md-code/cppDemos/build
    "C:\Program Files (x86)\CMake\bin\cmake.exe" -E cmake_progress_start C:\cppDemos\build\CMakeFiles C:\cppDemos\build\\CMakeFiles\progress.marks
    make -s -f CMakeFiles\Makefile2 all
    [ 50%] Built target string-funcs.cpp
    [100%] Built target string-null-tm.cpp
    "C:\Program Files (x86)\CMake\bin\cmake.exe" -E cmake_progress_start C:\cppDemos\build\CMakeFiles 0
    Running tests...
    "C:\Program Files (x86)\CMake\bin\ctest.exe" --force-new-ctest-process 
    Test project C:/coding/md-code/cppDemos/build
        Start 1: string-null-tm
    1/2 Test #1: string-null-tm ...................   Passed    0.02 sec
        Start 2: string-funcs
    2/2 Test #2: string-funcs .....................   Passed    0.02 sec

    100% tests passed, 0 tests failed out of 2

    Total Test time (real) =   0.06 sec

根据 Sublime 工程文件设置的 PATH 环境变量访问系统安装的 MinGW 编译器套件，执行 Make help 可以检查是否版本正确无误：

    GNU Make 4.2.1
    Built for Windows32
    Copyright (C) 1988-2016 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.
    g++ (GCC) 9.2.0
    Copyright (C) 2019 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.



# GCC - GNU Compiler Collection
- [GCC - the GNU Compiler Collection](https://gcc.gnu.org/)
- [GCC Releases](http://gcc.gnu.org/releases.html)
- [GCC 5 Release Series](https://gcc.gnu.org/gcc-5/)
- [C++ Standards Support in GCC](http://gcc.gnu.org/projects/cxx-status.html)
- [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support)
- [GCC 8.1.0 Doucmentation](https://gcc.gnu.org/onlinedocs/gcc-8.1.0/gcc/)
- [GCC Invocation](https://gcc.gnu.org/onlinedocs/gcc-5.5.0/cpp/Invocation.html)
- [GCC 参数详解](https://www.runoob.com/w3cnote/gcc-parameter-detail.html)
- [mingw-w64 GCC for Windows 64 & 32 bits](http://mingw-w64.org/doku.php)
- [MinGW](http://www.mingw.org/)
- [MinGW Distro](https://nuwen.net/mingw.html)

GNU 编译器套件 GNU Compiler Collection 包括 C、C++、Objective-C、Fortran、Java、Ada 和 Go 语言的前端，也包括了这些语言的库，如 libstdc++、libgcj 等等。GCC 的初衷是为GNU操作系统专门编写的一款编译器。GNU 系统是彻底的自由软件。此处，自由的含义是它尊重用户的自由。

对于后缀为 `.c` 的文件 gcc 把它当作是 C 程序，而 g++ 当作是 c++ 程序。后缀为 `.cpp` 的，两者都会认为是 C++ 程序，虽然 C++ 是 C 的超集，但是两者对语法的要求是有区别的。在编译阶段，g++ 会调用 gcc，对于 C++ 代码，两者是等价的，但是因为 gcc 命令不能自动和 C++ 程序使用的库联接，所以通常用 g++ 来完成链接，为了统一起见，干脆编译链接统统用 g++。

此外，TCC - Tiny C Compiler 是一个小巧的编译器，用来研究编译原理是不错的目标。

MinGW 就是 GCC 的 Windows 移植版。

MinGW - Minimalist GNU on Windows 是将经典的开源 C/C++ 语言编译器 GCC 移植到了 Windows 平台下，并且包含了 Win32API ，因此可以将源代码编译为可在 Windows 中运行的可执行程序。而且还可以使用一些 Windows 不具备的，Linux 平台下的开发工具。

MinGW 包含 32-bit 和 64-bit 两种，MinGW-w64 可以编译生成 64-bit 或 32-bit 可执行程序，使用 `-m32` 选项。
正因为如此，MinGW 32-bit 版本现已被 MinGW-w64 所取代，且 MinGW 也早已停止了更新，内置的 GCC 停滞在了 4.8.1 版本，而 MinGW-w64 内置的 GCC 则持续更新。

使用 MinGW-w64 的优势：

- MinGW-w64 是开源软件，可以免费使用。
- MinGW-w64 由一个活跃的开源社区在持续维护，因此不会过时。
- MinGW-w64 支持最新的 C/C++ 语言标准。
- MinGW-w64 使用 Windows 的 C 语言运行库，因此，可以编译出无 DLL 依赖的 Windows 程序。
- 许多开源 IDE 集成 MinGW-w64，如 CodeBlocks，使它拥有友好的图形化界面。

MinGW-w64 是稳定可靠的、持续更新的 C/C++ 编译器，使用它可以免去很多麻烦，不用担心跟不上时代，也不用担心编译器本身有bug，可以放心的去编写程序。

GCC 有多个 Windows 移植版本，比较出名的就是 MinGW 和 TDM-GCC，最新版本 MinGW-W64 GCC-8.1.0：

- MinGW：http://www.mingw.org/
- TDM-GCC: http://tdm-gcc.tdragon.net/download
- Cygwin：http://www.cygwin.com/

MinGW Distro 是提供了一个开箱即用的打包,提供最新的 MinGW 17.1 包含以下常用部件:

| Essentials    | Libraries     | Utilities     | Utilities     |
| :-----------  | :-----------  | :-----------  | :-----------  |
| binutils 2.33.1| Boost 1.71.0 | coreutils 8.31| 7-Zip 19.00   |
| GCC 9.2.0     | FreeType 2.10.1| gdb 8.3.1    | git 2.24.1.2  |
| mingw-w64 7.0 | glbinding 3.1.0| grep 3.3 |               |
|               | GLFW 3.3      | LAME 3.100    |               |
|               | GLM 0.9.9.6   | make 4.2.1    |               |
|               | libjpeg-turbo 2.0.3| OptiPNG 0.7.7    |       |
|               | libogg 1.3.4  | pngcheck 2.3.0    |           |
|               | libpng 1.6.37 | sed 4.7       |               |
|               | libvorbis 1.3.6| vorbis-tools 1.4.0   |       |
|               | PCRE 8.43**   |               |               |
|               | PCRE2 10.34** |               |               |
|               | SDL 2.0.10    |               |               |
|               | SDL_mixer 2.0.4|              |               |
|               | zlib 1.2.11   |               |               |
|               | zstd 1.4.4    |               |               |


目前 C 语言的标准有：C89(ANSI C)、C90、C95、C99(ISO C)、C11（C1x）。

目前 C++ 语言的标准有：C++98、C++03（对98小幅修改）、C++11（全面进化）、C++14、C++17、C++18、C++20。

目前来说 C++11 是普及标准。

高版本的 GCC 向下兼容，支持低版本的 C++ 标准：

| GCC 版本    | 发布日期  | C++ 标准    |
| :-------  | :-------  | :-------  |
| GCC 4.3   | Mar 2008  | C++11 部分支持，C++14 部分支持 |
| GCC 4.8.1 | May 2013  | C++11 完全支持，C++14 部分支持 |
| GCC 5.3   | Dec 2015  | C++14 完全支持，C++17 部分支持 |
| GCC 6.1   | Apr 2016  | C++14 完全支持，C++17 部分支持 |
| GCC 7.1   | May 2017  | C++17 完全支持    |
| GCC 8.1   | May 2018  | C++2a 部分支持    |
| GCC 10.1  | May 2020  | C++20 基本支持    |

使用 `g++ -v --help` 可以查询当前版本支持的标准：

|       Standard      | GCC 9.2 | GCC 8.1 | GCC 5.3 |                            Note                            |
|---------------------|---------|---------|---------|------------------------------------------------------------|
| -std=c++03          | ✅       | ✅       | ✅       | ✓ ISO 1998 C++ 2003 修订版，同 `-std=c++98`                |
| -std=c++0x          | ✅       | ✅       | ✅       | ✗ 弃用，`-std=c++11` 替代，同 `-std=c++11`                 |
| -std=c++11          | ✅       | ✅       | ✅       | ✓ ISO 2011 C++                                             |
| -std=c++14          | ✅       | ✅       | ✅       | ✓ ISO 2014 C++                                             |
| -std=c++17          | ✅       | ✅       | ✅       | ✓ ISO 2017 C++                                             |
| -std=c++1y          | ✅       | ✅       | ✅       | ✗ 弃用，`-std=c++14` 替代，同 `-std=c++14`                 |
| -std=c++1z          | ✅       | ✅       | ✅       | ✗ 弃用，`-std=c++17` 替代，同 `-std=c++17`                 |
| -std=c++2a          | ✅       | ✅       | ❌       | ✓ ISO 2020(?) C++ draft [体验]                             |
| -std=c++98          | ✅       | ✅       | ✅       | ✓ ISO 1998 C++ 2003 修订版                                 |
| -std=c11            | ✅       | ✅       | ✅       | ✓ ISO 2011 C                                               |
| -std=c17            | ✅       | ✅       | ❌       | ✓ ISO 2017 C (2018)                                        |
| -std=c18            | ✅       | ✅       | ❌       | ✓ ISO 2017 C (2018)，同 `-std=c17`                         |
| -std=c1x            | ✅       | ✅       | ✅       | ✗ 弃用，`-std=c11` 替代，同 `-std=c11`                     |
| -std=c2x            | ✅       | ❌       | ❌       | ✓ ISO 202X C 标准草案 [体验]                               |
| -std=c89            | ✅       | ✅       | ✅       | ✓ ISO 1990 C 标准，同 `-std=c90`                           |
| -std=c90            | ✅       | ✅       | ✅       | ✓ ISO 1990 C                                               |
| -std=c99            | ✅       | ✅       | ✅       | ✓ ISO 1999 C                                               |
| -std=c9x            | ✅       | ✅       | ✅       | ✗ 弃用，`-std=c99` 替代，同 `-std=c99`                     |
| -std=gnu++03        | ✅       | ✅       | ✅       | ✓ ISO 1998 C++ 2003 修订版，带 GNU 扩展，同 `-std=gnu++98` |
| -std=gnu++0x        | ✅       | ✅       | ✅       | ✗ 弃用，`-std=gnu++11` 替代，同 `-std=gnu++11`             |
| -std=gnu++11        | ✅       | ✅       | ✅       | ✓ ISO 2011 C++ 标准，带 GNU 扩展                           |
| -std=gnu++14        | ✅       | ✅       | ✅       | ✓ ISO 2014 C++ 标准，带 GNU 扩展                           |
| -std=gnu++17        | ✅       | ✅       | ✅       | ✓ ISO 2017 C++ 标准，带 GNU 扩展                           |
| -std=gnu++1y        | ✅       | ✅       | ✅       | ✗ 弃用，`-std=gnu++14` 替代，同 std=gnu++14                |
| -std=gnu++1z        | ✅       | ✅       | ✅       | ✗ 弃用，`-std=gnu++17` 替代，同 std=gnu++17                |
| -std=gnu++2a        | ✅       | ✅       | ❌       | ✓ ISO 2020(?) C++ draft 标准，带 GNU 扩展 [体验]           |
| -std=gnu++98        | ✅       | ✅       | ✅       | ✓ ISO 1998 C++ 2003 修订版，带 GNU 扩展                    |
| -std=gnu11          | ✅       | ✅       | ✅       | ✓ ISO 2011 C 标准，带 GNU 扩展                             |
| -std=gnu17          | ✅       | ✅       | ❌       | ✓ ISO 2017 C (2018)，带 GNU 扩展                           |
| -std=gnu18          | ✅       | ✅       | ❌       | ✓ ISO 2017 C (2018)，带 GNU 扩展，同 std=gnu17             |
| -std=gnu1x          | ✅       | ✅       | ✅       | ✗ 弃用，`-std=gnu11` 替代，同 std=gnu11                    |
| -std=gnu2x          | ✅       | ❌       | ❌       | ✓ ISO 202X C 标准草案，带 GNU 扩展  [体验]                 |
| -std=gnu89          | ✅       | ✅       | ✅       | ✓ ISO 1990 C 标准，带 GNU 扩展，同 std=gnu90               |
| -std=gnu90          | ✅       | ✅       | ✅       | ✓ ISO 1990 C 标准，带 GNU 扩展                             |
| -std=gnu99          | ✅       | ✅       | ✅       | ✓ ISO 1999 C 标准，带 GNU 扩展                             |
| -std=gnu9x          | ✅       | ✅       | ✅       | ✗ 弃用，`-std=gnu99` 替代，同 std=gnu99                    |
| -std=iso9899:1990   | ✅       | ✅       | ✅       | ✓ ISO 1990 C 标准，同 std=c90                              |
| -std=iso9899:199409 | ✅       | ✅       | ✅       | ✓ ISO 1990 C as amended in 1994                            |
| -std=iso9899:1999   | ✅       | ✅       | ✅       | ✓ ISO 1999 C 标准，同 std=c99                              |
| -std=iso9899:199x   | ✅       | ✅       | ✅       | ✗ 弃用，`-std=iso9899:1999` 替代，同 std=c99               |
| -std=iso9899:2011   | ✅       | ✅       | ✅       | ✓ ISO 2011 C 标准，同 std=c11                              |
| -std=iso9899:2017   | ✅       | ✅       | ❌       | ✓ ISO 2017 C (2018)，同 `-std=c17`                         |
| -std=iso9899:2018   | ✅       | ✅       | ❌       | ✓ ISO 2017 C (2018)，同 `-std=c17`                         |

## GCC CLI 命令

GCC 环境变量：

| 变量名                | 功能                                                               |
| :-------              | :-------                                                           |
| `CPATH`               | 搜索目录列表，也可以使用命令选项，如 -I. -I/special/include        |
| `C_INCLUDE_PATH`      | 搜索目录列表，分隔符号由 PATH_SEPARATOR 变量指定，通常是分号或冒号 |
| `CPLUS_INCLUDE_PATH`  | 搜索目录列表                                                       |
| `OBJC_INCLUDE_PATH`   | 搜索目录列表                                                       |
| `DEPENDENCIES_OUTPUT` | 非系统依赖的输出，相当命令选项 -MM、-MT 和 -MF 结合                |
| `SUNPRO_DEPENDENCIES` | 类似 DEPENDENCIES_OUTPUT，除了系统头文件不被忽略，相当 -M 选项     |


GCC 命令的常用选项：

|     选项     |                                           解释                                           |
|--------------|------------------------------------------------------------------------------------------|
| -ansi        | 只支持 ANSI 标准的 C 语法。这一选项将禁止 GNU C 的某些特色， 例如 asm 或 typeof 关键词。 |
| -c           | 只编译并生成目标文件。                                                                   |
| -DMACRO      | 以字符串"1"定义 MACRO 宏。                                                               |
| -DMACRO DEFN | 以字符串"DEFN"定义 MACRO 宏。                                                            |
| -E           | 只运行 C 预编译器。                                                                      |
| -g           | 生成调试信息，一般用于生成 Debug 版本程序，GNU 调试器可利用该信息。                      |
| -IDIRECTORY  | 指定 DIRECTORY 为额外的头文件搜索路径。                                                  |
| -LDIRECTORY  | 指定 DIRECTORY 为额外的函数库搜索路径。                                                  |
| -lLIBRARY    | 连接时搜索指定的函数库LIBRARY。                                                          |
| -m486        | 针对 486 进行代码优化。                                                                  |
| -o           | FILE 生成指定的输出文件。用在生成可执行文件时。                                          |
| -O0          | 不进行优化处理。                                                                         |
| -O           | 或 -O1    优化生成代码。                                                                 |
| -O2          | 进一步优化。                                                                             |
| -O3          | 比 -O2 更进一步优化，包括 inline 函数。                                                  |
| -s           | 清理符号 --strip-all 生成更小的可执行程序文件                                            |
| -shared      | 生成共享目标文件，通常用在建立共享库时。                                                 |
| -static      | 使用静态共享连接。                                                                       |
| -UMACRO      | 取消对 MACRO 宏的定义。                                                                  |
| -w           | 不生成任何警告信息。                                                                     |
| -Wall        | 生成所有警告信息。                                                                       |


Microsoft Visual C++，版本对应 C++ 标准关系如下所示：

| VS 版本            | 编译器版本 | C++ 标准                       |
| :-------           | :-------   | :-------                       |
| Visual Studio 6    | vc6        |                                |
| Visual Studio 2003 | vc7        |                                |
| Visual Studio 2005 | vc8        |                                |
| Visual Studio 2008 | vc9        |                                |
| Visual Studio 2010 | vc10       |                                |
| Visual Studio 2012 | vc11       | C++11 基本支持                 |
| Visual Studio 2013 | vc12       | C++11 基本支持，C++14 部分支持 |
| Visual Studio 2015 | vc14       | C++17 部分支持                 |
| Visual Studio 2017 | vc15       | C++14 完全支持，C++17 基本支持 |
| Visual Studio 2019 | vc16       | C++14 完全支持，C++17 基本支持 |

CodeBlocks 工程 GCC 生成 Debug/Release 的配置，注意 `-g` 调试选项和 `-s`、`-O` 优化选项的使用:

    <?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
    <CodeBlocks_project_file>
        <FileVersion major="1" minor="6" />
        <Project>
            <Option title="multithread" />
            <Option pch_mode="2" />
            <Option compiler="gcc" />
            <Build>
                <Target title="Debug">
                    <Option output="bin/Debug/multithread" prefix_auto="1" extension_auto="1" />
                    <Option object_output="obj/Debug/" />
                    <Option type="1" />
                    <Option compiler="gcc" />
                    <Compiler>
                        <Add option="-g" />
                    </Compiler>
                </Target>
                <Target title="Release">
                    <Option output="bin/Release/multithread" prefix_auto="1" extension_auto="1" />
                    <Option object_output="obj/Release/" />
                    <Option type="1" />
                    <Option compiler="gcc" />
                    <Compiler>
                        <Add option="-O2" />
                    </Compiler>
                    <Linker>
                        <Add option="-s" />
                    </Linker>
                </Target>
            </Build>
            <Compiler>
                <Add option="-Wall" />
            </Compiler>
            <Unit filename="main.c">
                <Option compilerVar="CC" />
            </Unit>
            <Extensions>
                <code_completion />
                <envvars />
                <debugger />
                <lib_finder disable_auto="1" />
            </Extensions>
        </Project>
    </CodeBlocks_project_file>


GCC 编译命令与链接命令使用，加 `-shared` 链接选项生成动态链接库：

    >gcc -c -o add_basic.o add_basic.c
    >gcc -o add_basic.dll -s -shared add_basic.o -Wl,--subsystem,windows

以上分步演示了编译和链接两个过程，但是 GCC 可以一步执行：

    gcc -o add_basic.dll -s -shared add_basic.c -Wl,--subsystem,windows



## GCC Warning

❌ warning: no return statement in function returning non-void [-Wreturn-type]

一个函数需要返回一个 non-void 数据，但没有返回语句，可以 `return NULL;`。

❌ warning: 'xxx' is deprecated [-Wdeprecated-declarations]

使用了过时的符号定义，更正使用最新的替代符号。



## GCC Error

❌ error: 'xxx' was not declared in this scope

常见原因，名称写错，或是没有给编译器指定引用的导入库，又或者导入库的版本不对导致链接程序找不到符号定义。


❌ undefined reference to `xxx`

找不到引用符号的定义，链接程序没有大指定的链接库中找到对应符号，可能是导入库文件没在给链接程序指定。如果确实已经指定导入库文件，那需要确实，依赖使用的动态链接库和导入库版本是不一致，要确保编译器一致和编译的架构一致，尽量版本号也一致。

提示一下，像 VCpkg 会自动查找依赖的库，像本系统一样，编译 libpng 进出现 zlib 库的各种函数无定义：

    undefined reference to `deflateEnd'
    undefined reference to `crc32'

这是因为编译依赖库时找到的 zlib 是来自 Anaconda 中安装的库文件，而在自己编写的程序中引用的是另一个版本的库，前后不一致而导致找不到符号：

    C:/Anaconda3/Library/include
    C:/Anaconda3/Library/lib/z.lib

这里的问题就很隐秘，因为自己的程序中使用的 libpng 是使用 Anaconda 中的 zlib 编译的，而在编译程序时使用了另一个 zlib 版本，这就是版本不一致导致的引用未定义符号。



# Makefile 自动化编译
- http://www.ruanyifeng.com/blog/2015/02/make.html
- https://www.gnu.org/software/make/manual/make.html
- http://erlang.org/doc/man/make.html#emakefile
- Programming Erlang 2nd - 10.3 Automating Compilation with Makefiles


Make 是最常用的构建工具，诞生于 1977 年，主要用于 C 语言的项目。但是实际上 ，任何只要某个文件有变化，就要重新构建的项目，都可以用 Make 构建。

Erlang 命令本身也实现了 Emakefile 的功能，执行编译 `erl -make` 相当执行 `make:all()`，编译后的字节文件会保存到 `ebin` 目录，执行时使用 `erl -pa ebin` 就可以自动加载字节码。erl -make 也兼容 GNU make。

Emakefile 规则定义语法：

    Modules.
    {Modules,Options}.    

其中 Modules 是原子类型，可以是以下：

- 一个模块名，如 file1，又或者在其它目录中 `../foo/file1`
- 一组模块，通过熊通配符号指定，如 `'file*'`
- 全通配，当前目录下的所有模块 `'*'`
- 由以上项目任意组合的列表，比如 `['file*','../foo/file3','File4']`

选项 Options 指定了编译选项，Emakefile 文件是从上到下读取的，如果多条匹配设置出现，开头的一条生效。如下 `'file1'` 模块的编译选项是 `[debug_info,{i,"../foo"}]`，它指定了编译输出调试信息，如以下 Emakefile 文件：

    {'src/*', [debug_info,
               {i, "src"},
               {i, "include"},
               {outdir, "ebin"}]}.

    {'file1',[debug_info,{i,"../foo"}]}.
    {'*',[debug_info]}.    


GNU 的 Make 工具可以替代手工的编译工作，通过 Makefile 脚本实现工程级别的编译工作自动化。

列如，以下一个 Makefile：

    .SUFFIXES: .erl .beam
     
    .erl.beam:
        erlc -W $<
    ERL = erl -boot start_clean 
     
    MODS = hello shop
    
    all: compile 
     
    compile: ${MODS:%=%.beam}
        @echo "make clean - clean up"
     
    clean:  
        rm -rf *.beam erl_crash.dump 

保存到源代码 hello.erl、shop.erl 同一文件夹下，执行 `erl -make`，编译成功就会出现源代码对应的 .beam。

在 Windows 系统使用 Gnu make 命令，需要 ComSpec 这个环境变量指向 cmd.exe，或者设置 `SHELL=cmd.exe` 否则 shell 会执行失败：

    process_begin: CreateProcess(NULL,gcc -c test.c, ...)failed. 
    make(e=2): 系统找不到指定的文件 
    make:*** [test.o] 错误2 

列如，Erlang 源代码中提供了 wxErlang 模块的示例，其编译脚本 otp_src_23.0\lib\wx\examples\demo\Makefile 是为 Linux 系统准备的，在 Windows 系统上使用需要修改一下；

    SHELL=cmd.exe

    ERL_TOP = ..\..\..\..
    TOPDIR   = ..\..
    SRC = .
    BIN = .
    ERLINC = $(TOPDIR)/include
    ERLC = erlc
    TESTMODS = \
        demo \
        demo_html_tagger \
        ...
        ex_graphicsContext

    TESTTARGETS = $(TESTMODS:%=%.beam)
    TESTSRC = $(TESTMODS:%=%.erl)

    # Targets
    $(TESTTARGETS):$(TESTSRC)
    opt debug:  $(TESTTARGETS)
        ERLC -o $(TOPDIR)/ebin  $(TESTSRC)
    clean:
        del $(TOPDIR)\ebin\*.beam
        del "$(TOPDIR)\ebin\erl_crash.dump"
    #   del $(TESTTARGETS:%="$(TOPDIR)/ebin/%")
    #   rm -f $(TESTTARGETS)
    #   rm -f *~ core erl_crash.dump

    # docs:

    run: opt
        erl -smp -detached -pa $(TOPDIR)\ebin -s demo

然后执行编译，运行测试：

    $ make
    $ erl -noshell -s demo start -s init stop

make 命令只是一个根据指定的 Shell 命令进行构建的工具，它的规则很简单：

- Target 规定要构建哪个文件，用什么命令；
- Dependence 它依赖哪些源文件；
- Update 当那些文件有变动时，如何重新构建它。

构建规则都写在 Makefile 文件里面，这个文件由一系列规则 rules 构成：

    <target> : <prerequisites> 
    [tab]  <commands>

- 第一行冒号前面的部分，叫做`目标` Target，多目标用空格隔开，冒号后面的部分叫做`前置条件` prerequisites。
- 第二行必须由一个 tab 键起首，后面跟着`命令` commands。
- 目标是必需的，不可省略，前置条件和命令都是可选的，但是两者之中必须至少存在一个。
- 每条规则就明确两件事：构建目标的前置条件是什么，以及如何构建。

目标通常是文件名，指明 Make 命令所要构建的对象，除了文件名，目标还可以是某个操作的名字，这称为`伪目标` phony target。

在定义目标时，如果当前目录中，正好有一个文件同名，比如，目标叫做 `clean`，Make 执行时发现 clean 文件已经存在，而且是最新的状态，就认为没有必要重新构建了，就不会执行指定的命令。为了避免这种情况，可以明确声明 clean 是伪目标，写法如下：

    .PHONY: clean
    clean:
            rm *.o temp

声明 clean 是伪目标之后，make 就不会去检查是否存在一个叫做 clean 的文件，而是每次运行都执行对应的命令。像 `.PHONY` 这样的内置目标名还有不少，伪目标以句点开头跟大写字母，可以查看手册。

前置条件通常是一组文件名，之间用空格分隔。它指定了目标是否重新构建的判断标准： 只要有一个`前置文件`不存在，或者有过更新，前置文件的 last-modification 时间戳比`目标`的时间戳新，目标就需要重新构建。

命令 commands 表示如何更新目标文件，由一行或多行的 Shell 命令组成。它是构建目标的具体指令，它的运行结果通常就是生成目标文件。

Make 有`隐含规则` implict rule，比如：

    foo : foo.o bar.o
            cc -o foo foo.o bar.o $(CFLAGS) $(LDFLAGS)

上面的规则中，没有定义 foo.o 目标，make 会自动使用隐含规则，选检查 foo.o 文件是不存在，然后检查目录下对应的源代码，比如 foo.c 文件就会执行 C 编译器，如果是 foo.p 文件则执行 Pascal 编译器，如此。

隐含规则和隐含变量是配套的，C compiler，对应的隐含变量就是 cc 命令，可以直接调用，$(CC)、$(CFLAGS)、$(CPPFLAGS) 等。


Make 的一些编程能力：

- Make 支持命令换行，在换行符前加反斜杠 `\` 转义，$$ 表示转义 $ 符号。
- 井号 # 在 Makefile 中表示其后面的内容是注释。
- 支持 `*`、`?`、`[...]`  通配符用来指定一组符合条件的文件名。
- 支持匹配符，`%`，如 `%.o: %.c` 为当前目录下源码文件定义相应的目标。
- 支持变量，如 `v1 = Hi!` 定义了 v1 变量，`${v1}` 或 `$(v1)` 使用变量，例如 `@echo $(v1)`，或者 `v2 = $(v1)`。
- 支持 shell 命令，如 `contents := $(shell cat foo)`。
- 变量高级引用，`$(var:a=b)` 或者 `${var:a=b}`，例如以下 bar 变量最后的值是 `a.c b.c l.a c.c`：

        foo := a.o b.o l.a c.o
        bar := $(foo:.o=.c)

- 内置变量，如`$(CC)` 指向当前使用的编译器，`$(MAKE)` 指向当前使用的 Make 工具。
- 自动变量：

    - `$@` 指代当前 Make 命令当前构建的那个目标。
    - `$<` 指代第一个前置条件。
    - `$?` 指代比目标更新的所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，其中 p2 的时间戳比 t 新，$? 就指代 p2。
    - `$^` 指代所有前置条件，之间以空格分隔。
    - `$*` 指代匹配符 % 匹配的部分， 比如 % 匹配 f1.txt 中的 f1，$* 就表示 f1。
    - `$(@D)` 和 `$(@F)` 分别指向 $@ 自动变量的目录名和文件名部分。
    - `$(<D)` 和 `$(<F)` 分别指向 $< 自动变量的目录名和文件名部分。

- 支持 if-else 条件判断结构：

        ifeq ($(CC),gcc)
            libs=$(libs_for_gcc)
        else
            libs=$(normal_libs)
        endif

- 支持循环结构：

        LIST = one two three

        all:
            for i in $(LIST); do \
                echo $$i; \
            done

        # 等同于

        all:
            for i in one two three; do \
                echo $i; \
            done

- 支持使用函数：

        $(function arguments)
        # 或者
        ${function arguments}

Makefile 提供了许多内置函数，可供调用。下面是几个常用的内置函数。

Text Functions

| 格式        | 示范        |
| :-------  | :-------  |
| $(subst from,to,text) | $(subst ee,EE,feet on the street) |
| $(lastword names…)    | $(lastword foo bar) |
| $(patsubst pattern,replacement,text)  | $(patsubst %.c,%.o,x.c.c bar.c) |
| $(strip string)   | $(strip a b c ) |
| $(findstring find,in) | $(findstring a,a b c) |
| $(filter pattern…,text)   | $(filter %.c %.s,$(sources)) |
| $(sort list)  | $(sort foo bar lose) |
| $(word n,text)    | $(word 2, foo bar baz) |
| $(wordlist s,e,text)  | $(wordlist 2, 3, foo bar baz) |

File Name Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(dir names…) | $(dir src/foo.c hacks)    |
| $(notdir names…)  | $(notdir src/foo.c hacks) |
| $(suffix names…)  | $(suffix src/foo.c src-1.0/bar.c hacks)   |
| $(basename names…)    | $(basename src/foo.c src-1.0/bar hacks)   |
| $(addsuffix suffix,names…)    | $(addsuffix .c,foo bar)   |
| $(addprefix prefix,names…)    | $(addprefix src/,foo bar) |
| $(join list1,list2)   | $(join a b,.c .o) |
| $(wildcard pattern)   |   |
| $(realpath names…)    |   |
| $(abspath names…) |   |

Conditional Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(if condition,then-part[,else-part]) |   |
| $(or condition1[,condition2[,condition3…]])   |   |
| $(and condition1[,condition2[,condition3…]])  |   |

Make Control Functions

| 格式        | 示范    |
| :-------  | :-------  |
| $(error text…)    | $(error error is $(ERROR1))   |
| $(info text…) |   |
| $(warning text…)  |   |

其它函数 

| 函数        | 格式        | 作用    |
| :-------  | :-------  | :-------  |
| Foreach Function  | $(foreach var,list,text)  | Repeat some text with controlled variation. |
| File Function     | $(file op filename[,text])    | Write text to a file. |
| Call Function     | $(call variable,param,param,…)    | Expand a user-defined function. |
| Value Function    | $(value variable) | Return the un-expanded value of a variable. |
| Eval Function     | $(eval $(call PROGRAM_template,$(prog))   | Evaluate the arguments as makefile syntax. |
| Origin Function   | $(origin variable)    | Find where a variable got its value. |
| Flavor Function   | $(flavor variable)    | Find out the flavor of a variable. |
| Shell Function    | $(shell echo *.c) | Substitute the output of a shell command. |
| Guile Function    |   | Use GNU Guile embedded scripting language. |


脚本模板 Makefile.template：

    # leave these lines alone
    .SUFFIXES: .erl .beam .yrl

    .erl.beam:
        erlc -W $<

    .yrl.erl:
        erlc -W $<

    ERL = erl -boot start_clean

    # Here's a list of the erlang modules you want compiling
    # If the modules don't fit onto one line add a \ character
    # to the end of the line and continue on the next line
    # Edit the lines below
    
    MODS = module1 module2 \
        module3 ... special1 \
        ...
        moduleN
    
    # The first target in any makefile is the default target.
    # If you just type "make" then "make all" is assumed (because
    # "all" is the first target in this makefile)

    all: compile

    compile: ${MODS:%=%.beam} subdirs

    ## special compilation requirements are added here

    special1.beam: special1.erl
        ${ERL} -Dflag1 -W0 special1.erl

    ## run an application from the makefile

    application1: compile
        ${ERL} -pa Dir1 -s application1 start Arg1 Arg2

    # the subdirs target compiles any code in sub-directories

    subdirs:
        cd dir1; $(MAKE)
        cd dir2; $(MAKE)
        ...

    # remove all the code

    clean:
        rm -rf *.beam erl_crash.dump
        cd dir1; $(MAKE) clean
        cd dir2; $(MAKE) clean

最重要的是：

    MODS = module1 module2 module3 ... special1 ...

它定义了需要编译的目标模块，然后使用 `${MODS:%=%.beam}` 转换成 beam 扩展名，执行 make 可以指定编译的目标：

    make [Target]

就会将模块编译生成脚本定义目标文件。


# Ninja 快速构建工具
- [Ninja - a speedy and small build system](https://ninja-build.org/)
- [The Ninja build system v1.10.0](https://ninja-build.org/manual.html)

Ninja 是 Chrome 项目的构建工具，用来替换经典工具 make，目前这个开源工具已经被很多其它项目采用。据项目作者描述，创建这个新的构建工具，主要是为了提升大型项目的编译速度。

由于 Ninja 的设计目标之一是“必须易于嵌入大型构建系统”，所以，像写 Makfile 那样手写规则文件，并不是它的目标； Ninja 的项目作者说，Ninja 构建文件使用的语言“简单到了不便于人类书写”的程度。Ninja 的规则文件中，并没有条件语句或是基于文件后缀的规则，相反，有的仅仅是一个个列表。这些列表记录了确切的输入文件路径，以及所产生的确切结果。因为这种简单的表达并不需要额外的解释，所以，在运行时，这些规则文件能够被快速载入。 

Ninja 规则脚本默认名称 build.ninja，简单到只需要三个基本概念：

- Variables 变量设置
- Rules 规则设置
- Build 构建设置

假设有一个 demo.cpp 程序要编译，以下示范 Ninja 的脚本编写：

    # Version required
    ninja_required_version = 1.5

    # build output
    builddir = bin

    # variables
    GCC = C:\MinGW\bin\g++.exe
    cflags = -Wall

    # compile rules depfile ---> ninja_deps files
    rule compile_demo
      command = $GCC -c $cflags -MD -MF $out.d $in -o $out
      description = Compiling $in for $out
      depfile = $out.d
      deps = gcc

    # link rules
    rule link_demo
      command = $GCC $DEFINES $INCLUDES $cflags $in -o $out
      description = Linking $in for $out

    # build
    build demo.o : compile_demo src/demo.cpp
    build demo.exe : link_demo demo.o
    build all: phony demo.exe

    default all

其中 phony 是一条特殊的规则，用来创建目标别名：

    build foo: phony some/file/in/a/faraway/subdir/foo

规则中，只有 command 变量是必须的，这指定要运行的命令。

在 Ninja 1.3 引入 deps 规则变量，它可以指定 gcc 或 msvc 依赖文件处理方式。

Ninja 处理三类的依赖：

- Explicit dependencies 显式依赖，在 build 规则罗列的依赖文件，包括 $in 变量，改变显式依赖文件就会导致重新构建。
- Implicit dependencies 隐式依赖，在 build 规则后面 `| dep1 dep2` 指定，或者从 depfile 文件解释得到的依赖。
- Order-only dependencies 顺序依赖，在 build 规则后面 `|| dep1 dep2 ` 指定，会依据日期状态重新构建。

为了正确构建 C/C++ 代码，一个构建系统必需能感知头文件间的依赖。假定 foo.c 包含一行 #inclue “foo.h” 。而 foo.h 自身又包含一行 #include “bar.h”。所有的三个文件都会影响后续编译，例如，bar.h 的改变也会触发 foo.o 的重新构建。

一些构建系统使用一个“头文件扫描器”在构建时提取这部分依赖信息。但这个方法太慢，而且很难精确处理有 #ifdef 指令出现的情形。另一种选择是要求构建文件正确地报告所有依赖，包括头文件的依赖，但这对开发人员来说十分笨重：每次你添加或删除 #include 语句时，都需要修改或重新生成构建文件。

一个有用的方法依赖于这样的事实：在编译时，GCC 以及 MSVC 可以给出在构建输出时用到了哪些头文件。这份信息文件，如同用于生成输出的信息，可以被构建系统记录和加载，由此，依赖可以被精确追踪。在第一次编译时，因为还未有输出，所有文件都会被编译，故不需头文件依赖。第一次编译后，对于被某个输出用到的任何文件如果发生更改包括增加或删除额外的依赖，就会导致重新构建，这保证了依赖信息的更新。

在编译时，gcc 以 Makefile 的格式记下头文件依赖。Ninja 包括一个解析器处理 depfile 指定的这一 Makefile 语法文件，只是 Makefile 简化子集，并在下一次构建时载入这份依赖信息。

Ninja 文件由记录的序列组成，而记录要么是一个路径，要么是一个依赖列表。每个写入文件的路径都被赋于了一个整数序列号，故而依赖就是一列整数。为了向文件添加依赖，Ninja 首先记录下还没有序列号的路径，然后用这些序列号记录依赖。在后续的构建载入这一文件时，Ninja 可以简单地使用一个数组将序列号映射到对应的 Node 指针。


安装 Ninja ：

- Ninja binary https://github.com/ninja-build/ninja/releases
- build from source:

        $ git clone git://github.com/ninja-build/ninja.git && cd ninja
        $ git checkout release
        $ cat README

环境变量 NINJA_STATUS 可以控制 ninja 打印进度状态的样式，有几个占位符：

| 占位符号    | 说明                                             |
| ----------: | :----------------------------------------------- |
|          %s | 起始 edges 的数量。                              |
|          %t | 完成构建必须运行的 edges 总数。                  |
|          %p | 起始 edges 的百分比。                            |
|          %r | 当前运行的 edges 数。                            |
|          %u | 要开始的剩余 edges 数。                          |
|          %f | 完成的 edges 数。                                |
|          %o | 每秒完成 edges 数                                |
|          %c | 当前每秒完成 edges 数，由 -j 指定构建的平均值    |
|          %e | 经过的时间，以秒为单位。自 Ninja 1.2 起可用。    |
|          %% | 一个普通的 % 字符。                              |

默认进度状态为 "[%f/%t] " 请注意尾随空格以与构建规则分开。可能的进度状态的另一个示例可能是 "[%u/%r/%f] "。
尝试改为

    export NINJA_STATUS="[%p/%f/%t %e] "（Windows下set NINJA_STATUS="[%p/%f/%t %e] "）


规则文件一般是通过 cmake/gn 来生成 ninja 的配置，再进行编译：

    # 示例
    cmake . -G "Ninja" 
    cmake . -G "CodeBlocks - Ninja"
    cmake . -G "Sublime Text 2 - Ninja"
    ninja 



# VCpkg 开源库管理工具
- [Manage C and C++ libraries on Windows](https://github.com/Microsoft/vcpkg/)
- [Tips for VCpkg](https://vvingerfly.github.io/2018/05-08-Tips4vcpkg/)

Windows 下开发 C/C++ 程序，少不了编译开源的第三方库。比如用于网络连接的高性能库 libcurl、用于压缩解压的 zlib 等等。使用这些库开发极大的方便了程序员，使得我们不必重复造轮子。由于这些开源库绝大部分都来源于 Linux 系统，其工程文件、编译系统都使用 gnu 系列工具，使得将其移植到 Windows 的 VC 开发环境下一直是难点。

还需要考虑预先编译出哪种类型的开源库程序，比如：Debug 还是 Release、动态库还是静态库、MD 还是 MT、32 位还是 64 位。光是这三种组合就有 16 种可能性。如果像 libcurl 这种还要考虑是否引用其他开源库的功能，那么编译类型的组合会更多。

VCpkg 就是解决这个问题的：

- 自动调用 git 等工具下载开源库源代码；
- 源码包的缓存管理和版本管理，可以升级版本；
- 紧密结合 CMake 轻松编译；
- 依赖关系检查，比如编译 libcurl，会自动下载 zlib、openssl 进行编译；
- 无缝集成 Visual Studio，不需要设置库文件、头文件的所在目录，自动集成。
- Visual Studio 全平台支持，支持 Debug/Release、x86/x64 编译，还支持 UWP、ARM 平台的编译。

一般使用流程：

- 执行 vcpkg 安装模块，等待编译动作完成；
- 执行 vcpkg integrate 集成到项目或者 Visual Studio，又或者全局集成；
- 在代码中通过头文件使用安装好的模块；


vcpkg 主目录文件夹结构：

| buildtrees | 所有下载好的 library 源代码和构建目录         |
| docs       | 文档与示例                                    |
| downloads  | 下载缓冲文件夹，执行安装命令时会先查询这里    |
| installed  | 编译好 library 后安装头文件和编译生成的文件   |
| packages   | 内部文件夹，在工程安装依赖时用到              |
| ports      | 包含分类中的库描述文件，包含版本、下载地址等  |
| scripts    | 脚本目录，如 cmake, powershell 脚本           |
| toolsrc    | VcPkg C++ 源代码和组件                        |
| triplets   | 包含支持架构配置文件，如 x86-windows、x64-uwp |

  
vcpkg 安装依赖模块的基本执行流程：

- 环境初始化
- 下载源代码，如果已经在 cache 中，则跳过下载环节
- 校验文件有效性
- 解压缩源代码
- 利用配套工具配置源码工程，如 cmake，如果是 ffmpeg 则用 msys2
- 执行 MSBuild 编译源码，一般会同时编译 Release 和 Debug 版本。
- 把编译好的文件拷贝到相关目录中去，一般是 installed 目录

如果没有在 vcpkg 主目录运行，可能会遇到 Error: Could not detect vcpkg-root。


使用 PowerShell 执行 Vcpkg 工程目录下的 bootstrap-vcpkg.bat 进行编译，会在同级目录下生成 vcpkg.exe 文件。

命令使用示范：

    >vcpkg --help
    Commands:
      vcpkg search [pat]              Search for packages available to be built
      vcpkg install <pkg>...          Install a package
      vcpkg remove <pkg>...           Uninstall a package
      vcpkg remove --outdated         Uninstall all out-of-date packages
      vcpkg list                      List installed packages
      vcpkg update                    Display list of packages for updating
      vcpkg upgrade                   Rebuild all outdated packages
      vcpkg x-history <pkg>           (Experimental) Shows the history of CONTROL versions of a package
      vcpkg hash <file> [alg]         Hash a file by specific algorithm, default SHA512
      vcpkg help topics               Display the list of help topics
      vcpkg help <topic>              Display help for a specific topic

      vcpkg integrate install         Make installed packages available user-wide. Requires admin
                                      privileges on first use
      vcpkg integrate remove          Remove user-wide integration
      vcpkg integrate project         Generate a referencing nuget package for individual VS project use
      vcpkg integrate powershell      Enable PowerShell tab-completion

      vcpkg export <pkg>... [opt]...  Exports a package
      vcpkg edit <pkg>                Open up a port for editing (uses %EDITOR%, default 'code')
      vcpkg import <pkg>              Import a pre-built library
      vcpkg create <pkg> <url> [archivename]
                                      Create a new package
      vcpkg owns <pat>                Search for files in installed packages
      vcpkg depend-info <pkg>...      Display a list of dependencies for packages
      vcpkg env                       Creates a clean shell environment for development or compiling
      vcpkg version                   Display version information
      vcpkg contact                   Display contact information to send feedback
      ...

    >vcpkg search assimp
    >vcpkg search | findstr assimp
    assimp               5.0.1            The Open Asset import library
    magnum-plugins[assimpimporter]        AssimpImporter plugin

    >vcpkg search | findstr glu
    aws-sdk-cpp[glue]                     C++ SDK for the AWS glue service
    freeglut             3.2.1-4          Open source implementation of GLUT with source and binary backwards compatibil...
    glui                 2019-11-30       GLUI is a GLUT-based C++ user interface library
    mathgl[glut]                          glut module

    >vcpkg install assimp:
    Computing installation plan...
    The following packages will be built and installed:
        assimp[core]:x86-windows
      * minizip[core]:x86-windows
      * rapidjson[core]:x86-windows
      * zlib[core]:x86-windows
    Additional packages (*) will be modified to complete this operation.
    Warning: The following VS instances are excluded because the English language pack is unavailable.
        C:\Program Files (x86)\Microsoft Visual Studio\2019\Community
    Please install the English language pack.

安装具有 Cuda 加速的 opencv 库：

    vcpkg search opencv
    vcpkg install opencv[cuda]:x64-windows 
    vcpkg --triplet x64-windows install opencv[cuda]

支持的架构组合查询：

    >vcpkg help triplet

| VCPKG built-in triplets | VCPKG community triplets |
|-------------------------|--------------------------|
| arm-uwp                 | arm-ios                  |
| arm64-windows           | arm-mingw                |
| x64-linux               | arm-windows              |
| x64-osx                 | arm64-ios                |
| x64-uwp                 | arm64-mingw              |
| x64-windows-static      | arm64-uwp                |
| x64-windows             | arm64-windows-static     |
| x86-windows             | wasm32-emscripten        |
|                         | x64-ios                  |
|                         | x64-mingw                |
|                         | x64-osx-dynamic          |
|                         | x64-windows-static-md    |
|                         | x86-ios                  |
|                         | x86-mingw                |
|                         | x86-uwp                  |
|                         | x86-windows-static-md    |
|                         | x86-windows-static       |


作为 MinGW 的用户，我非愿意看到 triplet 列表中有 x64-mingw 和 x86-mingw 的身影。

可以设置默认的架构：

    VCPKG_DEFAULT_TRIPLET=x64-windows

vcpkg 的 Triplet files 是用来记录和库相关的 OS、CPU、Compiler、Runtime 等信息的文件，它包含了编译模块时使用的工具链。

安装第三方的 MinGW 架构依赖库时出现错误：

    >vcpkg install assimp:x64-mingw
    Computing installation plan...
    The following packages will be built and installed:
        assimp[core]:x64-mingw
      * minizip[core]:x64-mingw
      * rapidjson[core]:x64-mingw
      * zlib[core]:x64-mingw
    Additional packages (*) will be modified to complete this operation.
    Unable to determine toolchain to use for triplet x64-mingw with CMAKE_SYSTEM_NAME MinGW

提示信息表明，vcpkg 无法从 CMAKE_SYSTEM_NAME 指定的 x64-mingw 架构确定需要用到的工具链：

    triplets/community/x64-mingw.cmake

这个问题有点恶心，因为 vcpkg 的源代码忽略了 MinGW，解决方法是修改 build.cpp 重新编译 vcpkg：

    diff --git a/toolsrc/src/vcpkg/build.cpp b/toolsrc/src/vcpkg/build.cpp
    index c61c6b7..d7c78aa 100644
    --- a/toolsrc/src/vcpkg/build.cpp
    +++ b/toolsrc/src/vcpkg/build.cpp
    @@ -558,6 +558,10 @@ namespace vcpkg::Build
             else if (cmake_system_name == "Android")
             {
                 return m_paths.scripts / fs::u8path("toolchains/android.cmake");
    +        }
    +        else if (cmake_system_name == "MinGW")
    +        {
    +            return m_paths.scripts / fs::u8path("toolchains/mingw.cmake");
             }
             else if (cmake_system_name.empty() || cmake_system_name == "Windows" || cmake_system_name == "WindowsStore")
             {
    --

参考 https://github.com/microsoft/vcpkg/issues/12065


安装好依赖模块后，接着是将 vcpkg 集成到项目或进行全局集成：

    >vcpkg integrate install
    Applied user-wide integration for this vcpkg root.

    All MSBuild C++ projects can now #include any installed libraries.
    Linking will be handled automatically.
    Installing new libraries will make them instantly available.

    CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

使用 CMake 的编译项目中使用 vcpkg 安装的库，最佳方式指定 CMake (Toolchain File) 工具链文件 `scripts/buildsystems/vcpkg.cmake`，让 `find_package()` 命令发现安装的库。

要使用这个文件，通过命令参数传入 CMake 即可：

    cmake .. -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake (Linux/MacOS)
    cmake .. -DCMAKE_TOOLCHAIN_FILE=vcpkg\scripts\buildsystems\vcpkg.cmake (Windows)

再比如，如果要用 VS2017 编译器，输入下面命令即可：

    cmake .. -DCMAKE_TOOLCHAIN_FILE=D:\vcpkg\scripts\buildsystems\vcpkg.cmake -G "Visual Studio 15 2017 Win64"

还有一种方法，直接在 CMakeLists.txt 文件中指定 `CMAKE_TOOLCHAIN_FILE` 变量，即：

    set(CMAKE_TOOLCHAIN_FILE "D:\vcpkg\scripts\buildsystems\vcpkg.cmake")
    project(PROJECT_NAME)

注意，要在 `project()` 命令之前设置。另外，类似 `CMAKE_SYSTEM_NAME`,`CMAKE_C_COMPILER` 等这些变量都要在 `project()`命令之前设定，不然 CMake 会按照默认的设置处理。

如果电脑中没有安装 cmake，vcpkg 会自动下载 cmake portable 版本。


集成安装：

|            命令            |               说明              |
|----------------------------|---------------------------------|
| vcpkg integrate install    | 为所有用户集成安装依赖包        |
| vcpkg integrate remove     | 为所有用户移除集成安装          |
| vcpkg integrate project    | 为独立 VS 项目创建 nuget 包引用 |
| vcpkg integrate powershell | 为 PowerShell Tab 自动完成集成  |
|----------------------------|---------------------------------|


依赖包的管理：

    vcpkg.exe remove assimp
    vcpkg.exe remove --outdated
    vcpkg.exe list
    vcpkg.exe export assimp --7zip

导出时必须指定导出的包格式。vcpkg支持5种导出包格式，有：

| 参数        | 格式                     |
| :---------- | ------------------------ |
| –raw        | 以不打包的目录格式导出   |
| –nuget      | 以 nuget 包形式导出      |
| –ifw        | 基于 IFW 的安装包        |
| –zip        | 以 zip 压缩包形式导出    |
| –7zip       | 以 7z 压缩包形式导出     |

最后，提示一下，VCpkg 会自动查找依赖的库，像本系统一样，编译 libpng 进出现 zlib 库的各种函数无定义：

    undefined reference to `deflateEnd'
    undefined reference to `crc32'

这是因为编译依赖库时找到的 zlib 是来自 Anaconda 中安装的库文件，而在自己编写的程序中引用的是另一个版本的库，前后不一致而导致找不到符号：

    C:/Anaconda3/Library/include
    C:/Anaconda3/Library/lib/z.lib
