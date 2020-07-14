# Demo

Demo 这个仓库原本是坚果用来学 Git 版本管理用的，随着演示项目的增加，觉得有需要通过分支的方式来管理各个演示 DEMO，所以原来的 demo 仓库的 master 只是作为文档来使用，而各个分支则作为演示项目来推进：

	git clone https://github.com/jimboyeah/demo.git

演示项目列表：

- .NetCore Web 服务开发

    https://github.com/jimboyeah/demo/tree/DotNetCoreWebw

		git clone -b DotNetCoreWebw https://github.com/jimboyeah/demo.git

- Xarmarin 跨平台开发

    https://github.com/jimboyeah/demo/tree/XamarinVS2019

        git clone -b XamarinVS2019 https://github.com/jimboyeah/demo.git

- OpenGL & OpenCV 进行中

    https://github.com/jimboyeah/demo/tree/OpenGL_demos

        git clone -b OpenGL_demos https://github.com/jimboyeah/demo.git

    OpenGL 红宝书例程讲解在此仓库：

    https://github.com/jimboyeah/The-OpenGL-Redbook-Samples-MinGW.git

- DLL with MinGW

    https://github.com/jimboyeah/demo/tree/dllDemo

    此项目演示如何使用 MinGW 编译器来构建 DLL 动态链接库，使用 CMake 构建工具。

        git clone -b dllDemo https://github.com/jimboyeah/demo.git

