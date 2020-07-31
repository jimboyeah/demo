cmake_minimum_required(VERSION 2.8)

# set(CMAKE_C_COMPILER cl.exe)
# set(CMAKE_CXX_COMPILER cl.exe)
# set(CMAKE_RC_COMPILER rc.exe)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

project( DEMO CXX )

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
    "${PROJECT_SOURCE_DIR}/../lib/"
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/atlmfc/lib/x64/"
    "C:/PROGRA~2/MICROS~1/2019/COMMUN~1/VC/Tools/MSVC/1426~1.288/lib/x64/"
    "C:/PROGRA~2/WI3CF2~1/10/Lib/10.0.18362.0/ucrt/x64/"
    "C:/PROGRA~2/WI3CF2~1/10/Lib/10.0.18362.0/um/x64/"
)

add_executable(Test "./Test.cpp")

set (dynamicLibTest "./libTest.cpp")
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_executable(LibTest_d ${dynamicLibTest})
    target_link_libraries(LibTest_d dynamicLib_d msvcrtd)
else(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_executable(LibTest ${dynamicLibTest})
    target_link_libraries(LibTest dynamicLib msvcrt)
endif(CMAKE_BUILD_TYPE MATCHES "Debug")