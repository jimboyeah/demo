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
