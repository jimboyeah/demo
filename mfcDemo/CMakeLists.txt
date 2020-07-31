cmake_minimum_required(VERSION 2.8)

# execute_process(COMMAND "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/Build/vcvars64.bat")

# set(CMAKE_C_FLAGS "/MDd")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "/EHsc" )
# set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)


# 设置 /MT 或 /MTd 进行多线程静态库链接，默认使用静态库 NAFXCW、NAFXCWD、UAFXCW、UAFXCWD、AFXNMCD、AFXNMCDD
# 设置 /MD 或 /MDd 进行多线程动态链接，结合 /D _AFXDLL 进行动态链接

# add_definitions(/D _WINDOWS /D _UNICODE /D UNICODE)
# add_definitions(/D _WINDOWS /D _MBCS)
# set(CMAKE_MFC_FLAG 1)
# add_definitions(/D_USRDLL)
# add_definitions(-D _AFXDLL)
# set(CMAKE_MFC_FLAG 2)

# SET(CMAKE_CXX_FLAGS_DEBUG "/W3 /MDd /Zl /ZI /FD /Od /D DEBUG /D WIN32 /D _DEBUG /Fp\"demo_d.pch\"")
# SET(CMAKE_CXX_FLAGS_RELEASE "/Ox /MD /Zl /Zi /W3 /O2 /D WIN32 /D NDEBUG /Fp\"demo.pch\"")

SET(CMAKE_CXX_FLAGS_DEBUG " /W3 /FD /Od /MDd")
SET(CMAKE_CXX_FLAGS_RELEASE "/W3 /Ox /O2 /MD")

# set (CMAKE_BUILD_TYPE "Release")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_EXE_LINKER_FLAGS "/machine:x64") # /out:../bin/MFCdemo_d.exe
    # set(CMAKE_EXE_LINKER_FLAGS " /NODEFAULTLIB:libcmtd.lib")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_EXE_LINKER_FLAGS "/machine:x64 /incremental:no /pdb:demo.pdb")
    # set(CMAKE_EXE_LINKER_FLAGS " /NODEFAULTLIB:libcmt.lib")
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")


set(CMAKE_C_COMPILER cl.exe)
set(CMAKE_CXX_COMPILER cl.exe)
set(CMAKE_RC_COMPILER rc.exe)


project( DEMO CXX )

# LIST(APPEND CMAKE_MODULE_PATH 
#     "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/share/cmake-3.17/Modules/" )

FIND_PACKAGE( MFC )
message(STATUS "MFC_FOUND ${MFC_FOUND}")

include_directories(
    "${PROJECT_SOURCE_DIR}/dynamicLib/"
    "C:/PROGRA~2/WI3CF2~1/10/Include/10.0.18362.0/um/"
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/atlmfc/include/"
    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/ucrt/"
    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/shared/"
    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/winrt/"
    "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.26.28801/include/"
    # "c:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/um/"
    # 'C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.26.28801/atlmfc/include/'
)
link_directories(
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/atlmfc/lib/x64/"
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/lib/x64/"
    "C:/PROGRA~2/WI3CF2~1/10/Lib/10.0.18362.0/ucrt/x64/"
    "C:/PROGRA~2/WI3CF2~1/10/Lib/10.0.18362.0/um/x64/"
)

SET(01-simple 
    # ./01-simple/src/StdAfx.h 
    ./01-simple/src/StdAfx.cpp 
    # ./01-simple/src/ChildView.h 
    ./01-simple/src/ChildView.cpp
    # ./01-simple/src/Mainfrm.h 
    ./01-simple/src/Mainfrm.cpp
    # ./01-simple/src/demo.h 
    ./01-simple/src/demo.cpp
    ./01-simple/src/AboutDialog.cpp
    # 设置资源文件
    # ./01-simple/res/resource.h 
    ./01-simple/res/demo.rc 
    ./01-simple/res/demo.ico 
    ./01-simple/res/demo.rc2
    )

# 定义 WIN32 GUI 程序目标输出，等效 /SUBSYSTEM:WINDOWS
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_executable(01-simple_d WIN32 ${01-simple})
    target_link_libraries(01-simple_d)
    target_compile_definitions(01-simple_d PUBLIC /D DEBUG /D WIN32 /D _DEBUG /D _WINDOWS /D _MBCS /D _AFXDLL)
    target_compile_options(01-simple_d PUBLIC /MDd /Fp\"demo_d.pch\")
else(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_executable(01-simple WIN32 ${01-simple})
    target_link_libraries(01-simple)
    target_compile_definitions(01-simple PUBLIC /D WIN32 /D NDEBUG /D _WINDOWS /D _MBCS /D _AFXDLL)
    target_compile_options(01-simple PUBLIC /MD /Fp\"demo.pch\" )
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

add_subdirectory(src)
add_subdirectory(dynamicLib)
