# 仓库说明

此分支演示 CPP 程序，还有 CMake 自动编译，及 CMake Test 的使用。

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



# STL - Standard Template Library

STL - Standard Template Library 标准模板库，提供了通用的函数模板和类模板。

STL 有六大组件类型：

- 容器 Containers

    STL 容器是一种类模板 Class Template，主要分为`关联式容器` Associated containers 和`序列式容器` Sequence containers，存放各种数据结构，如 Vector，List，Deque，Set，Map。就体积而言，这一部分很像冰山载海面的比率。

- 算法 Algorithms

    各种常用算法，如Sort，Search，Copy，Erase。从实现的角度来看，STL 算法是一种函数模板 Function Templates。

- 迭代器 Iterators

    扮演容器与算法之间的胶合剂，是所谓的泛型指针，共有五种，以及其它衍生变化。从实现的角度来看，迭代器是一种将 `Operators*`, `Operator->`, `Operator++`, `Operator–` 等相关操作予以重载的 Class Template。所有 STL 容器都附带有自己专属的迭代器。是的，只有容器设计者才知道如何遍历自己的元素，原生指针 Native pointer 也是一种迭代器。

- 仿函数 Functors

    **行为类似函数，可作为算法的某种策略 Policy。**从实现的角度来看，仿函数是一种重载了 `Operator()` 的 Class 或 Class Template。一般函数指针可视为狭义的仿函数。

- 适配器 Adapters

    **一种用来修饰容器 Containers 或仿函数 Functors 或迭代器 Iterators 接口的东西，**例如：STL 提供的 Queue 和 Stack，虽然看似容器，其实只能算是一种容器配接器，因为它们的底部完全借助 Deque，所有操作由底层 Deque 供应。改变 Functor 接口者，称为 Function Adapter；改变 Container 接口者，称为 Container Adapter；改变 Iterator 接口者，称为 Iterator Adapter。配接器的实现技术很难一言蔽之，必须逐一分析。

- 分配器 Allocators

    负责空间配置与管理，从实现的角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的 Class Template。

C++ STL 中最基本以及最常用的类或容器 string、vector、set、list、map 等等。

顺序访问容器 Sequence containers 实现按顺序的访问容器元素，能快速插入新元素。

- `array` 模板类实现，(since C++11) static contiguous array
- `vector` 模板类实现，dynamic contiguous array
- `deque` 模板类实现，double-ended queue
- `forward_list` 模板类实现，(since C++11) singly-linked list
- `list` 模板类实现，doubly-linked list
 
