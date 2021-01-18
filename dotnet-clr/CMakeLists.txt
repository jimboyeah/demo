cmake_minimum_required(VERSION 2.8)

# execute_process(COMMAND "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/Build/vcvars64.bat")

# set(CMAKE_C_FLAGS "/MDd")
# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS" )
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(CMAKE_CXX_FLAGS_DEBUG "/W3 /FD /Od /MDd")
SET(CMAKE_CXX_FLAGS_RELEASE "/W3 /Ox /O2 /MD")

set (CMAKE_BUILD_TYPE "Release")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_EXE_LINKER_FLAGS "/machine:x64") # /out:../bin/MFCdemo_d.exe
    # set(CMAKE_EXE_LINKER_FLAGS " /NODEFAULTLIB:libcmtd.lib")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_EXE_LINKER_FLAGS "/machine:x64 /incremental:no")
    # set(CMAKE_EXE_LINKER_FLAGS " /NODEFAULTLIB:libcmt.lib")
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

set(EXECUTABLE_OUTPUT_PATH "../bin-clr")
set(LIBRARY_OUTPUT_PATH "../bin-clr")


set(CMAKE_C_COMPILER "cl.exe")
set(CMAKE_CXX_COMPILER "cl.exe")
set(CMAKE_RC_COMPILER "rc.exe")

link_directories(
    "C:/coding/md-code/cppDemos/lib/"
    )

project( clr CXX )

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(postfix "_d")
else(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(postfix "")
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

#  add_library will add /LD to CL.EXE
macro(AddLibrary name)
    set(LIBNAME ${name})
    if(${name} MATCHES "MathLibrary")
        string(REGEX REPLACE "(.+)_dll" "\\1" LIBNAME ${name})
        message(STATUS "AddLibrary = [${name}${postfix}] <===============")
        add_library("${LIBNAME}${postfix}" SHARED ${ARGN})
        target_compile_options("${LIBNAME}${postfix}" PUBLIC /c /EHsc)
        # add_custom_command(
        #     TARGET "${LIBNAME}${postfix}" POST_BUILD
        #     COMMAND lib "MathLibrary_dll.cpp.obj"
        #     )
    elseif(${name} MATCHES "_dll")
        string(REGEX REPLACE "(.+)_dll" "\\1" LIBNAME ${name})
        message(STATUS "AddLibrary = [${name}${postfix}] <=============== ${LIBNAME}.dll")
        add_library("${LIBNAME}${postfix}" SHARED ${ARGN})
        target_compile_options("${LIBNAME}${postfix}" PUBLIC /clr)
    elseif(${name} MATCHES "_nm")
        string(REGEX REPLACE "(.+)_nm" "\\1" LIBNAME ${name})
        message(STATUS "AddLibrary = [${name}${postfix}] <=============== ${LIBNAME} NO main")
        add_library("${LIBNAME}${postfix}" SHARED ${ARGN})
        target_compile_options("${LIBNAME}${postfix}" PUBLIC /clr /c)
    endif(${name} MATCHES "MathLibrary")
    # endif(${name} MATCHES "_dll")
endmacro()

macro(AddDemo name)
    if(${name} MATCHES "_zw")
        # target_compile_options("${name}${postfix}" PUBLIC /ZW)
    elseif(${name} MATCHES "_dll")
    elseif(${name} MATCHES "_nm")
    else(${name} MATCHES "_zw")
        message(STATUS "AddDemo = [${name}${postfix}]")
        add_executable("${name}${postfix}" ${ARGN})
        target_compile_options("${name}${postfix}" PUBLIC /clr)
    endif(${name} MATCHES "_zw")
endmacro()

# aux_source_directory("src/" libraries)
# foreach(item ${libraries})
#     string(REGEX REPLACE ".*/(.*)\\..*$" "\\1" name ${item})
#     AddLibrary("${name}" ${item})
# endforeach(item)

aux_source_directory("src/" demo_src)
foreach(item ${demo_src})
    string(REGEX REPLACE ".*/(.*)\\..*$" "\\1" name ${item})
    if("${item}" MATCHES "MathClient")
        continue()
    endif("${item}" MATCHES "MathClient")
    AddDemo("${name}" ${item})
endforeach(item)

add_library("MathLibrary${postfix}" STATIC "./src/MathLibrary_nm.cpp")
add_executable("MathClient${postfix}" "./src/MathClient.cpp")
target_link_libraries("MathClient${postfix}" "MathLibrary${postfix}")
add_dependencies("MathClient${postfix}" "MathLibrary${postfix}")

# add_dependencies("friend_assemblies_2${postfix}" "friend_assemblies${postfix}")


AddDemo("clr-gui" WIN32
    "../dotnet-clr/clr-gui/MyForm.cpp" 
    "../dotnet-clr/clr-gui/AppForm.resx")
AddDemo("clr-res"
    "../dotnet-clr/clr-res/clrc.cpp" 
    "../dotnet-clr/clr-res/AssemblyInfo.cpp" 
    "../dotnet-clr/clr-res/stdafx.cpp" 
    "../dotnet-clr/clr-res/app.rc" 
    "../dotnet-clr/clr-res/MyForm.cpp" 
    "../dotnet-clr/clr-res/MyForm.resx")
