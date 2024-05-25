Getting Started Linux kernel Programming
========================================

   此代码仓库为 Linux Kernel 学习之用，Kernel 包含的代码经过数十年的积累的庞大代码库，
   学习它不必强求全面，每个人的精力有限，可以挑选此感兴趣的功能部分进行研究。这本身也不是
   简单的事，为了可以顺利进行 Kernel 功能模块的的学习，要求有一定的 C/C++ 语言基础，
   并且需要有良好的数据结构与算法基础，要熟悉各种树状数据结构的特点、优劣面，以及其常用操作。

   并且需要掌握 GCC/LLVM 等编译器的使用，编写代码的过程中，还会需要使用 GDB 等调试工具。

   LLVM 为了方便 GCC 用户迁移到 Clang，设计考虑到与 GCC 的兼容，编译驱动（Compilation Driver）
   或语言特性都有对应的参照物，以下是 LLVM 标准编译驱动名称与 GCC 对照关系：

   - ``clang`` for the ``gcc`` driver (used to compile C programs)
   - ``clang++`` for the ``gxx`` driver (used to compile C++ programs)
   - ``clang-cpp`` for the ``cpp`` driver (pure preprocessor)
   - ``clang-cl`` for the ``cl`` driver
   - ``flang`` for the ``flang`` driver
   - ``clang-dxc`` for the ``dxc`` driver

   LLVM 编译器三层架构设计中，Clang 本身工作只包括前端部分，整个编译流程包括以下主要步骤：

   - **Preprocessor**: 执行 C 语言预处理，展开 #includes 和 #defines 等宏指令。
      使用 ``Clang -E``  命令完成这个步骤就停止。
   - **Parsing**: 源代码词法解析（parses）与语法分析（semantically analyzes）。
      生成中间阶段的抽象语法树 Abstract Syntax Trees (AST)。以及，根据不同输入生成：
      precompiled header (PCH), preamble, or precompiled module file (PCM)。
      使用 ``clang -precompile``  命令完成这个步骤就停止，这是处理输入为头文件的默认行为。
   - **IR generation**: 源代码转换为中间层表示，主要是方便对代码做优化工作。对于 Clang，中间代码就是 LLVM IR。
      使用 ``clang -emit-llvm `` 命令产生中间代码，配合 -S 输出文本，否则输出字节码。
   - **Compiler backend**: 编译器后端将中间代码转换为目标机器汇编代码。
      使用 ``clang -S``  命令生成汇编代码，然后停止后续步骤。
   - **Assembler**: 汇编程序将汇编代码转换为机器码对象文件，包含特定机器可以直接执行的指令。
      使用 ``clang -c`` 生成机器码对象文件，然后停止后续步骤。
   - **Linker**: 链接程序将多个对象文件链接成为一个映像（可执行文件或者共享库）。

   如果对操作系统硬件底层有兴趣，那么法布里斯·贝拉 (Fabrice Bellard)所编写的 `QEMU <https://www.qemu.org>`__
   模拟器将是你的得力助手，底层开发者用过都说离不开它。 

   在编译代码过程中，会遇到各种各样的问题，需要尽可以地利用编译器、调试器来解决问题。比如，字符串，
   如果在代码中引用了标记为弃用的功能，将会收到警告信息，要定位警告来源，就需要利用以上的编译流程，
   通过格检查预处理生成的代码、汇编代码等等来解决问题。

   C++ 有两种字符串流（数组 I/O 流）： ``<strstream>`` 和 ``<sstream>``，它们实现的功能上基本一致。

      =======================  ======================
      strstream (char*)        sstream (std::string)
      =======================  ======================
      class strstreambuf;      class stringbuf;
      class istrstream;        class istringstream;
      class ostrstream;        class ostringstream;
      class strstream;         class stringstream;
      =======================  ======================

   它们的主要差别在于一个基于 C 类型字符串，另一个更规范地使用 std::string 实现。str() 方法
   返回的数据类型不同：

   - ostrstream::str() 返回的是 char* 类型的字符串
   - ostringstream::str() 返回的是 std::string 类型的字符串

   一般情况下编写 C++ 程序推荐使用 std::string 类型的字符串。strstream 虽仍然是 C++ 语言标准，
   但已被标记为 “deprecated”，如果引用它，编译还会给出警告信息：

   .. code-block:: bash

      $ g++ -H src/x0000-diff-ccpp.cpp
      ...
      . /usr/include/c++/9/backward/strstream
      .. /usr/include/c++/9/backward/backward_warning.h
      In file included from /usr/include/c++/9/backward/strstream:50,
                     from src/x0000-diff-ccpp.cpp:15:
      /usr/include/c++/9/backward/backward_warning.h:32:2: warning: #warning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. [-Wcpp]
      32 | #warning \
         |  ^~~~~~~

   一直以来，Kernel 代码全是纯 C 语言风格编写，因为 Linux 诞生之初 C 语言已经伴随 Unix 系统
   发展了 20 年并成为最成熟的系统开发语言。Linux 系统诞生于 1991 年芬兰，由 Linus Torvalds
   本人在一封主题为《关于我的新操作系统的小型民意调查》电邮公开其原型代码，系统借鉴 UNIX 的变体
   MINIX 系统。

   自从 Dennis 创建 C 语言，它的发展大概分为产生和繁荣两个主要历史时期：

   1969-1970 年，Tompson 在 BCPL 语言上创造 B 语言。
   1971-1977 年，Ritchie 改造 B 语言增加数据类型创造了 C 语言，伴随 Unix 产生而产生。
   1977-1979 年，C 语言伴随 Unix 移植性需求而繁荣发展。

   Ken Thompson 与 Dennis M. Ritchie 这对好基友都是图灵奖获得者。

   1979 年，本贾尼·斯特劳斯特卢普（Bjarne Stroustrup）来到 AT&T 贝尔实验室从事 C 语言改良
   工作，并给成果取名 C with classes。1983 年，该语言被正式命名为 C++。1989 年开始 C++ 
   标准化工作，并联合 ANSI 和 ISO 国际标准化组织成立标准化委员会。

   2018 年 4 月 1 日，Andrew Pinski 提议将 Linux 内核源码转为 C++，出于以下优点考虑：

   1. 内联模板函数，使得诸如 cmpxchg() 和 get_user() 这样的功能的实现更加清晰。
   2. 内联重载函数，使得诸如 static_branch_likely() 这样功能的实现更加清晰。
   3. 类继承。例如，所有那些需要包含基本 inode 结构并且必须通过更规范方式访问 inode 封装器。

   2024 年 1 月 9 日，Linux 基金会技术顾问委员会成员、长期从事 Linux 内核开发的 H. Peter Anvin
   写了一篇长长的 LKML（Linux Kernel Mailing List，Linux 内核邮件列表）帖子，其认为
   「现在是 Linux 内核从 C 语言转向 C++」的正确时机。
   
   另外还有陈述了不选用 Rust 的原因，相比之下，C++ 语法更加熟悉，而且通过一些清理，现有的 C 语言
   代码可以逐步转换为 C++。作者认为 Rust 的语法不仅不必要，而且内核开发人员需要花费大量时间来适应。

   一切事件都在运动，即使是死尸也一样，只不过它在腐败中成为其它物体的养料。新的 C++20（23）规范
   确实是主要的游戏规则改变者，从其引入模块化、协程来看，推进力量不小。还有元编程的便利性，从泛型
    (Generics)时代进化到元编程 (Metaprogramming)。

   What are you parepared to do?