关联容器 Associative containers 实现有序的数据结构，能实现快速查找，时间复杂度 (O(log n)。

- `set` collection of unique keys, sorted by keys
- `map` collection of key-value pairs, sorted by keys, keys are unique
- `multiset` collection of keys, sorted by keys
- `multimap` collection of key-value pairs, sorted by keys

(since C++11) 提供无序关联容器 Unordered associative containers 实现松散哈希 hashed 数据结构，实现快速查找，时间复杂度平均为常数 O(1)，最差为 O(n)。

- `unordered_set` collection of unique keys, hashed by keys
- `unordered_map` collection of key-value pairs, hashed by keys, keys are unique
- `unordered_multiset` collection of keys, hashed by keys
- `unordered_multimap` collection of key-value pairs, hashed by keys

容器适配 Container adaptors 
Container adaptors provide a different interface for sequential containers.

- `stack` adapts a container to provide stack (LIFO data structure)
- `queue` adapts a container to provide queue (FIFO data structure)
- `priority_queue` adapts a container to provide priority queue



## template 模板泛型
- https://www.runoob.com/cplusplus/cpp-templates.html
- [C++ 模板和 C# 泛型之间的区别](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/differences-between-cpp-templates-and-csharp-generics)

泛型编程 Generic 这个概念最早就是来源于 C++ 当初设计 STL 时所引入的模板 Template 概念，而为什么要引入模板呢，因为 STL 要完成这样一个目标：

设计一套通用的，不依赖类型的，高效的的算法和数据结构，例如 std::sort 和 std::list。

关于通用性，运行时多态 Polymorphism 可以做到，高级语言的继承 Inheritance 机制，接口 Interface 机制，但是 C++ 作为一门相对底层的语言，对运行效率的要求是很严格的，而运行时多态会影响效率。例如成员函数只有在运行时才知道调用哪个，所以设计 STL 的人就创造了一种编译时多态技术，即模板。

那什么又是编译时多态呢，简单点说就是让编译器帮我确定类型，我写程序时只要标记下这里我要用某种类型的对象，至于具体是什么类型我不关心，你编译器帮我确定，编译完成后在运行时绝对是类型确定的，这样就大大提高了运行效率，反之对编译就增加了很多工作，而且生成的目标代码也会大大增加。

所以对 C++ 来说，所谓泛型 Generics，并不是说编译器不知道类型，而是针对程序员来说的，这也正是通用性的体现。C++ 的模板在刚出来的时候并没有想到会演化成今天这样，其他高级语言，如 Java，C# 在使用的时候带给了程序员极大的便利，就考虑支持这样一种功能，但是也仅仅是借用了 C++ 的模板理念，而没有完全照抄模板的实现方法，所以对于大部分程序员来说，只要使用起来差不多，并不关心实现。

所以最后总结下，泛型是只是一个概念，具体实现有 C++ 的模板，Java 的泛型等，但实现方法大不相同，只是提供给语言使用者相同的使用方法而已。

C++ 模板与 Java 泛型的比较：

- C++ template 是 reified generic，Java generic 是 type erasure。
- C++ 是在 call site 做 instantiate type，Java 是在 call site 插入 cast。
- C++ template 在 call site 可以做 inline，Java generic 因为并没有在 call site 生成代码所以不行。
- C++ 在 runtime 没有额外的开销，Java 在 runtime 有 cast 的开销。
- C++ 的每个 reified generic type 都有一份独立的代码，Java 只有一份 type erased 之后的代码。
- C++ 的 type check 在编译时完成，Java 的 type check 在编译期和运行期都要做一些工作。

总的来说 C++ 的 template 会生成更大的二进制代码，但会执行的比较快，但大个的二进制代码可能会导致更多的 I/O，所以也不一定完全是优势。Java 生成的代码只有一份，运行时会有一些 type cast 开销，但可以在运行时支持新类型，比如用 ClassLoader 动态加载进来的类。

C++ 模板和 C# 泛型之间的主要差异：

- C# 泛型的灵活性与 C++ 模板不同。 例如，虽然可以调用 C# 泛型类中的用户定义的运算符，但是无法调用算术运算符。
- C# 不允许使用非类型模板参数，如 template C<int i> {}。
- C# 不支持显式定制化；即特定类型模板的自定义实现。
- C# 不支持部分定制化：部分类型参数的自定义实现。
- C# 不允许将类型参数用作泛型类型的基类。
- C# 不允许类型参数具有默认类型。
- C# 泛型类型参数本身不能是泛型，但是构造类型可以用作泛型。 C++ 允许使用模板参数。
- C++ 允许在模板中使用可能并非对所有类型参数有效的代码，随后针对用作类型参数的特定类型检查此代码。 C# 要求类中编写的代码可处理满足约束的任何类型。 例如，在 C++ 中可以编写一个函数，此函数对类型参数的对象使用算术运算符 + 和 -，在实例化具有不支持这些运算符的类型的模板时，此函数将产生错误。 C# 不允许此操作；唯一允许的语言构造是可以从约束中推断出来的构造。

C++ 模板和 C# 泛型在语法层次，C# 泛型是参数化类型的一个更简单的方法，而不具有 C++ 模板的复杂性。 此外，C# 不试图提供 C++ 模板所具有的所有功能。 在实现层次，主要区别在于 C# 泛型类型的替换在运行时执行，从而为实例化对象保留了泛型类型信息。


模板函数定义的一般形式如下所示：

    template <typename type> ret-type func-name(parameter list)
    {
       // body
    }

C++ 的模板定义的是一类具有相似行为的对象：

- `class template` a family of classes, which may be nested classes 
- `function template` a family of functions, which may be member functions 
- `alias template` an alias to a family of types (since C++11) 
- `variable template` a family of variables (since C++14) 


函数模板示例：

    #include <iostream>
    #include <string>
     
    using namespace std;
     
    template <typename T>
    inline T const& Max (T const& a, T const& b) 
    { 
        return a < b ? b:a; 
    } 

    int main ()
    {
        int i = 39;
        int j = 20;
        cout << "Max(i, j): " << Max(i, j) << endl; 
     
        double f1 = 13.5; 
        double f2 = 20.7; 
        cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
     
        string s1 = "Hello"; 
        string s2 = "World"; 
        cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
     
       return 0;
    }

类模板示例：

    #include <iostream>
    #include <vector>
    #include <cstdlib>
    #include <string>
    #include <stdexcept>

    using namespace std;

    template <class T>
    class Stack 
    {
    private:
        vector<T> elems;

    public:
        Stack<T>& push(T const&);
        T pop();
        T top() const;
        bool empty() const {
            return elems.empty();
        }
        int size() const {
            return elems.size();
        }
    };

    template<class T>
    Stack<T>& Stack<T>::push(T const& elem)
    {
        elems.push_back(elem);
        return *this;
    }

    template<class T>
    T Stack<T>::pop()
    {
        if (elems.empty())
        {
            throw out_of_range("<Stack<T>::pop() with empty stack");
        }
        T back = elems.back();
        elems.pop_back();
        return back;
    }

    template <class T>
    T Stack<T>::top() const
    {
        if (elems.empty())
        {
            throw out_of_range("<Stack<T>::top() with empty stack");
        }
        return elems.back();
    }

    int main()
    {
        try
        {
            Stack<int> iStack;
            Stack<string> sStack;

            iStack.push(7).push(8);
            cout << iStack.pop() << endl;
            cout << iStack.top() << endl;

            sStack.push("hello").push("world");
            cout << sStack.pop() << sStack.pop()  << endl;
            sStack.pop();
        } catch (exception const& ex)
        {
            cerr << "Exception: " << ex.what() << endl;
            return -1;
        }
    }


## map 映射容器
- https://www.w3cschool.cn/cpp/cpp-fu8l2ppt.html
- https://docs.microsoft.com/zh-cn/cpp/standard-library/map
- https://docs.microsoft.com/zh-cn/cpp/standard-library/multimap-class

Map 是 C++ 标准容器，提供了很好 Key-Value 一对一的关系。用于存储和检索集合中的数据，此集合中的每个元素均为包含数据值和排序键的元素对。 键的值是唯一的，用于自动排序数据，可以直接更改映射中的元素值。 键值是常量，不能更改。 必须先删除与旧元素关联的键值，才能为新元素插入新键值。

C++ 标准库 map 类为：

- 大小可变的关联容器，基于关联键值高效检索元素值。
- 可逆，因为它提供双向迭代器来访问其元素。
- 有序，因为它的元素根据指定的比较函数按键值排序。
- 唯一。 因为它的每个元素必须具有唯一键。
- 关联容器对，因为它的元素数据值与其键值不同。
- 类模板实现，是泛型的，独立于元素或键类型。

C++ 标准库多重映射类 multimap 用于存储和检索集合中的数据，此集合中的每个元素均为包含数据值和排序键的元素对。 键值不需要唯一，用于自动排序数据。 可以直接更改多重映射中的元素值，但不能直接更改其关联键值。 必须先删除与旧元素关联的键值，才能插入与新元素关联的新键值。

C++ 标准库多重映射类：

- 大小可变的关联容器，支持基于关联键值高效检索元素值。
- 可逆，因为它提供双向迭代器来访问其元素。
- 有序，因为它的元素在容器中根据指定的比较函数按键值排序。
- 多个，它的元素不需要具有唯一键，因此一个键值可具有多个相关联的元素数据值。
- 关联容器对，因为它的元素数据值与其键值不同。
- 类模板实现，是泛型的，因此与作为元素或键包含的特定数据类型无关。


构造函数用法；

    map<char, int> mapchar;
    map<char, string> mapchar;
    map<int, char> mapint；
    map<int, string> mapint;
    map<sring, char> mapstring;
    map<string, int> mapstring;

添加数据；

    map<int ,string> maplive;  
    maplive.insert(pair<int,string>(102,"aclive"));
    maplive.insert(map<int,string>::value_type(321,"hai"));
    maplive[112]="April";

成员类型：

| Member type   |  Definition  |
| :-------- | :-------- |
| key_type  | Key  |
| mapped_type   | T  |
| value_type    | std::pair<const Key, T>  |
| size_type | Unsigned integer type (usually std::size_t)  |
| difference_type   | Signed integer type (usually std::ptrdiff_t)  |
| key_compare   | Compare  |
| allocator_type    | Allocator  |
| reference | Allocator::reference (until C++11), value_type& (since C++11) |
| const_reference   | Allocator::const_reference (until C++11), const value_type& (since C++11) |
| pointer   | Allocator::pointer (until C++11), std::allocator_traits<Allocator>::pointer (since C++11) |
| const_pointer | Allocator::const_pointer (until C++11), std::allocator_traits<Allocator>::const_pointer (since C++11) |
| iterator  | BidirectionalIterator  |
| const_iterator    | Constant bidirectional iterator  |
| reverse_iterator  | std::reverse_iterator<iterator>  |
| const_reverse_iterator    | std::reverse_iterator<const_iterator>  |
| node_type | a specialization of node handle representing a container node (since C++17)  |
| insert_return_type    | instantiated with template arguments iterator and node_type. (since C++17)  |

基本操作函数：

- `at`             查找具有指定键值的元素。
- `begin`          返回指向 map 头部的迭代器
- `begin`          返回指向 map 头部的迭代器
- `clear`          删除所有元素
- `count`          返回指定元素出现的次数
- `empty`          如果 map 为空则返回 true
- `emplace`        将就地构造的元素插入到映射。
- `end`            返回指向 map 末尾的迭代器
- `equal_range`    返回特殊条目的迭代器对
- `erase`          删除一个元素
- `find`           查找一个元素
- `get_allocator`  返回 map 的配置器
- `insert`         插入元素
- `key_comp`       返回比较元素 key 的函数
- `lower_bound`    返回键值 >= 给定元素的第一个位置
- `max_size`       返回可以容纳的最大元素个数
- `rbegin`         返回一个指向 map 尾部的逆向迭代器
- `rend`           返回一个指向 map 头部的逆向迭代器
- `size`           返回 map 中元素的个数
- `swap`           交换两个 map
- `upper_bound`    返回键值 > 给定元素的第一个位置
- `value_comp`     返回比较元素 value 的函数

示例程序：

    #include <map>
    #include <iostream>

    int main( )
    {
        using namespace std;
        map <int, int> m1;

        map <int, int> :: iterator m1_Iter;
        map <int, int> :: const_iterator m1_cIter;
        map <int, int> :: const_iterator m1_eIter;
        typedef pair <int, int> Int_Pair;

        m1.insert ( Int_Pair ( 0, 0 ) );
        m1.insert ( Int_Pair ( 1, 1 ) );
        m1.insert ( Int_Pair ( 1, 3 ) );
        m1.insert ( Int_Pair ( 2, 4 ) );

        m1_cIter = m1.begin ( );
        cout << "The first element of m1 is " << m1_cIter -> first << endl;
        cout << "The second element of m1 is " << m1_cIter -> second << endl;
        // cout << "The third element of m1 is " << m1_cIter -> third << endl; // no third

        m1_Iter = m1.begin ( );
        m1.erase ( m1_Iter );

        // The following 2 lines would err because the iterator is const
        // m1_cIter = m1.begin ( );
        // m1.erase ( m1_cIter );

        m1_cIter = m1.begin( );
        cout << "The first element of m1 is now " << m1_cIter -> first << endl;

        // Keys must be unique in map, so duplicates are ignored
        int i = m1.count(1);
        cout << "The number of elements in m1 with a sort key of 1 is: " << i << "." << endl;

        i = m1.count(2);
        cout << "The number of elements in m1 with a sort key of 2 is: " << i << "." << endl;

        m1_Iter = m1.begin( );
        m1_eIter = m1.end();
        cout << "double each element in map:\n<key -> value>\n";
        while ( m1_Iter != m1_eIter)
        {
            m1_Iter -> second *= 2;
            cout << m1_Iter -> first << " -> " << m1_Iter -> second << "\n";
            m1_Iter++;
        }
        cout << "The number of element in map with a key 2 is: " << m1[2] << endl;

        i = m1.size();
        m1.clear();
        cout << "The size of the map after clearing is " << m1.size() << ", whcih before is " << i << "." << endl;
    }

注意，map 取值主要有 at 和下标 [] 两种操作，(C++11) 引入的 at 会作下标检查。map 可使用类似数组下标的方式访问元素。multimap 不可以这样访问元素，它需要通过迭代器访问：

    m1_Iter = m1.find(2);
    cout << "The number of element in map with a key 2 is: " << m1_Iter->second << endl;



## vector 向量容器
- https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
- https://www.w3cschool.cn/cpp/cpp-i6da2pq0.html

向量 Vector 封装了动态大小数组的序列容器 Sequence Container。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。

容器特性：

- `顺序序列` 顺序容器中的元素按照严格的线性顺序排序。可以通过元素在序列中的位置访问对应的元素。
- `动态数组` 支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算述进行该操作。操供了在序列末尾相对快速地添加/删除元素的操作。
- `内存分配感知` Allocator-aware 容器使用一个内存分配器对象来动态地处理它的存储需求。

Vector 是 C++ STL的一个重要成员。

定义：

    template<
        class T,
        class Allocator = std::allocator<T>
    > class vector; (1)  

    namespace pmr {
        template <class T>
        using vector = std::vector<T, std::pmr::polymorphic_allocator<T>>;
    } (2) (since C++17) 

1) std::vector is a sequence container that encapsulates dynamic size arrays.
2) std::pmr::vector is an alias template that uses a polymorphic allocator

