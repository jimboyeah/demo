cmake_minimum_required(VERSION 2.8)

project( dllDemo )

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -Wall -O2")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -g -Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS "-w" )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

if (POLICY CMP0054)
    cmake_policy(SET CMP0015 NEW)
endif()

include_directories( "./include/" )

# Static Libs
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
set(BUILD_SHARED_LIBS ON)

# set(ENV{PATH} C:/CodeBlocks/MinGW/bin)
# message($ENV{PATH})
# execute_process(COMMAND where g++ )
# execute_process(COMMAND where make )

aux_source_directory("src/" src)
add_library( point ${src} )

# message( ${CMAKE_INSTALL_LIBDIR} )
install(TARGETS point DESTINATION "/lib")
install(TARGETS point DESTINATION "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory(example bin EXCLUDE_FROM_ALL)
# add_subdirectory(example bin)
