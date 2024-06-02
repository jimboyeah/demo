# set(CMAKE_CXX_COMPILER g++-13)
# set(CMAKE_C_COMPILER   gcc-13)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_CXX_STANDARD 20)
else()
    set(CMAKE_CXX_STANDARD 20)
endif()

project(hi_kernel C CXX)


add_executable(k0000 src/k0000.c)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
add_executable(k0001 src/k0001-generic-errors.c)
endif()

add_executable(g0001 src/g0001-diff-ccpp.cpp)
add_executable(g0002 src/g0002.cpp)