vector 有五种构造方式：

    #include<vector>;

    int a[7]={1,2,3,4,5,9,8};
    vector<int> v(a,a+7); // 从数组中获得初值
    vector<int> b(10);    // 定义了 10 个整型元素的向量，但没有给出初值。
    vector<int> b(10,1);  // 定义了 10 个整型元素的向量初值为 1
    vector<int> c(b);     // 整体复制 b 向量
    vector<int> c(b.begin(),b.begin+3); // 从 b 向量中提取元素
 
vector 对象的增删改遍历等重要操作：

    a.at(pos < size())
    a.back();  // 返回最后一个元素
    a.front(); // 返回第一个元素
    a[i];      // 返回第 i 个元素，a[i] 必须存在才可以访问

    a.assign(4,2); // 定义 a 含 4 个元素，初始值 2
    a.assign(b.begin(), b.begin()+3); // b 为向量，将 b 的 0~2 个元素构成的向量赋给a
    a.capacity(); // 返回向量对象现有的容量，即可容纳的元素个数
    a.clear(); // 清空元素
    a.empty(); // 判断是否为空，返回 ture、false
    a.erase(a.begin()+1, a.begin()+3); // 删除元素，但不包括 a.begin()+3
    a.insert(a.begin()+1,3,5); // 在 1 索引位置插入 3 个数，其值都为5
    a.insert(a.begin()+1,5);   // 在 1 索引位置插入数值 5
    a.insert(a.begin()+1,b+3,b+6); // 在 1 索引位置插入数组 b 的第3个元素到第5个元素
    a.pop_back(); // 删除向量的最后一个元素
    a.push_back(5); // 在向量最后插入一个元素，值为 5
    a.reserve(100); // 保留并扩容，如果容量少于 100 则扩充至 100，大于 100 则保留原容量
    a.resize(10); // 调整容量为 10 个，元素多则删，少则补，其值随机
    a.resize(10,2); // 调整空间为 10 个，多则删，少则补，其值为 2
    a.size(); // 返回向量元素的个数；
    a.swap(b); // 两向量元素整体进行交换
    a==b;  // 向量的比较操作，还有!=,>=,<=,>,<

