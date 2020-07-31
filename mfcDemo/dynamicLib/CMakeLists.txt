cmake_minimum_required(VERSION 2.8)

# set(CMAKE_C_FLAGS "/MDd")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "/EHsc" )
# set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

SET(CMAKE_CXX_FLAGS_DEBUG "/W3 /Zl /ZI /FD /Od /MDd /D DEBUG /D _DEBUG /D WIN32 /D _WINDOWS /D _MBCS")
SET(CMAKE_CXX_FLAGS_RELEASE "/Ox /Zl /Zi /W3 /O2 /MD /D NDEBUG /D WIN32 /D _WINDOWS /D _MBCS")

# 设置 /MT 或 /MTd 进行多线程静态库链接
# 设置 /MD 或 /MDd 进行多线程动态链接

# add_definitions(/D _WINDOWS /D _UNICODE /D UNICODE)
# add_definitions(/D _WINDOWS /D _MBCS /D LIB_EXPORTS)
# 不定义 LIB_EXPORTS 会导致 DLL 项目不能准确定义导入导出符号，出现 warning C4273: dll 链接不一致

include_directories(
    "C:/PROGRA~2/WI3CF2~1/10/Include/10.0.18362.0/um/"
    )
link_directories(
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/lib/x64/"
    "C:/PROGRA~2/WI3CF2~1/10/Lib/10.0.18362.0/ucrt/x64/"
    "C:/PROGRA~2/WI3CF2~1/10/Lib/10.0.18362.0/um/x64/"
    )

# 开启 BUILD_SHARED_LIBS 等价 /LD 编译选项，/DLL 连接选项，构建 DLL 动态链接
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(CMAKE_BUILD_TYPE "Build type[Debug, Release]" "Release")
set (BUILD_SHARED_LIBS ON)
# set (CMAKE_BUILD_TYPE "Release")

message("BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS}")
message("CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
# STATIC， 代表静态链接库，编译的时候link到工程中；
# SHARED，代表动态链接库，运行时候加载；
# MODULE，是一些插件，运行时候使用dlopen-like的功能进行动态加载；
if(BUILD_SHARED_LIBS MATCHES "ON")
    set (LIB_TYPE SHARED)
else(BUILD_SHARED_LIBS MATCHES "ON")
    set (LIB_TYPE STATIC)
    set(CMAKE_POSTFIX "_static")
endif(BUILD_SHARED_LIBS MATCHES "ON")

# set(CMAKE_DEBUG_POSTFIX "_static")
# set(CMAKE_RELEASE_POSTFIX "_static")
# set_target_properties (myTarget PROPERTIES DEBUG_POSTFIX _d)
# set_property(TARGET myTarget PROPERTY DEBUG_POSTFIX _d) 

# 通过 set_target_properties 给 MSVC 编译器可以指定 /NOENTRY 创建没有入口的纯资源 DLL。
# 注意，因为是动态库，不能通过 CMAKE_EXE_LINKER_FLAGS 设置。
# 对于 DLL 工程，不需要图形界面，设置 /SUBSYSTEM:CONSOLE 程序类型。
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_EXE_LINKER_FLAGS "/machine:x64")
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_EXE_LINKER_FLAGS "/machine:x64 /incremental:no")
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

message("====> where cl.exe")
execute_process(COMMAND where cl.exe)

# set(CMAKE_CXX_COMPILER "cl.exe")
# set(CMAKE_RC_COMPILER rc.exe)

link_directories("${PROJECT_SOURCE_DIR}/lib")

project( dynamicLib CXX )

set(dynamicLib "./lib.cpp")
set(dynamicLibTest "../src/libTest.cpp")

# 定义 WIN32 GUI 程序目标输出
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(LIB_NAME "dynamicLib_d${CMAKE_POSTFIX}")
    add_library(${LIB_NAME} ${LIB_TYPE} ${dynamicLib})
    target_link_libraries(${LIB_NAME} msvcrtd msvcprtd vcruntimed ucrtd)
    set_target_properties(${LIB_NAME}
        PROPERTIES
        LINK_FLAGS /SUBSYSTEM:CONSOLE
        LINK_FLAGS /NOENTRY 
        LINK_FLAGS /DEF:"${PROJECT_SOURCE_DIR}/lib.def"
        )
    target_compile_definitions(${LIB_NAME} PUBLIC /D LIB_EXPORTS)
    # target_compile_options(${LIB_NAME} PUBLIC /MDd /W3 /Zl /ZI /FD /Od )
    add_executable(dynamicLibTest_d${CMAKE_POSTFIX} ${dynamicLibTest})
    target_link_libraries(dynamicLibTest_d${CMAKE_POSTFIX} ${LIB_NAME} msvcrtd msvcprtd vcruntimed ucrtd)
else(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(LIB_NAME "dynamicLib${CMAKE_POSTFIX}")
    add_library(${LIB_NAME} ${LIB_TYPE} ${dynamicLib})
    target_link_libraries(${LIB_NAME} msvcrt msvcprt vcruntime ucrt)
    set_target_properties(${LIB_NAME}
        PROPERTIES
        LINK_FLAGS /SUBSYSTEM:CONSOLE
        LINK_FLAGS /NOENTRY 
        LINK_FLAGS /DEF:"${PROJECT_SOURCE_DIR}/lib.def"
        )
    target_compile_definitions(${LIB_NAME} PUBLIC /D LIB_EXPORTS)
    # target_compile_options(${LIB_NAME} PUBLIC /MD /Ox /Zl /Zi /W3 /O2)
    add_executable(dynamicLibTest${CMAKE_POSTFIX} ${dynamicLibTest})
    target_link_libraries(dynamicLibTest${CMAKE_POSTFIX} ${LIB_NAME} msvcrt msvcprt vcruntime ucrt)
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

