cmake_minimum_required(VERSION 2.8)
# SET(CMAKE_C_COMPILER "c:/Qt/Tools/mingw530_32/bin/gcc.exe")
# SET(CMAKE_CXX_COMPILER "c:/Qt/Tools/mingw530_32/bin/g++.exe")

project( cppDemo )

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -Wall -O2")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -g -Wall -O2 -std=c++11")
# set(CMAKE_C_FLAGS "-std=c99 -ffunction-sections -fdata-sections")
# set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2 -s -Wl,-Map=object.map,--cref,--gc-section" )

set(BUILD_SHARED_LIBS ON)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# set(CMAKE_CXX_FLAGS "-w" )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

if (POLICY CMP0054)
    cmake_policy(SET CMP0015 NEW)
endif()

include_directories( 
    "./include/" 
    "c:/boost_1_73_0/" 
    "c:/boost_1_73_0/boost/" 
    "C:/vcpkg/installed/x64-mingw/include/"
    "C:/vcpkg/buildtrees/freetype/src/2.10.1-ea10bbeefe/src/raster/"
    )

link_directories(
    "C:/vcpkg/installed/x64-mingw/lib/"
    )

macro(AddDemo name)
    message(STATUS "AddDemo = [${name}]")
    add_executable(${name} ${ARGN})
endmacro()

message("DEMOS LIST:")
aux_source_directory("src/" src)
foreach(item ${src})
    string(REGEX REPLACE ".*/(.*)\\..*$" "\\1" name ${item})
    if(name STREQUAL "bin")
        message(STATUS "--------> use for ex stream-file.cpp canceld build ${item}")
        continue()
    endif(name STREQUAL "bin")
    AddDemo(${name} ${item})
endforeach(item)

message("BOOST DEMOS LIST:")
aux_source_directory("boost/" boost)
foreach(item ${boost})
    string(REGEX REPLACE ".*/(.*)\\..*$" "\\1" name ${item})
    AddDemo(${name} ${item})
endforeach(item)

message("Win32 DEMOS LIST:")
aux_source_directory("win32/" win32)
foreach(item ${win32})
    string(REGEX REPLACE ".*/(.*)\\..*$" "\\1" name ${item})
    if(name MATCHES "gui")
        # /SUBSYSTEM:WINDOWS
        AddDemo(${name} WIN32 ${item})
    else(name MATCHES "gui")
        # /SUBSYSTEM:CONSOLE
        AddDemo(${name} ${item})
    endif(name MATCHES "gui")
    target_link_libraries( ${name} kernel32 user32 Winmm gdi32 winspool comdlg32 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32 ws2_32)
    # set_target_properties (${name} PROPERTIES LINK_OPTIONS "LINKER:--subsystem,console")
    # target_link_options( ${name} PUBLIC LINKER:--subsystem,console)
endforeach(item)


message("Base Lib DEMOS LIST:")
aux_source_directory("base/" base)
foreach(item ${base})
    string(REGEX REPLACE ".*/(.*)\\..*$" "\\1" name ${item})
    AddDemo(${name} ${item})
    target_link_libraries( ${name} freetype png z bz2 )
endforeach(item)


# message(CHECK_START Checking)
# execute_process(COMMAND ${PROJECT_SOURCE_DIR}/bin/lambda.cpp.exe)
# message(CHECK_PASS Check End)

# add_subdirectory(QtDemos)

enable_testing()
# set(ENV{CTEST_OUTPUT_ON_FAILURE} 1)

ADD_TEST(NAME string-null-tm COMMAND string-null-tm.cpp)
SET_TESTS_PROPERTIES(string-null-tm
    PROPERTIES PASS_REGULAR_EXPRESSION 
    "Greeting message: Hello[\n\r]Shanghai")

ADD_TEST(NAME string-funcs COMMAND string-funcs.cpp)
SET_TESTS_PROPERTIES(string-funcs
    PROPERTIES PASS_REGULAR_EXPRESSION 
    # "[\n\r.]*[\n\r.]*[\n\r.]*")
    "strcpy\\( str3, str1\\) : Hello[\n\r]*strcat\\( str1, str2\\): HelloWorld[\n\r]*strlen\\(str1\\) : 10[\n\r]*")


ADD_TEST(NAME string COMMAND string.cpp)
SET_TESTS_PROPERTIES(string
    PROPERTIES PASS_REGULAR_EXPRESSION 
    # "[\n\r.]*[\n\r.]*[\n\r.]*")
    "str3 : Hello[\n\r]*str1 \\+ str2 : HelloWorld[\n\r]*str3.size\\(\\) :  10[\n\r]*")