示例：

    #include <iostream>
    #include <vector>
    #include <algorithm>

    int main()
    {
        // Create a vector containing integers
        std::vector<int> v = {7, 5, 16, 8};
     
        // Add two more integers to vector
        v.push_back(25);
        v.push_back(13);
        sort(v.begin(),v.end());

        // Iterate and print values of vector
        for(int n : v) {
            std::cout << n << '\n';
        }
    }

Output:

    7
    5
    16
    8
    25
    13

利用数组下标遍历 & 迭代器遍历：

    #include <string.h>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    using namespace std;
     
    int main()
    {
        vector<int>obj;
        for(int i=0;i<10;i++)
        {
            obj.push_back(i);   
        } 
     
        for(int i=0;i<10;i++)
        {
            cout << obj[i] << " ";
        }
     
        cout<<endl; 
        vector<int>::iterator it;
        for(it=obj.begin();it!=obj.end();it++)
        {
            cout<<*it<<" ";
        }
        return 0;
    }

使用 vector 注意事项：

1、如果你要表示的向量长度较长，容易导致内存泄漏，而且效率会很低；
2、Vector作为函数的参数或者返回值时，需要注意它的写法：

    double Distance(vector<int>&a, vector<int>&b)

其中的“&”绝对不能少！！！


## set 有序集合

set 跟 vector 类似，唯一区别就是，set 里面的元素是有序的且唯一的，往 set 里添加元素，它就会自动排序，而且，对于已经存在数据就忽略添加操作。

    #include <iostream>
    #include <iomanip>
    #include <set>
    #include <string>

    using namespace std;

    template <typename T>
    void showset(set<T> v)
    {
        for (typename set<T>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << setw(10) << left << *it;
        }
        cout << endl;
    }

    int main()
    {
        set<int> nums{9,8,1,2,3,4,5,5,5,6,7,7 };
        showset(nums);
        set<string> fruits{ "pineapple", "apple", "melon", "peach" };
        showset(fruits);

        nums.insert(9); // do nothing for existing one
        fruits.insert("berry");
        showset(fruits);
        
        // system("pause");
        return 0;
    } 



## list 链表

list 就是双向链表数据结构，C 语言中经常需要自己实现链表，但是，花时间实现高效的链表，这种重复造轮子并不这个讨好。

除了 list 双向链表，还有单链表容器 foward_list。

list 双向链表的优点是插入和删除元素都比较快捷，缺点是不能随机访问元素。

    #include <list>
    #include <iostream>
    #include <iomanip>
    #include <list>
    #include <string>

    using namespace std;

    template <typename T>
    void showlist(list<T> v)
    {
        for (list<T>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << setw(4) << left << *it;
        }
        cout << endl;
    }

    int main()
    {
        list<int> l1{ 1,2,3,4,5,5,6,7,7 };
        l1.sort();
        l1.reverse();
        showlist(l1);
        list<double> l2;
        list<char> l3(10);
        list<int> l4(5, 10); // 将元素都初始化为10
        showlist(l4);

        // system("pause");
        return 0;
    } 


值得注意的是，list 容器不能调用 algorithm 下的 sort 函数进行排序，因为 sort 函数要求容器必须可以随机存储。所以，list 内部实现了排序函数。

GCC 编译程序时候提示如下错误：

    error: need 'typename' before 'std::list<T>::iterator' because 'std::list<T>' is a dependent scope|

提示的意思是说在 list<T> 前面需要用 typename 限定一下，因为编译器不知道 list<T>::iterator 是代表一个类型，更改代码：

    list<T>::iterator it; => typename std::list<T>::iterator it;



# stream format
- https://en.cppreference.com/w/cpp/utility/format/format
- https://en.cppreference.com/w/cpp/header/iomanip

C++ 的 `<cstdio>` 头文件定义替代 C 的 `<stdio.h>`：

    int printf( const char* format, ... ); (1)  
    int fprintf( std::FILE* stream, const char* format, ... ); (2)  
    int sprintf( char* buffer, const char* format, ... ); (3)  
    int snprintf( char* buffer, std::size_t buf_size, const char* format, ... ); (4) (since C++11) 

    const char *fmt = "sqrt(2) = %f";
    int sz = std::snprintf(nullptr, 0, fmt, std::sqrt(2));
    std::vector<char> buf(sz + 1); // note +1 for null terminator
    std::snprintf(&buf[0], buf.size(), fmt, std::sqrt(2));