- CPP with MinGW

    https://github.com/jimboyeah/demo/tree/cppDemos

    此项目演示如何使用 CMake 自动编译和 MinGW 编译器来编写 C++ 程序。

        git clone -b cppDemos https://github.com/jimboyeah/demo.git

    以下网站可以下载 MinGW-x64 GCC 9.2.0：

    - [MinGW Distro](https://nuwen.net/mingw.html)

- 造轮子 Websocket 现在就 Go

    https://github.com/jimboyeah/demo/tree/go-my-websocket

        git clone -b go-my-websocket https://github.com/jimboyeah/demo.git


# GCC - GNU Compiler Collection
- [MinGW](http://www.mingw.org/)
- [GCC 参数详解](https://www.runoob.com/w3cnote/gcc-parameter-detail.html)
- [GCC 5 Release Series](https://gcc.gnu.org/gcc-5/)
- [GCC - the GNU Compiler Collection](https://gcc.gnu.org/)
- [mingw-w64 GCC for Windows 64 & 32 bits](http://mingw-w64.org/doku.php)
- [GCC Invocation](https://gcc.gnu.org/onlinedocs/gcc-5.5.0/cpp/Invocation.html)
- [C++ Standards Support in GCC](http://gcc.gnu.org/projects/cxx-status.html)
- [GCC 版本的发布](http://gcc.gnu.org/releases.html)
- [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support)
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


GCC 环境变量：

| 变量名       | 功能    |
| :-------  | :-------  |
| `CPATH`   | 搜索目录列表，也可以使用命令选项，如 -I. -I/special/include |
| `C_INCLUDE_PATH`  | 搜索目录列表，分隔符号由 PATH_SEPARATOR 变量指定，通常是分号或冒号 |
| `CPLUS_INCLUDE_PATH`  | 搜索目录列表 |
| `OBJC_INCLUDE_PATH`   | 搜索目录列表 |
| `DEPENDENCIES_OUTPUT` | 非系统依赖的输出，相当命令选项 -MM、-MT 和 -MF 结合 |
| `SUNPRO_DEPENDENCIES` | 类似 DEPENDENCIES_OUTPUT，除了系统头文件不被忽略，相当 -M 选项 |


GCC 命令的常用选项：

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


Microsoft Visual C++，版本对应 C++ 标准关系如下所示：

| VS 版本 | 编译器版本 | C++ 标准    |
| :-------  | :-------  | :-------  |
| Visual Studio 6    | vc6 | |
| Visual Studio 2003 | vc7 | |
| Visual Studio 2005 | vc8 | |
| Visual Studio 2008 | vc9 | |
| Visual Studio 2010 | vc10 | |
| Visual Studio 2012 | vc11 | C++11 基本支持 |
| Visual Studio 2013 | vc12 | C++11 基本支持，C++14 部分支持 |
| Visual Studio 2015 | vc14 | C++17 部分支持 |
| Visual Studio 2017 | vc15| C++14 完全支持，C++17 基本支持 |
| Visual Studio 2019 | vc16| C++14 完全支持，C++17 基本支持 |




# 造轮子 Websocket 现在就 Go
MD: 2019‎年‎12‎月17‎日，‏‎03:45:10
https://gitbook.cn/gitchat/activity/5df7ecb85d2ecb0a746047df


笔者坚果有幸从事软件开发，一直都是兴趣驱动的工作。第一次接触计算机是 1999 年后的事，我用来学习的电脑是大哥买来准备学 CAD 的 486 机，当时 CPU 还是威胜的 333MHz 主频，硬盘也只有 4GB，系统是 Windows 98 SE。那时所谓的学电脑纯属拆玩具模式，因为手上可用的资源不多，网络也不发达，也没有太丰富的参考资料，相关的图书也不是太丰富。所以翻查硬盘或系统光盘文件成了日常活动，除此之外，DOS 游戏也和红白机具有一样的可玩性。彼时，BAT 脚本和 Windows 系统光盘中 QBasic 脚本编程工具成了不错的好玩具。后来玩起了 Visual Studio 6.0，主要是 VB 和 VBA 脚本编程，C 语言也开始了解一些，C++ 几乎没有基础可言，所以 Visual C++ 一直玩不动 MFC 什么的更是不知云云。当然了，集成开发工具提供的最大的好处也就体现在这，即使你是个傻瓜也能毫不費力地运行配置好的模板程序，编译成完整的可运行程序。不知不觉，坚果从曾经的傻瓜程序员一路走到今天，没有兴趣带领还真不会有今天。

## 内容提要

这是我二进 GitChat 的创造，距离今年 ‎6 ‎月分‎第一次发布《从 JavaScript 入门到 Vue 组件实践》大谈前端技术全局观、30' JavaScript 入门课，还有 VSCode 和 Sublime 这些好用的开发工具。到如今已经有近半年时间，‎期间经历了较大的工作变动，技术上已经以脚本后端转到 Golang 为主，这是一种我一直期待的语言。期间也学到一些技术领域比较不容易学习到的知识，有项目管理层面的，有职业规划方面的，对知识付费时代也有了更深入的理解。

那么 Golang 作为一款以便利的并发编程的语言，用在后端的开发真的是不要太好。

Golang 虽然它已经有 10 岁大了，最早接触也是 2012 年左右，但是真正花心思学起来是今年的 7 月份。Golang 号称 21 世纪的 C 语言，这确实是对我最大的吸引力，它的特点可以总结为 C + OOP，以松散组合的方式去实现面向对象的编程思维。完全不像 C++ 把对象数据模型设计的异常复杂，把一种编程语言搞得自己发明人都不能完全掌握。当然每种语言都有它的适用领域及特点，免不了一堆人贬低 Golang 没有泛型之类，确实 Golang 1.x 就是没有提供实现。如日中天的 Python 就是个典型，作为奇慢的脚本解析型语言，慢这个缺点完全掩盖不了它中人工智能算法领域的应用，也完全阻挡不了爬虫一族赖以为生。这种取舍其实就是一种效益的体现，选择恰当的工具做适合的事！

我们将从网络协议层面来打开 Golang 编程大门，学习关于 Websocket 网络协议的相关知识点，在 TCP/IP 协议栈中，新加入的 Websocket 分量也是重量级的。WebSocket 作为实时性要求较高场合的应用协议，主要应用在在线网页聊天室、页游行业等等。掌握 Websocket 技能，你值得拥有！


在本轮学习中，你可以 Get 到技能：

- 如何拥有快速掌握一种计算机语言的能力；
- 入门 TCP/IP 协议森林；
- telnet 工具的使用；
- 理解几个基本网络概念：
	- Persistent connection 长连接；
	- Temporary connection 短连接；
	- Polling 轮询；
	- LongPolling 长轮询；
- Websocket 核心的数据帧 Data Framing 构造；
- Websocket 握手连接建立数据通讯过程；
- 实现一个 go-my-websocket 简约版 Websocket 服务器；
- 深入分解 Golang 的 Engine.io 及 Socket.io 的应用；
- 获得一份完整的电子版 PDF；
- 获得一份完整的 go-my-websocket 代码；
- 通过交流活动获得问题解答机会；


> 从任天堂红白机时代接触单片机，尽管那时不懂却被深深吸引了；从 MS-DOS 时代结缘计算机，就这样一路披荆斩棘前行；很多人说 IT 人是吃青春饭的，对于我，一个 80 后，在乳臭未干的时候就闻到这饭香了，到现在也没觉得吃够吃厌倦了。我只当这是个兴趣，现在这个爱好还能给我带来一份收入而已。
>
> by Jeangowhy 微信同名(jimboyeah◉gmail.com) 
> Tue Dec 17 2019 04:23:08 GMT+0800 (深圳宝安)

![gitchat](https://github.com/jimboyeah/demo/blob/go-my-websocket/go-my-websocket.jpg)
