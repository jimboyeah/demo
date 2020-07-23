cmake_minimum_required(VERSION 2.8)

# execute_process(COMMAND "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/Build/vcvars64.bat")

# set(CMAKE_C_FLAGS "/MDd")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "/EHsc" )
# set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS_DEBUG "/nologo /MDd /W3 /ZI /FD /Od /DEBUG /D WIN32 /D _DEBUG /D _WINDOWS /D _MBCS /D _AFXDLL /Fp\"demo_d.pch\"")
SET(CMAKE_CXX_FLAGS_RELEASE "/Ox /MD /W3 /O2 /D WIN32 /D NDEBUG /D _WINDOWS /D _AFXDLL /D _MBCS /Zi /D NDEBUG /Fp\"demo.pch\"")
set(CMAKE_DEBUG_POSTFIX "_d") 
# set(CMAKE_RELEASE_POSTFIX "_r") 

# set (CMAKE_BUILD_TYPE "Release")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    message(STATUS "CMAKE_BUILD_TYPE => ${CMAKE_BUILD_TYPE}")
    set(CMAKE_EXE_LINKER_FLAGS "/subsystem:windows /machine:x64 /out:../bin/demod.exe")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "CMAKE_BUILD_TYPE -> ${CMAKE_BUILD_TYPE}")
    set(CMAKE_EXE_LINKER_FLAGS "/subsystem:windows /incremental:no /pdb:demo.pdb /machine:x64 /out:../bin/demo.exe")
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")


set(CMAKE_C_COMPILER cl.exe)
set(CMAKE_CXX_COMPILER cl.exe)
set(CMAKE_RC_COMPILER rc.exe)


if(CMAKE_CL_64)
    message(STATUS "CMAKE_CL_64")
endif()


project( DEMO CXX )

# LIST(APPEND CMAKE_MODULE_PATH 
#     "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/share/cmake-3.17/Modules/" )

FIND_PACKAGE( MFC )
message(STATUS "MFC_FOUND ${MFC_FOUND}")

include_directories(
    "C:/PROGRA~2/WI3CF2~1/10/Include/10.0.18362.0/um/"
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/atlmfc/include/"
    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/ucrt"
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

SET(SOURCE_FILE 
    ./src/StdAfx.h ./src/StdAfx.cpp 
    ./res/resource.h 
    ./src/ChildView.h ./src/ChildView.cpp
    ./src/Mainfrm.h ./src/Mainfrm.cpp
    ./src/demo.h ./src/demo.cpp)

ADD_DEFINITIONS(-D_AFXDLL)

# 在共享库中使用MFC
SET(CMAKE_MFC_FLAG 2)

# 设置资源文件
SET(RC_FILE 
    ./res/demo.rc 
    ./res/demo.ico 
    ./res/demo.rc2)

# 定义 WIN32 GUI 程序目标输出
add_executable(MFCDemo WIN32 ${SOURCE_FILE} ${RC_FILE})
target_link_libraries(MFCDemo mfc140 atls)