Formatting library (C++20)，对没错老妖怪这时才提供格式化函数库，在头文件 `<format>` 中定义，但是这个功能边 GCC 10.1 也没支持：
    
    #include <iostream>
    #include <format>
     
    int main() {
        std::format("{} {}!", "Hello", "world", "something"); // OK, produces "Hello world!"
        std::cout << std::format("Hello {}!\n", "world");
    }

示范，利用字符串打印函数 `_vsnprintf` 实现一个 format 函数：

    // #include <boost/format.hpp>
    // #include <format> // C++20

    #include <string>
    #include <vector>
    #include <cstdarg>

    std::string format(const char *pszFmt, ...)
    {
        std::string str;
        va_list args;
        va_start(args, pszFmt);
        {
            int nLength = _vscprintf(pszFmt, args);
            nLength += 1;  // plus 1 for null-terminator
            std::vector<char> vectorChars(nLength);
            _vsnprintf(vectorChars.data(), nLength, pszFmt, args);
            str.assign(vectorChars.data());
        }
        va_end(args);
        return str;
    }

    int main()
    {
        char c = 'A';
        std::string str = format("c=%c", c);  // c=A
             
        int i = 10;
        str = format("i=%c", i);  // i=10
         
        double d = 1.5;
        str = format("d=%f", d);  // d = 1.500000
         
        std::string strName = ("txdy");
        str = format("I am %s", strName.c_str());  // I am txdy
    }


C 库定义的宏 va_start 初始化 ap 变量，变量类型 va_list 是参数列表。此宏与 va_arg、va_end 搭配使用，并在它们之前调用。last_arg 是最后一个传递给函数的命名参数，即省略号之前的最后一个参数。

    void va_start(va_list ap, last_arg);



C++ 中常用的输出流操纵算子都是在头文件 `<iomanip>` 中定义的。

C++ 流操纵算子

| 流操纵算子 | 作  用 |
| :-------- | :-------- |
| dec       | 以十进制形式输出整数 |
| hex       | 以十六进制形式输出整数 |
| oct       | 以八进制形式输出整数 |
| fixed     | 以普通小数形式输出浮点数 |
| scientific| 以科学计数法形式输出浮点数 |
| left      | 左对齐，即在宽度不足时将填充字符添加到右边 |
| right     | 右对齐，即在宽度不足时将填充字符添加到左边 |
| setbase(b)| 设置输出整数时的进制，b=8、10 或 16 |
| setw(w)   | 指定输出宽度为 w 个字符，或输人字符串时读入 w 个字符 |
| setfill(c)| 在指定输出宽度的情况下，输出的宽度不足时用字符 c 填充（默认情况是用空格填充） |
| setprecision(n)   | 设置输出浮点数的精度为 n。 |
| setiosflags(flag) | 将某个输出格式标志置为 1 |
| resetiosflags(flag)   | 将某个输出格式标志置为 0 |
| boolapha  | 把 true 和 false 输出为字符串 |
| *noboolalpha  | 把 true 和 false 输出为 0、1 |
| showbase  | 输出表示数值的进制的前缀 |
| *noshowbase   | 不输出表示数值的进制.的前缀 |
| showpoint | 总是输出小数点 |
| *noshowpoint  | 只有当小数部分存在时才显示小数点 |
| showpos   | 在非负数值中显示 + |
| *noshowpos| 在非负数值中不显示 + |
| *skipws   | 输入时跳过空白字符 |
| noskipws  | 输入时不跳过空白字符 |
| uppercase | 十六进制数中使用 A~E。若输出前缀，则前缀输出 0X，科学计数法中输出 E |
| *nouppercase  | 十六进制数中使用 a~e。若输出前缀，则前缀输出 0x，科学计数法中输出 e。 |
| internal  | 数值的符号（正负号）在指定宽度内左对齐，数值右对 齐，中间由填充字符填充。 |


使用这些算子的方法是将算子用 << 和 cout 连用。例如：

    cout << hex << 12 << "," << 24;

这条语句的作用是指定以十六进制形式输出后面两个数，因此输出结果是：

    c, 18

在使用非 fixed 且非 scientific 方式输出的情况下，n 即为有效数字最多的位数，如果有效数字位数超过 n，则小数部分四舍五人，或自动变为科学计 数法输出并保留一共 n 位有效数字。

在使用 fixed 方式和 scientific 方式输出的情况下，n 是小数点后面应保留的位数。


setiosflags() 算子实际上是一个库函数，它以一些标志作为参数，这些标志可以是在 iostream 头文件中定义的以下几种取值，它们的含义和同名算子一样。

| 标 志       | 作 用 |
| :-------  | :-------  |
| ios::left | 输出数据在本域宽范围内向左对齐 |
| ios::right    | 输出数据在本域宽范围内向右对齐 |
| ios::internal | 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充 |
| ios::dec  | 设置整数的基数为 10 |
| ios::oct  | 设置整数的基数为 8 |
| ios::hex  | 设置整数的基数为 16 |
| ios::showbase | 强制输出整数的基数（八进制数以 0 开头，十六进制数以 0x 打头） |
| ios::showpoint    | 强制输出浮点数的小点和尾数 0 |
| ios::uppercase    | 在以科学记数法格式 E 和以十六进制输出字母时以大写表示 |
| ios::showpos  | 对正数显示“+”号 |
| ios::scientific   | 浮点数以科学记数法格式输出 |
| ios::fixed    | 浮点数以定点格式（小数形式）输出 |
| ios::unitbuf  | 每次输出之后刷新所有的流 |
| ios::stdio    | 每次输出之后清除 stdout, stderr |

这些标志实际上都是仅有某比特位为 1，而其他比特位都为 0 的整数。

多个标志可以用|运算符连接，表示同时设置。例如：

    cout << setiosflags(ios::scientific|ios::showpos) << 12.34;

    +1.234000e+001

如果两个相互矛盾的标志同时被设置，如先设置 setiosflags(ios::fixed)，然后又设置 setiosflags(ios::scientific)，那么结果可能就是两个标志都不起作用。因此，在设置了某标志，又要设置其他与之矛盾的标志时，就应该用 resetiosflags 清除原先的标志。例如下面三条语句：

    cout << setiosflags(ios::fixed) << 12.34 << endl;
    cout << resetiosflags(ios::fixed) << setiosflags(ios::scientific | ios::showpos) << 12.34 << endl;
    cout << resetiosflags(ios::showpos) << 12.34 << endl;  //清除要输出正号的标志

