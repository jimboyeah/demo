cmake_minimum_required(VERSION 2.8)
project( cppDemo )

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -Wall -O2")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -g -Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS "-w" )
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

if (POLICY CMP0054)
    cmake_policy(SET CMP0015 NEW)
endif()

include_directories( 
    "./include/" 
    )

# find_library(OpenGL)
FIND_PACKAGE(OpenGL REQUIRED)

macro(AddDemo name)
    message(STATUS AddDemo=${name})
    add_executable(${name} ${ARGN})
endmacro()

aux_source_directory("src/" src)
foreach(item ${src})
    string(REGEX REPLACE ".*/\(.*\)" "\\1" name ${item})
    AddDemo(${name} ${item})
endforeach(item)

enable_testing()
ADD_TEST(NAME string-null-tm COMMAND string-null-tm.cpp)
SET_TESTS_PROPERTIES(string-null-tm
    PROPERTIES PASS_REGULAR_EXPRESSION "Greeting message: Hello \nShanghai")
ADD_TEST(NAME string-funcs COMMAND string-funcs.cpp)
SET_TESTS_PROPERTIES(string-funcs
    PROPERTIES PASS_REGULAR_EXPRESSION "strcpy( str3, str1) : Hello\nstrcat( str1, str2): HelloWorld\nstrlen(str1) : 10")

