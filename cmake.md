

# CMake 编译
- [CMake Tutorial – Getting Started](https://www.johnlamp.net/cmake-tutorial-1-getting-started.html)
- [CMake Manual](https://cmake.org/cmake/help/v3.18/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [User Interaction Guide](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html)
- [Using Dependencies Guide](https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html)
- [Ninja - small build system](https://ninja-build.org/)

Why CMake？

先回答上面的问题：被逼的！这三个字是认真的。

不管 CMake - Cross platform Make 是否是一个优秀的构建工具，不管你是否认同 CMake，都无法否认 CMake 目前是 C++ 的 defacto build system。

CMake 是跨平台编译工具，比 make 更为高级，通过编写 `CMakeLists.txt` 文件，然后用 cmake 命令将其转化为 make 所需要的 `makefile` 文件，最后用 `make -G` 命令生成指定编译平台的脚本或工程文件。

CMake 输入的脚本文件有两种扩展名，但有三种组织方式：

- 入口脚本 `CMakeLists.txt`，通常在项目的顶层目录，用来生成构建脚本系统，包含此脚本的子目录可以 add_subdirectory 添加；
- Scripts `<script>.cmake`，独立脚本执行简单任务并不生成构建脚本，可以使用 -P 选项传入 cmake 命令执行；
- Modules `<module>.cmake`，模块脚本，可以由独立脚本或入口脚本 include() 命令包括；

目前 CMake 已经支持 Ninja、GCC 等编译平台，同时也支持生成 Visual Studio、 Xcode、CodeBlocks、Sublime Text 等 IDE 的工程文件。支持 cmake 和 cmake-gui 两种工作方式。

来看看 CMake 命令的基本使用：

    Generate a Project Buildsystem
     cmake [<options>] <path-to-source>
     cmake [<options>] <path-to-existing-build>
     cmake [<options>] -S <path-to-source> -B <path-to-build>

    Build a Project
     cmake --build <dir> [<options>] [-- <build-tool-options>]

    Install a Project
     cmake --install <dir> [<options>]

    Open a Project
     cmake --open <dir>

    Run a Script
     cmake [{-D <var>=<value>}...] -P <cmake-script-file>

    Run a Command-Line Tool
     cmake -E <command> [<options>]

    Run the Find-Package Tool
     cmake --find-package [<options>]

试试生成 MinGW 的编译脚本，可以结合 Sublime 的构建命令使用：

    cmake path_to_cmakelists.txt -G "Sublime Text 2 - MinGW Makefiles"

生成目标的 Makefile 脚本后，可以执行命令查看 CMake 自动生成了什么目标设置：

    >make help
    The following are some of the valid targets for this Makefile:
    ... all (the default if no target is provided)
    ... clean
    ... depend
    ... edit_cache
    ... rebuild_cache
    ... freetype
    ... src/freetype.obj
    ... src/freetype.i
    ... src/freetype.s

生成目标的 Makefile 脚本后，还没有脱离 CMake 环境，执行 make 时还是需要调用 cmake 执行命令行工具，cmake_progress_start 这个命令行工具也没有文档说明，看名字应该是启动编译时初始化工作，然后才是 make 执行 CMakeFiles/Makefile2：

    # The main all target
    all: cmake_check_build_system
        $(CMAKE_COMMAND) -E cmake_progress_start freetype/build/CMakeFiles freetype/build/CMakeFiles/progress.marks
        $(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
        $(CMAKE_COMMAND) -E cmake_progress_start freetype/build/CMakeFiles 0

    # Special rule to run CMake to check the build system integrity.
    # No rule that depends on this can have commands that come from listfiles
    # because they might be regenerated.
    cmake_check_build_system:
        $(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0

CMake 提供的命名行工具还不少，例如生成摘要：

    >cmake -E sha512sum cmake_install.cmake
    de7e06db2e5a535896689db776fc72a25abf6xd...  cmake_install.cmake

目前已存在多种 Make 工具，GNU Make ，QT 的 qmake ，微软的 nmake，BSD Make，Makepp 等等。这些 Make 工具遵循着不同的规范和标准，所执行的 Makefile 格式也千差万别。如果使用上面的 Make 工具，就得为每一种标准写一次 Makefile，这将是一件让人抓狂的工作。而 CMake 就是为了解决这种工作而开发出来让人抓狂的工具！

cmake 命令提供了相关的文档，可以使用命令打印到文件中。例如，以下命令会将所有 CMake 的模块文档保存到 cmake_modules.rst 文件中：

    >cmake --help-modules cmake_modules.rst

reStructuredText 这种文件可以理解为是 Markdown 文件的精简版。

CMake 目前支持的编译系统：

- `AppleClang`: Apple Clang for Xcode versions 4.4+.
- `Clang`: Clang compiler versions 2.9+.
- `GNU`: GNU compiler versions 4.4+.
- `MSVC`: Microsoft Visual Studio versions 2010+.
- `SunPro`: Oracle SolarisStudio versions 12.4+.
- `Intel`: Intel compiler versions 12.1+.
- `NVIDIA CUDA`: NVIDIA nvcc compiler 7.5+.

对于 C/C++ 语言，可以在环境变量或 CMakeLists.txt 中指定编译器：

    export CC=/usr/bin/clang++
    export CXX=/usr/bin/clang++

    SET(CMAKE_C_COMPILER /usr/bin/gcc)
    SET(CMAKE_CXX_COMPILER /usr/bin/g++)

注意，一定要写在 project 指令之前，否则无效，并且会在生成的脚本中固定。

给链接程序设置参数使用以下格式：

    target_link_options( hello PUBLIC LINKER:--kill-at)


CMake 提供 5 个工具：

- Command-Line Tools

    - `cmake` 生成编译脚本
    - `ctest` 运行测试如 `ctest -R Qt -j8`
    - `cpack` 打包安装程序

- Interactive Dialogs

    - `cmake-gui` 图形界面的 cmake
    - `ccmake` CMake curses interface

在当前目标下执行 `cmake path_to_cmakelists_txt` 命令，就会根据指定的列表文件生成编译脚本，也可以直接在源代码目录中执行这个命令，除非列表文件指定了禁止在源目录生成。当前目录和指定的 CMakeLists.txt 所在的目录是就 path-to-build 和 path-to-source 也对应 cmake-gui 两个目录。

CMake 强大的功能按以下类别进行划分，这也是主要的学习内容：

| 命令分类  | 功能描述  |
| :-------- | :-------- |
|`cmake-buildsystem`            | 构建系统，高逻辑级别上定义构建目标，生成执行文件、库文件输出等 |
|`cmake-commands`               | 重点内容，各种命令功能支持，分成 Scripting、Project、CTest 三类 |
|`cmake-compile-features`       | 为各种编译器提供参数或设置 |
|`cmake-developer`              | CMake 扩展开发支持，如编写 Find Module 脚本 |
|`cmake-env-variables`          | 环境变量读写支持 |
|`cmake-file-api`               | 提供文件 API 访问  `<build>/.cmake/api/` |
|`cmake-generator-expressions`  | 表达式生成器，在脚本运行过程中生成个表达式的值 |
|`cmake-generators`             | CMake 生成器，即 -G 指定生成的 Makefile 类型 |
|`cmake-language`               | CMake 脚本语言 |
|`cmake-modules`                | CMake 提供了一系列的模块，如 FindPNG 找图像库，还有 FindPHP4 等等 |
|`cmake-packages`               | 依赖模块功能支持，如查找依赖模块 find_package |
|`cmake-policies`               | 考虑后向兼容，不同版本的 CMake 可按指定策略运行编译脚本 |
|`cmake-properties`             | 编译脚本属性支持，如 INCLUDE_DIRECTORIES 属性包含头文件的目录列表 |
|`cmake-qt`                     | CMake 提供 Qt 4 和 Qt 5 库支持 |
|`cmake-server`                 | cmake -E server 启动服务器模式，已弃用，由 cmake-file-api 替代 |
|`cmake-toolchains`             | 工具链接支持，如使用语言设置、平台交叉编译等 |
|`cmake-variables`              | CMake 提供的变量支持非常丰富，内置的变量按编译工具、平台等分成多类 |
|`cpack-generators`             | 打包生成器，Archive、NSIS、NuGet、RPM、WIX 等等 |


以下是和当前工程有关的变量：

    <PROJECT-NAME>_BINARY_DIR
    <PROJECT-NAME>_DESCRIPTION
    <PROJECT-NAME>_HOMEPAGE_URL
    <PROJECT-NAME>_SOURCE_DIR
    <PROJECT-NAME>_VERSION
    <PROJECT-NAME>_VERSION_MAJOR
    <PROJECT-NAME>_VERSION_MINOR
    <PROJECT-NAME>_VERSION_PATCH
    <PROJECT-NAME>_VERSION_TWEAK
    PROJECT_BINARY_DIR
    PROJECT_DESCRIPTION
    PROJECT_HOMEPAGE_URL
    PROJECT_NAME
    PROJECT_SOURCE_DIR
    PROJECT_VERSION
    PROJECT_VERSION_MAJOR
    PROJECT_VERSION_MINOR
    PROJECT_VERSION_PATCH
    PROJECT_VERSION_TWEAK

因此 CMake 的编译基本步骤如下：

- 在当前目录为 cmake 配置 CMakeLists.txt;
- 在当前目录执行 `cmake .` 命令生成 make 使用的 makefile;
- 执行 make 进行编译；


如果编译软件使用了外部库，事先并不知道它的头文件和链接库的位置。CMake 使用 `find_package` 命令来查找它们的路径，然后在编译命令中加上包含它们的路径：

    FIND_PACKAGE( <name> [version] [EXACT] [QUIET] [NO_MODULE] [ [ REQUIRED | COMPONENTS ] [ componets... ] ] )

如：

    FIND_PACKAGE( name REQUIRED)

CMake 解决项目的依赖时，会自动查找那些已知的软件通常会保存的目录路径，如果找不到再通过依赖包的  Config-file 来查找。这条命令执行后，CMake 会到变量 `CMAKE_MODULE_PATH` 指示的目录中查找文件 `Find<name>.cmake` 并执行，然后这个脚本返回 `<name>affe_FOUND`、`<name>_INCLUDE_DIRS`、`<name>_LIBRARIES` 这些变量，如查找 Caffe：

    find_package(Caffe REQUIRED)

    if (NOT Caffe_FOUND)
        message(FATAL_ERROR "Caffe Not Found!")
    endif (NOT Caffe_FOUND)

    include_directories(${Caffe_INCLUDE_DIRS})

    add_executable(demo ssd_detect.cpp)
    target_link_libraries(demo ${Caffe_LIBRARIES})

首先明确一点，cmake 本身不提供任何搜索库的便捷方法，比如下面将要提到的 FindXXX.cmake 和 XXXConfig.cmake，库的作者通常会提供这两个文件，以方便使用者调用。

find_package 采用两种模式搜索库：

- Module 模式：搜索 CMAKE_MODULE_PATH 指定路径下的 FindXXX.cmake 文件，执行该文件，由它找到 XXX 库，并赋值给 `XXX_INCLUDE_DIRS`、`XXX_LIBRARIES` 两个变量。

- Config 模式：搜索 XXX_DIR 指定路径下的 XXXConfig.cmake 文件，执行该文件从而找到 XXX 库，并给 `XXX_INCLUDE_DIRS`、`XXX_LIBRARIES` 两个变量赋值。

两种模式看起来似乎差不多，不过 cmake 默认采取 Module 模式，如果 Module 模式未找到库，才会采取 Config 模式。如果 XXX_DIR 路径下找不到 XXXConfig.cmake 文件，则会找 /usr/local/lib/cmake/XXX/ 中的 XXXConfig.cmake 文件。总之，Config 模式是一个备选策略。通常，库安装时会拷贝一份 XXXConfig.cmake 到系统目录中，因此在没有显式指定搜索路径时也可以顺利找到。

以下是一个 reStructuredText 格式展示的 Find Module 编写格式示范，具体参考 cmake-developer 文档：

    # Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
    # file Copyright.txt or https://cmake.org/licensing for details.

    #[=======================================================================[.rst:
    FindFoo
    -------

    Finds the Foo library.

    Imported Targets
    ^^^^^^^^^^^^^^^^

    This module provides the following imported targets, if found:

    ``Foo::Foo``
      The Foo library

    Result Variables
    ^^^^^^^^^^^^^^^^

    This will define the following variables:

    ``Foo_FOUND``
      True if the system has the Foo library.
    ``Foo_VERSION``
      The version of the Foo library which was found.
    ``Foo_INCLUDE_DIRS``
      Include directories needed to use Foo.
    ``Foo_LIBRARIES``
      Libraries needed to link to Foo.

    Cache Variables
    ^^^^^^^^^^^^^^^

    The following cache variables may also be set:

    ``Foo_INCLUDE_DIR``
      The directory containing ``foo.h``.
    ``Foo_LIBRARY``
      The path to the Foo library.

    #]=======================================================================]


每个构建脚本都奔构建目标来的，生成可执行文件或是类库，如果是类库，那么可以指定静态 STATIC 或动态 SHARED 等：

    add_library(archive archive.cpp zip.cpp lzma.cpp)
    add_library(archive SHARED archive.cpp zip.cpp lzma.cpp)
    add_library(archive STATIC archive.cpp zip.cpp lzma.cpp)
    add_library(archive OBJECT archive.cpp zip.cpp lzma.cpp)

    add_executable(zipapp zipapp.cpp)
    target_link_libraries(zipapp archive)

生成共享库的 add_library 命令格式如下：

    add_library(libname [SHARED|STATIC|MODULE][EXCLUDE_FROM_ALL]source1 source2 ... sourceN)

- SHARED 动态库(扩展名为.so)
- STATIC 静态库(扩展名为.a)
- MODULE 在使用 dyld 的系统有效，如果不支持 dyld，则被当作 SHARED 对待。
- EXCLUDE_FROM_ALL 参数的意思是这个库不会被默认构建，除非有其他的组件依赖或者手工构建。

CMake 会根据的生成库的设置，为编译链接程序提供和种链接方式：

    set(CMAKE_EXE_LINKER_FLAGS "-static")

| 连接方式  | 连接选项  | 优缺点   |
| 全静态   | -static -pthread -lrt -ldl    | 生成的文件比较大，没有运行依赖。|
| 全动态   | -pthread -lrt -ldl    | 生成文件最小，并且可能有依赖不兼容问题。 |
| 半静态   | -static-libgcc -L. -pthread -lrt -ldl | 灵活度大，结合了全静态与全动态两种链接方式的优点。 |


CMake 属性和命令有些名字区别不大，通常用大小写区别开来，例如以下两个属性包含的是目录列表：

- INCLUDE_DIRECTORIES 包含头文件目录列表，供预处理程序搜索头文件
- LINK_DIRECTORIES 属性包含目录列表，包含链接阶段使用的共享库、模块等

相关的命令 target_include_directories 为编译的目标提供头文件目录，指定的目标必须已经使用 `add_executable()` 或 `add_library()` 定义：

    include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])

    target_include_directories(<target> [SYSTEM] [BEFORE]
      <INTERFACE|PUBLIC|PRIVATE> [items1...]
      [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])

    target_include_directories(mylib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mylib>
        $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
    )

这个命令会将设置的目录赋值给 INCLUDE_DIRECTORIES 属性，也可以使用 set_property() 命令来设置属性。

还有两条和链接库目录有关的命令：

    link_directories([AFTER|BEFORE] directory1 [directory2 ...])

    target_link_directories(<target> [BEFORE]
      <INTERFACE|PUBLIC|PRIVATE> [items1...]
      [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])

两者的差别就在于 target_link_directories 只为指定的编译目标提供链接库目录，供链接程序查找依赖文件。

以下类似的命令用于指定链接过程使用的依赖共享库的链接，即通过导入库 `.lib` 链接到动态链接库：

    link_libraries([item1 [item2 [...]]]
                   [[debug|optimized|general] <item>] ...)
    target_link_libraries(<target> ... <item>... ...)

类似地，target 前缀的命令表示只为指定的编译目标提供链接库，而且这个目标要已经使用 `add_executable()` 或 `add_library()` 定义。

    add_executable(<name> [WIN32] [MACOSX_BUNDLE]
                   [EXCLUDE_FROM_ALL]
                   [source1] [source2 ...])

    add_library(<name> [STATIC | SHARED | MODULE]
                [EXCLUDE_FROM_ALL]
                [source1] [source2 ...])

添加库目标或可执行程序时，可以指定 IMPORTED，即工程外部的库或程序，这样不会产生一个 target rule 目标规则。

add_subdirectory 命令用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置。EXCLUDE_FROM_ALL 参数的含义是将这个目录从编译过程中排除，可能就需要工程构建完成后，再进入子目录单独进行构建，当然，你也可以通过定义依赖来解决此类问题。

    subdirs(dir1 dir2...) # Deprecated since version 3.0
    add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])

不论是 subdirs 还是 add_subdirectory 命令是否指定编译输出目录，我们都可以通过 SET 指令重新定义 `EXECUTABLE_OUTPUT_PATH` 和 `LIBRARY_OUTPUT_PATH` 变量来指定最终的目标二进制的位置：

    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

库文件或可以执行文件生成后就可以执行安装命令 `make install`，将其拷贝到 DESTINATION 指定的 bin 目录，给 CMake 定义一条 install 命令即可：

    install(TARGETS Tutorial DESTINATION bin)

install 命令用于指定在安装时运行的规则，它可以用来安装很多内容，可以包括目标二进制、动态库、静态库以及文件、目录、脚本等：

    install(TARGETS <target>... [...])
    install({FILES | PROGRAMS} <file>... [...])
    install(DIRECTORY <dir>... [...])
    install(SCRIPT <file> [...])
    install(CODE <code> [...])
    install(EXPORT <export-name> [...])

    install(TARGETS targets... [EXPORT <export-name>]
            [[ARCHIVE|LIBRARY|RUNTIME|OBJECTS|FRAMEWORK|BUNDLE|
              PRIVATE_HEADER|PUBLIC_HEADER|RESOURCE]
             [DESTINATION <dir>]
             [PERMISSIONS permissions...]
             [CONFIGURATIONS [Debug|Release|...]]
             [COMPONENT <component>]
             [NAMELINK_COMPONENT <component>]
             [OPTIONAL] [EXCLUDE_FROM_ALL]
             [NAMELINK_ONLY|NAMELINK_SKIP]
            ] [...]
            [INCLUDES DESTINATION [<dir> ...]]
            )
    
    install(<FILES|PROGRAMS> files...
            TYPE <type> | DESTINATION <dir>
            [PERMISSIONS permissions...]
            [CONFIGURATIONS [Debug|Release|...]]
            [COMPONENT <component>]
            [RENAME <name>] [OPTIONAL] [EXCLUDE_FROM_ALL])

当一个编译目标需要依赖多个源文件时，有多种方法，一个个文件罗列是最原始的：

    source_group(<name> [FILES <src>...] [REGULAR_EXPRESSION <regex>])
    source_group(TREE <root> [PREFIX <prefix>] [FILES <src>...])

    FILE (GLOB ALL_SOURCES "*.cpp" "*.c" "./AFolder/*.cpp" )
    FILE (GLOB ALL_INCLUDES "*.hpp" "*.h" "./AFolder/*.hpp"  "./AFolder/*.h" )

    SET (ALL_SRCS 
         ${ALL_SOURCES}
         ${ALL_INCLUDES}
    )


    # 查找当前目录下的所有源文件将名称保存到 ALL_SRCS 变量
    aux_source_directory(. ALL_SRCS)
    #指定生成目标
    add_executable(Demo ${ALL_SRCS})

来看看 set_property、get_property 两个命令的使用格式：

    set_property(<GLOBAL                      |
                  DIRECTORY [<dir>]           |
                  TARGET    [<target1> ...]   |
                  SOURCE    [<src1> ...]
                            [<TARGET_DIRECTORY ... | DIRECTORY ...>]   |
                  INSTALL   [<file1> ...]     |
                  TEST      [<test1> ...]     |
                  CACHE     [<entry1> ...]    >
                 [APPEND] [APPEND_STRING]
                 PROPERTY <name> [value1 ...])

    get_property(<variable>
                 <GLOBAL             |
                  DIRECTORY [<dir>]  |
                  TARGET    <target> |
                  SOURCE    <source> |
                            [<TARGET_DIRECTORY ... | DIRECTORY ...>]   |
                  INSTALL   <file>   |
                  TEST      <test>   |
                  CACHE     <entry>  |
                  VARIABLE           >
                 PROPERTY <name>
                 [SET | DEFINED | BRIEF_DOCS | FULL_DOCS])

这是两个通用方法，可以给各种对象设置属性，例如给目标对象设置属性，以下分别展示了读写 INCLUDE_DIRECTORIES 属性的两种命令，注意属性是区分大小写的：

    set_property(TARGET ${LIB_NAME} PROPERTY 
        INCLUDE_DIRECTORIES "c:/OpenCV/include c:/Qt/include")
    set_target_properties(${LIB_NAME} PROPERTIES 
        INCLUDE_DIRECTORIES "c:/OpenCV/include c:/Qt/include")

    get_property(var TARGET ${LIB_NAME} PROPERTY INCLUDE_DIRECTORIES)
    get_target_property(var ${LIB_NAME} INCLUDE_DIRECTORIES)

    message(${var})

类似的命令有以下这些：

- get_source_file_property
- get_target_property
- get_test_property
- set_source_files_properties
- set_target_properties
- set_tests_properties

CMake 与控制台交互的命令除了上面的 message 输出消息，还可以使用 execute_process 执行 shell 命令：

    execute_process(COMMAND <cmd1> [<arguments>]
                    [COMMAND <cmd2> [<arguments>]]...
                    [WORKING_DIRECTORY <directory>]
                    [TIMEOUT <seconds>]
                    [RESULT_VARIABLE <variable>]
                    [RESULTS_VARIABLE <variable>]
                    [OUTPUT_VARIABLE <variable>]
                    [ERROR_VARIABLE <variable>]
                    [INPUT_FILE <file>]
                    [OUTPUT_FILE <file>]
                    [ERROR_FILE <file>]
                    [OUTPUT_QUIET]
                    [ERROR_QUIET]
                    [COMMAND_ECHO <where>]
                    [OUTPUT_STRIP_TRAILING_WHITESPACE]
                    [ERROR_STRIP_TRAILING_WHITESPACE]
                    [ENCODING <name>]
                    [ECHO_OUTPUT_VARIABLE]
                    [ECHO_ERROR_VARIABLE])

    execute_process(COMMAND where g++ )

使用 file 命令进行文件的操作，包括上传下载：

    Reading
      file(READ <filename> <out-var> [...])
      file(STRINGS <filename> <out-var> [...])
      file(<HASH> <filename> <out-var>)
      file(TIMESTAMP <filename> <out-var> [...])
      file(GET_RUNTIME_DEPENDENCIES [...])

    Writing
      file({WRITE | APPEND} <filename> <content>...)
      file({TOUCH | TOUCH_NOCREATE} [<file>...])
      file(GENERATE OUTPUT <output-file> [...])
      file(CONFIGURE OUTPUT <output-file> CONTENT <content> [...])

    Filesystem
      file({GLOB | GLOB_RECURSE} <out-var> [...] [<globbing-expr>...])
      file(RENAME <oldname> <newname>)
      file({REMOVE | REMOVE_RECURSE } [<files>...])
      file(MAKE_DIRECTORY [<dir>...])
      file({COPY | INSTALL} <file>... DESTINATION <dir> [...])
      file(SIZE <filename> <out-var>)
      file(READ_SYMLINK <linkname> <out-var>)
      file(CREATE_LINK <original> <linkname> [...])

    Path Conversion
      file(RELATIVE_PATH <out-var> <directory> <file>)
      file({TO_CMAKE_PATH | TO_NATIVE_PATH} <path> <out-var>)

    Transfer
      file(DOWNLOAD <url> <file> [...])
      file(UPLOAD <file> <url> [...])

    Locking
      file(LOCK <path> [...])

     Archiving
       file(ARCHIVE_CREATE OUTPUT <archive> FILES <files> [...])
       file(ARCHIVE_EXTRACT INPUT <archive> DESTINATION <dir> [...])

按 CMake 教程，一般 CMakeList.txt 编写流程：

    # (Step 1) ==========================================
    # A Basic Starting Point
    # - Adding a Version Number and Configured Header File
    # - Specify the C++ Standard

    cmake_minimum_required( VERSION 2.8 )
    project(Tutorial VERSION 1.0)

    set(CMAKE_CXX_FLAGS "-std=c++11" )
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
    ​
    # (Step 2) ==========================================
    # Adding a Library

    add_library(MathFunctions mysqrt.cxx)
    # add the MathFunctions library
    add_subdirectory(MathFunctions)

    # add the executable
    add_executable(Tutorial tutorial.cxx)

    # (Step 3) ==========================================
    # Adding Usage Requirements for Library

    # target_compile_definitions()
    # target_compile_options()

    target_link_libraries(Tutorial PUBLIC MathFunctions)
    
    # add the binary tree to the search path for include files
    # so that we will find TutorialConfig.h
    target_include_directories(Tutorial PUBLIC
                              "${PROJECT_BINARY_DIR}"
                              "${PROJECT_SOURCE_DIR}/MathFunctions"
                              )

    find_package(OpenCV REQUIRED)
    # If the package has been found, several variables will
    # be set, you can find the full list with descriptions
    # in the OpenCVConfig.cmake file.
    # Print some message showing some of them
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
    
    # (Step 4) ==========================================
    # Installing and Testing
    # - Install Rules
    # - Testing Support

    install(TARGETS Tutorial DESTINATION bin)
    install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
      DESTINATION include
      )

    # (Step 5) ==========================================
    # Adding System Introspection
    # - Specify Compile Definition

    # (Step 6) ==========================================
    # Adding a Custom Command and Generated File

    add_executable(MakeTable MakeTable.cxx)
    add_custom_command(
      OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
      COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
      DEPENDS MakeTable
      )

    # (Step 7) ==========================================
    # Building an Installer

    include(InstallRequiredSystemLibraries)
    set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
    set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
    include(CPack)

    # (Step 10) ==========================================
    # Adding Generator Expressions

    add_library(tutorial_compiler_flags INTERFACE)
    target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

    set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
    set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
    target_compile_options(tutorial_compiler_flags INTERFACE
      "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
      "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
    )

    # (Step 11) ==========================================
    # Adding Export Configuration
            
    install(TARGETS MathFunctions tutorial_compiler_flags
            DESTINATION lib
            EXPORT MathFunctionsTargets)
    install(FILES MathFunctions.h DESTINATION include)

    # (Step 12) ==========================================
    # Packaging Debug and Release

    set(CMAKE_DEBUG_POSTFIX d)
    add_library(tutorial_compiler_flags INTERFACE)

    add_executable(Tutorial tutorial.cxx)
    set_target_properties(Tutorial PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

    target_link_libraries(Tutorial PUBLIC MathFunctions)

    set_property(TARGET MathFunctions PROPERTY VERSION "1.0.0")
    set_property(TARGET MathFunctions PROPERTY SOVERSION "1")


静态、动态链接混合 Mixing Static and Shared

    cmake_minimum_required(VERSION 3.10)

    # set the project name and version
    project(Tutorial VERSION 1.0)

    # specify the C++ standard
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

    # control where the static and shared libraries are built so that on windows
    # we don't need to tinker with the path to run the executable
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

    option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

    # configure a header file to pass the version number only
    configure_file(TutorialConfig.h.in TutorialConfig.h)

    # add the MathFunctions library
    add_subdirectory(MathFunctions)

    # add the executable
    add_executable(Tutorial tutorial.cxx)
    target_link_libraries(Tutorial PUBLIC MathFunctions)


实际使用中，CMake 提供丰富的功能，列如：

    include_directories(
        ${PROJECT_SOURCE_DIR}/../include/mq 
        ${PROJECT_SOURCE_DIR}/../include/incl 
        ${PROJECT_SOURCE_DIR}/../include/rapidjson
    )
    target_include_directories(${PROJECT_NAME} )

    # 它相当于 g++ -L 选项的作用，也相当于环境变量中增加 LD_LIBRARY_PATH
    link_directories(directory1 directory2 ...)
    link_directories("/home/server/third/lib")

    # 设定 SRC 变量，将源代码路径统一管理
    set(SRC 
        ${PROJECT_SOURCE_DIR}/../include/incl/a.cpp 
        ${PROJECT_SOURCE_DIR}/../include/mq/b.cpp 
        ${PROJECT_SOURCE_DIR}/c.cpp
    )
    ​
    # 创建共享库/静态库或引用库 add_library
    ​
    # 设置生成共享库的路径
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
     
    # 成的共享库文件就叫做 lib[LIB_NAME].so
    set(LIB_NAME freetype)

    add_library(${LIB_NAME} SHARED ${SRC})
    add_library(${LIB_NAME} STATIC ${SRC})

    # 把 ${LIB_NAME} 库和其它依赖的库链接起来
    # 以 libpthread.so 为例，这个命令相当 -lpthread
    target_link_libraries(${LIB_NAME} pthread more)
    
    # 可执行文件生成
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
    add_executable(${PROJECT_NAME} ${SRC})
    # 可执行文件所依赖的库
    target_link_libraries(${PROJECT_NAME} pthread more ${LIB_NAME})


访问环境变量，读取环境变量使用 $ENV{JAVA_HOME} 这样的格式，写入环境变量使用 set：

    set( ENV{PATH} /home/martink )
    
    if(NOT DEFINED ENV{JAVA_HOME})
        message(FATAL_ERROR "not defined environment variable:JAVA_HOME")  
    endif()
    #不能用 if(ENV{JAVA_HOME}) 形式来判断是否定义 
    #但可以用 if($ENV{JAVA_HOME})

总结一下，读取环境变量时用 `$ENV`，写入和判断时用 `ENV{JAVA_HOME}` 它指代变量名。


使用 C++ 11 标准，可以通过不同方式设置：

    # 设置C++标准为 C++ 11
    set(CMAKE_CXX_STANDARD 11)

    # 检查c++编译器标志，设置c++11支持变量
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

    # 使用变量设置编译标志
    if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()



## CMake Ctest
- [CppUnit 单元测试](http://sourceforge.net/projects/cppunit)

Demo目录结构如下：

    Test/
    ├── add.cpp
    └── CMakeLists.txt

add.cpp

    #include <iostream>
    #include <stdlib.h>
    int main(int argc, char *argv[])
    {
        if (argc != 3) {
            std::cout << "parameter error" << std::endl;
            return -1; 
        }   
     
        int a, b;
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        std::cout << a << " + " << b << " is " << a + b << std::endl;
        return 0;
    }

CMakeLists.txt

    CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
    ADD_EXECUTABLE(add add.cpp)
    enable_testing()
    ADD_TEST(NAME test_add_2_3 COMMAND add 2 3)
    SET_TESTS_PROPERTIES(test_add_2_3
        PROPERTIES PASS_REGULAR_EXPRESSION "5")
    ADD_TEST(NAME test_add_4_5 COMMAND add 4 5)
    SET_TESTS_PROPERTIES(test_add_4_5
        PROPERTIES PASS_REGULAR_EXPRESSION "9")

在 CMakeLists.txt 里面，我们添加了两个测试用例。其中 PASS_REGULAR_EXPRESSION 用来测试输出是否包含后面的字符串。

在 Test 目录下建立 build 目录：

    cd build && cmake .., make, make test

像上面的方式写测试用例还是比较繁琐，还可以定义宏来简化：

    CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
    ADD_EXECUTABLE(add add.cpp)
    enable_testing()
     
    macro(do_test ARG1 ARG2 RESULT)
        ADD_TEST(NAME test_add_${ARG1}_${ARG2} COMMAND add ${ARG1} ${ARG2})
        SET_TESTS_PROPERTIES(test_add_${ARG1}_${ARG2}
            PROPERTIES PASS_REGULAR_EXPRESSION ${RESULT})
    endmacro(do_test)
    do_test(2 3 5)
    do_test(4 5 9)


配合 CPPUNIT 使用如下：

    #include <cppunit/TestResult.h>
    #include <cppunit/TestResultCollector.h>
    #include <cppunit/TextOutputter.h>
    #include <cppunit/TestRunner.h>
    #include <cppunit/extensions/HelperMacros.h>
     
    class StringTest : public CppUnit::TestFixture
    {
        CPPUNIT_TEST_SUITE(StringTest);
        CPPUNIT_TEST(testSwap);
        CPPUNIT_TEST(testFind);
        CPPUNIT_TEST_SUITE_END();
    public:
        void setUp()
        {   
            m_str1 = "Hello, world";
            m_str2 = "Hi, cppunit";
        }   
        void tearDown()
        {   
     
        }   
        void testSwap()
        {   
            std::string str1 = m_str1;
            std::string str2 = m_str2;
            m_str1.swap(m_str2);
            CPPUNIT_ASSERT(m_str1 == str2);
            CPPUNIT_ASSERT(m_str2 == str2);
        }   
        void testFind()
        {   
            int pos1 = m_str1.find(',');
            int pos2 = m_str2.rfind(',');
            CPPUNIT_ASSERT_EQUAL(5, pos1);
            CPPUNIT_ASSERT_EQUAL(2, pos2);
        }   
    protected:
        std::string m_str1;
        std::string m_str2;
    };
     
    CPPUNIT_TEST_SUITE_REGISTRATION(StringTest);
    int main(int argc, char *argv[])
    {
        CppUnit::TestResult r;
        CppUnit::TestResultCollector rc;
        r.addListener(&rc);
     
        CppUnit::TestRunner runner;
        runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
        runner.run(r);
     
        CppUnit::TextOutputter o(&rc, std::cout);
        o.write();
     
        return rc.wasSuccessful()?0:-1;
    }

测试是软件开发过程中极其重要的一环，详尽周密的测试能够减少软件BUG，提高软件品质。测试包括单元测试、系统测试等。其中单元测试是指针对软件功能单元所作的测试，这里的功能单元可以是一个类的属性或者方法，测试的目的是看这些基本单元是否工作正常。由于单元测试的内容很基础，因此可以看作是测试工作的第一环，该项工作一般由开发人员自行完成。如果条件允许，单元测试代码的开发应与程序代码的开发同步进行。

虽然不同程序的单元测试代码不尽相同，但测试代码的框架却非常相似，于是便出现了一些单元测试类库，CppUnit便是其中之一。

CppUnit 是 XUnit 中的一员，XUnit 是一个大家族，还包括 JUnit 和 PythonUnit 等。CppUnit 简单实用，学习和使用起来都很方便，网上已有一些文章对其作介绍，但本文更着重于讲解其中的基本概念和使用方法，以帮助初次接触CppUnit的人员快速入门。