输出结果是：

    12.340000
    +1.234000e+001
    1.234000e+001

关于流操纵算子的使用，来看下面的程序。

    #include <iostream>
    #include <iomanip>
    using namespace std;
    int main()
    {
        int n = 141;
        //1) 分别以十六进制、十进制、八进制先后输出 n
        cout << "1)" << hex << n << " " << dec << n << " " << oct << n << endl;
        double x = 1234567.89, y = 12.34567;
        //2)保留5位有效数字
        cout << "2)" << setprecision(5) << x << " " << y << " " << endl;
        //3)保留小数点后面5位
        cout << "3)" << fixed << setprecision(5) << x << " " << y << endl;
        //4)科学计数法输出，且保留小数点后面5位
        cout << "4)" << scientific << setprecision(5) << x << " " << y << endl;
        //5)非负数显示正号，输出宽度为12字符，宽度不足则用 * 填补
        cout << "5)" << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
        //6)非负数不显示正号，输出宽度为12字符，宽度不足则右边用填充字符填充
        cout << "6)" << noshowpos << setw(12) << left << 12.1 << endl;
        //7)输出宽度为 12 字符，宽度不足则左边用填充字符填充
        cout << "7)" << setw(12) << right << 12.1 << endl;
        //8)宽度不足时，负号和数值分列左右，中间用填充字符填充
        cout << "8)" << setw(12) << internal << -12.1 << endl;
        cout << "9)" << 12.1 << endl;
        return 0;
    }

程序的输出结果是：

    1)8d 141 215
    2)1.2346e+06 12.346
    3)1234567.89000 12.34567
    4)1.23457e+06 1.23457e+01
    5)***+12.10000
    6)12.10000****
    7)****12.10000
    8)-***12.10000
    9)12.10000

需要注意的是，setw() 算子所起的作用是一次性的，即只影响下一次输出。每次需要指定输出宽度时都要使用 setw()。因此可以看到，第 9) 行的输出因为没有使用 setw()，输出的宽度就不再是前面指定的 12 个字符。

在读入字符串时，setw() 还能影响 cin 的行为。例如下面的程序：

    #include <iostream>
    #include <iomanip>
    using namespace std;
    int main()
    {
        string s1, s2;
        cin >> setw(4) >> s1 >> setw(3) >> s2;
        cout << s1 << "," << s2 << endl;
        return 0;
    }

输入：

    1234567890↙

程序的输出结果是：

    1234,567

说明setw(4)使得读入 s1 时，只读入 4 个字符，其后的setw(3)使得读入 s2 时只读入 3 个字符。

setw() 用于 cin 时，同样只影响下一次的输入。

思考题：setw() 究竟是如何实现的，以至于能和 cout 连用来指定输出宽度？自行查看编译器所带的 iomanip 头文件，然后写一个功能和 setw() 完全相同的 mysetw()。

调用cout的成员函数

ostream 类有一些成员函数，通过 cout 调用它们也能用于控制输出的格式，其作用和流操纵算子相同，如表 3 所示。

| 成员函数  | 作用相同的流操纵算子    | 说明 |
| :-------- | :-------- | :-------- |
| precision(n)  | setprecision(n)   | 设置输出浮点数的精度为 n。 |
| width(w)  | setw(w)   | 指定输出宽度为 w 个字符。 |
| fill(c)   | setfill(c)    | 在指定输出宽度的情况下，输出的宽度不足时用字符 c 填充（默认情况是用空格填充）。|
| setf(flag)    | setiosflags(flag) | 将某个输出格式标志置为 1。 |
| unsetf(flag)  | resetiosflags(flag)   | 将某个输出格式标志置为 0。 |

setf 和 unsetf 函数用到的flag，与 setiosflags 和 resetiosflags 用到的完全相同。

这些成员函数的用法十分简单。例如下面的三行程序：

    cout.setf(ios::scientific);
    cout.precision(8);
    cout << 12.23 << endl;


# string
- https://www.runoob.com/cplusplus/cpp-strings.html

C++ 提供了以下两种类型的字符串表示形式：

- C 风格字符串 `#include <cstring>`
- C++ 引入的 string 类类型 `#include <string>`

C 风格的字符串起源于 C 语言，并在 C++ 中继续得到支持。字符串实际上是使用 null 终止的一维字符数组 Null-terminated。是一个以 null 结尾的字符串，包含了组成字符串的字符。

下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。

    char greeting[6] = {'H', 'e', 'l', 'l', 'o', ''};
    char greeting[] = "Hello";

不需要把 null 字符放在字符串常量的末尾。C++ 编译器会在初始化数组时，自动添加在末尾。

示例：

    #include <iostream>
    #include <string>
     
    // using std::string;
    // using std::cout;
    using namespace std;
     
    int main ()
    {
        char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

        cout << "Greeting message: ";
        cout << greeting << endl;

        string ss [] = {"Beijing", "Shanghai", "Chengdu"};
        cout << ss[1];

        return 0;
    }

C 风格函数：

    #include <iostream>
    #include <cstring>
     
    using namespace std;
     
    int main ()
    {
       char str1[11] = "Hello";
       char str2[11] = "World";
       char str3[11];
       int  len ;
     
       strcpy( str3, str1);
       cout << "strcpy( str3, str1) : " << str3 << endl;
     
       strcat( str1, str2);
       cout << "strcat( str1, str2): " << str1 << endl;
     
       len = strlen(str1);
       cout << "strlen(str1) : " << len << endl;
     
       return 0;
    }

C++ 字符串对象：

    #include <iostream>
    #include <string>
     
    using namespace std;
     
    int main ()
    {
       string str1 = "Hello";
       string str2 = "World";
       string str3;
       int  len ;
     
       // 复制 str1 到 str3
       str3 = str1;
       cout << "str3 : " << str3 << endl;
     
       // 连接 str1 和 str2
       str3 = str1 + str2;
       cout << "str1 + str2 : " << str3 << endl;
     
       // 连接后，str3 的总长度
       len = str3.size();
       cout << "str3.size() :  " << len << endl;
     
       return 0;
    }


C++ `<string>` 提供以下类型定义： 

| Type      | Definition    |
| :-------- | :-------- |
| `std::string` | std::basic_string<char>  |
| `std::wstring`    | std::basic_string<wchar_t>  |
| `std::u16string` (C++11)  | std::basic_string<char16_t>  |
| `std::u32string` (C++11)  | std::basic_string<char32_t>  |
| `std::pmr::string` (C++17)    | std::pmr::basic_string<char>  |
| `std::pmr::wstring` (C++17)   | std::pmr::basic_string<wchar_t>  |
| `std::pmr::u16string` (C++17) | std::pmr::basic_string<char16_t>  |
| `std::pmr::u32string` (C++17) | std::pmr::basic_string<char32_t  |


C++ 字符串类成员类型 String Member types

| member type   | definition    |
| :----------   | :----------   |
| value_type    | char |
| traits_type   | char_traits<char> |
| allocator_type| allocator<char> |
| reference     | char& |
| const_reference   | const char& |
| pointer       | char* |
| const_pointer | const char* |
| iterator      | a random access iterator to char (convertible to const_iterator) |
| const_iterator    | a random access iterator to const char |
| reverse_iterator  | reverse_iterator<iterator> |
| const_reverse_iterator    | reverse_iterator<const_iterator> |
| difference_type   | ptrdiff_t |
| size_type     | size_t |

C++ 字符串成员方法 Member functions

- (constructor) constructs a basic_string
- (destructor) destroys the string, deallocating internal storage if used
- `operator=` assigns values to the string
- `assign` assign characters to a string
- `get_allocator` returns the associated allocator

Element access 

- `at` access specified character with bounds checking
- `operator[]` access specified character
- `front` (C++11) accesses the first character
- `back` (C++11) accesses the last character
- `data` returns a pointer to the first character of a string
- `c_str` returns a non-modifiable standard C character array version of the string
- `operator basic_string_view` (C++17) returns a non-modifiable string_view into the entire string

Iterators 

- `begincbegin` (C++11) returns an iterator to the beginning
- `end` `cend` (C++11) returns an iterator to the end
- `rbegin` `crbegin` (C++11) returns a reverse iterator to the beginning
- `rend` `crend` (C++11) returns a reverse iterator to the end

Capacity 

- `empty` checks whether the string is empty
- `sizelength` returns the number of characters
- `max_size` returns the maximum number of characters
- `reserve` reserves storage
- `capacity` returns the number of characters that can be held in currently allocated storage
- `shrink_to_fit` (C++11) reduces memory usage by freeing unused memory

Operations 

- `clear` clears the contents
- `insert` inserts characters
- `erase` removes characters
- `push_back` appends a character to the end
- `pop_back` (C++11) removes the last character
- `append` appends characters to the end
- `operator`+= appends characters to the end
- `compare` compares two strings
- `replace` replaces specified portion of a string
- `substr` returns a substring
- `copy` copies characters
- `resize` changes the number of characters stored
- `swap` swaps the contents

Search 

- `find` find characters in the string
- `rfind` find the last occurrence of a substring
- `find_first_of` find first occurrence of characters
- `find_first_not_of` find first absence of characters
- `find_last_of` find last occurrence of characters
- `find_last_not_of` find last absence of characters




## string split

C++11之前只能自己写，我目前发现的史上最优雅的一个实现是这样的：
    
    void split(const string& s, vector<string>& tokens, const string& delimiters = " ")
    {
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos) {
            tokens.push_back(s.substr(lastPos, pos - lastPos));//use emplace_back after C++11
            lastPos = s.find_first_not_of(delimiters, pos);
            pos = s.find_first_of(delimiters, lastPos);
        }
    }

从C++11开始，标准库中提供了regex，regex用来做split就是小儿科了，比如：
    
    std::string text = "Quick brown fox.";
    std::regex ws_re("\\s+"); // whitespace
    std::vector<std::string> v(std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1), 
        std::sregex_token_iterator());
    for(auto&& s: v)
        std::cout<<s<<"\n";

结合 C++17 提供的 string_view 实现，减少拷贝，性能有不小提升，参看此文：
Speeding Up string_view String Split Implementation。
https://www.bfilipek.com/2018/07/string-view-perf-followup.html

从 C++20 开始，标准库中提供了 ranges，有专门的 split view，只要写 `str|split(' ')` 就可以切分字符串，如果要获取结果 `vector<string>` 可以这样用(随手写的，可能不是最简)：
    
    string str("hello world test split");
    auto sv = str
        | ranges::views::split(' ') 
        | ranges::views::transform([](auto&& i){
            return i | ranges::to<string>(); }) 
        | ranges::to<vector>();
        
    for(auto&& s: sv) {
        cout<<s<<"\n";
    }

其实 C 语言里面也有一个函数 strtok 用于 char* 的 split，例如：
    
    #include <string.h>
    #include <iostream>
    #include <string>
    using namespace std;
    int main() 
    {
        string str = "one two three four five";
        char *token = strtok(str.data(), " ");// non-const data() needs c++17
        while (token != NULL) {
            std::cout << token << '\n';
            token = strtok(NULL, " ");
        }
    }

这里要注意的是 strtok 的第一个参数类型是 char* 而不是 const char* 实际上 strtok 的确会改变输入的字符串。


## string literal

在C++中，

    char* p = "abc";　　// valid in C, invalid in C++

会跳出警告：

    warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

等号两边的变量类型不一样，进行了隐式类型转换 implicit conversion。

等号右边的 "abc" 是一个 string literal 字面常量，是 `const char*`，而 p 则是一个 `char*`。将右边的常量强制类型转换成一个指针，结果就是我们在修改一个 const 常量。编译运行的结果会因编译器和操作系统共同决定，有的编译器会通过，有的会抛异常，就算过了也可能因为操作系统的敏感性而被杀掉。

像这种直接将 string literal 赋值给指针的操作被开发者们认为是 deprecated，只不过由于以前很多代码都有这种习惯，为了兼容，就保留下来了。更规矩的写法：

    char* p = (char*)"abc";  // OK
    char const *p = "abc";　　// OK


# iostream & file
- [Input/output library](https://en.cppreference.com/w/cpp/io#Stream-based_I.2FO)
- [std::basic_fstream](https://en.cppreference.com/w/cpp/io/basic_fstream)
- https://docs.microsoft.com/zh-cn/cpp/standard-library/iostream
- https://docs.microsoft.com/zh-cn/cpp/standard-library/fstream

C++ 两个 I/O 库，现代的基于流的 Stream-based I/O，以及兼容的 C-style I/O。

基于流的 I/O，由高度抽象的 ios_base -> basic_ios 类型作为文件流、内存流或其它流的接口适配。再了继承生成 basic_ostream、basic_istream、basic_iostream 等一系列的明确输入或输出方向的流对象。再按具体流设备的差异，实现各种不同的流对象类型，如下：

- File I/O implementation `<fstream>`

    - basic_filebuf 
    - basic_ifstream
    - basic_ofstream
    - basic_fstream
 
- String I/O implementation `<sstream>`

    - basic_stringbuf
    - basic_istringstream
    - basic_ostringstream
    - basic_stringstream

- Array I/O implementations `<strstream>`

    - strstreambuf 已经在 C++98 标准弃用
    - istrstream 已经在 C++98 标准弃用
    - ostrstream 已经在 C++98 标准弃用
    - strstream 已经在 C++98 标准弃用


在 (since C++11) 引用 `<iostream>` 头文件后，相当引用了以下四个：

    #include <ios>
    #include <streambuf>
    #include <istream>
    #include <ostream>

基本流对象 `<iostream>` 定义了标准的输入输出流：

| 标准流对象 | 流对象类型 | 说明    |
| :-------  | :-------  | :-------  |
| std::cin  | istream   | standard input |
| std::cout | ostream   | standard output |
| std::cerr | ostream   | standard error |
| std::clog | ostream   | standard log |
| std::wcin | wistream  | standard input |
| std::wcout| wostream  | standard output |
| std::wcerr| wostream  | standard error |
| std::wclog| wostream  | standard log |

这些标准流对象的基础类型：

    typedef basic_istream<char>         istream;
    typedef basic_istream<wchar_t>     wistream;
    typedef basic_ostream<char>         ostream;
    typedef basic_ostream<wchar_t>     wostream;
    typedef basic_iostream<char>       iostream;
    typedef basic_iostream<wchar_t>   wiostream;

在控制台程序中，cin 和 cout 可以用来在字符界面输入输出。

基本文件流 `<fstream>` 定义了：

| 流对象类型 | 基础类型  |
| :------   | :------   |
| basic_filebuf | 实现低层文件设备 |
| basic_ifstream| 实现高级文件流输入操作 |
| basic_ofstream| 实现高级文件流输出操作 |
| basic_fstream | 实现高级文件流输入输出操作 |

类型定义 Typedefs：

| 流对象类型 | 基础类型  |
| :------   | :------   |
| filebuf   | basic_filebuf<char>   |
| wfilebuf  | basic_filebuf<wchar_t>    |
| ifstream  | basic_ifstream<char>  |
| wifstream | basic_ifstream<wchar_t>   |
| ofstream  | basic_ofstream<char>  |
| wofstream | basic_ofstream<wchar_t>   |
| fstream   | basic_fstream<char>   |
| wfstream  | basic_fstream<wchar_t>    |

基本文件流对象：

| class     | 默认模式  |
| :-------- | :-------- |
| ofstream  | ios::out  |
| ifstream  | ios::in   |
| fstream   | ios::in or ios::out   |

常用文件流模式：

| 文件模式      | 说明    |
| :-------- | :-------- |
| ios::in   | 读取    |
| ios::out  | 写入    |
| ios::binary| 二进制  |
| ios::ate  | 初始化读写游标到文件末端 at end   ，默认会在文件开头|
| ios::app  | 附加内容 append   |
| ios::trunc| 截断清空文件，如果文件存在 |

读写操作的数据由读写游标位置决定，默认是文件开头 ios::beg：

| 游标位置  | 说明    |
| :-------- | :-------- |
| ios::beg  | 在文件开头 |
| ios::cur  | 在当前位置 |
| ios::end  | 在文件结尾 |


文件状态标志检查：

- bad() 检查文件操作是否失败；
- fail() 同 bad() 并且包括文件格式错误等，如试图读取数值时得到字符；
- eof() 检查是不否读取到了文件末尾；
- good() 一般状态检查，注意和 bad() 并不是相反关系；
- clear() 重置状态标记；


文件读写操作示范：

    #include <iostream>
    #include <fstream>

    using namespace std;

    int main () {
      ofstream myfile;
      myfile.open ("example.txt");
      myfile << "Writing this to a file.\n";
      myfile.close();
      return 0;
    }

binary 文件读取：

    #include <iostream>
    #include <fstream>
    using namespace std;

    int main () {
      streampos size;
      char * memblock;

      ifstream file ("file-binary.cpp.exe", ios::in|ios::binary|ios::ate);
      if (file.is_open())
      {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();

        cout << "the entire file content is in memory: " << size;

        delete[] memblock;
      }
      else cout << "Unable to open file";
      return 0;
    }

文本文件读写：

    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    int write (string file) {
        try
        {
            fstream myfile (file, ios::app|ios::ate);
            // myfile.open (file, ios::app);
            myfile.exceptions(myfile.failbit);
            int size = myfile.tellg();
            myfile.seekg (0, ios::beg);
            myfile << "// write comments by myself\n";
            myfile.close();
            cerr << "done!" << endl;
            return size;
        } catch (exception const& ex) {
            cerr << "Exception: " << ex.what() << endl;
            return -1;
        } catch (const std::ios_base::failure& e) {
            std::cout << "Caught an ios_base::failure.\n"
                      << "Error code: " << e.code().value() 
                      << " (" << e.code().message() << ")\n"
                      << "Error category: " << e.code().category().name() << '\n';

        }
        return 0;
    }

    int read(string file)
    {
        string line;
        ifstream myfile (file, ios::ate);
        int size = myfile.tellg();
        myfile.seekg (0, ios::beg);
        if (!myfile.is_open())
        {
            cout << "Unable to open file: " << file; 
            return 0;
        }
        while ( getline (myfile, line) )
        {
            cout << line << '\n';
        }
        myfile.close();
        return size;
    }

    int main()
    {
        string file = "../src/\tfile-text.cpp";
        cout << write(file) << endl;
        cout << read(file) << endl;
    }
