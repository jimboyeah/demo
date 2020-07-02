cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
# find_package( OpenCV REQUIRED )

set(CMAKE_C_FLAGS "-std=c99")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
# set(CMAKE_CXX_FLAGS "-std=c++11" )
# set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory("src/" src)

include_directories(
    # "C:/CodeBlocks/MinGW/freeglut/include"
    # "C:/CodeBlocks/MinGW/freeglut/include/GL"

    "C:/download/OpenCV/redbook"
    "C:/download/OpenCV/freeglut-3.2.1/include/"
    "C:/download/OpenCV/freeglut-3.2.1/include/GL/"

    "C:/download/OpenCV/glfw-3.3.2/deps/"
    "C:/download/OpenCV/glfw-3.3.2/include/"
    "C:/download/OpenCV/glfw-3.3.2.bin.WIN64/include/"
    
    "C:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/include/"
    "C:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/include/opencv2/"
)
link_directories(
    # "C:/CodeBlocks/MinGW/freeglut/lib/x64"
    # "C:/download/OpenCV/freeglut/lib/x64"
    "C:/download/OpenCV/freeglut-3.2.1/build/lib/"

    # "C:/download/OpenCV/glfw-3.3.2/build/src/"
    "C:/download/OpenCV/glfw-3.3.2.bin.WIN64/lib-mingw-w64/"

    "C:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/x64/mingw/lib/"
    # "c:/download/OpenCV/opencv/build/x64/vc15/lib/"
    # "c:/download/OpenCV/opencv/build/x64/static/"
)

# set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
# Static Libs
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
# set(BUILD_SHARED_LIBS OFF)

set(ENV{PATH} C:/CodeBlocks/MinGW/bin)
message($ENV{PATH})
execute_process(COMMAND where g++ )
execute_process(COMMAND where make )

set(OpenGL_LIBS 
    # glut
    # glut32
    # freeglut
    glu32
    opengl32
    winmm
    freeglut
    # freeglut_static
    glfw3dll
    glfw3
)

set(OpenCV_LIBS 
    opencv_calib3d411
    opencv_core411
    opencv_dnn411
    opencv_features2d411
    opencv_flann411
    opencv_gapi411
    opencv_highgui411
    opencv_imgcodecs411
    opencv_imgproc411
    opencv_ml411
    opencv_objdetect411
    opencv_photo411
    opencv_stitching411
    opencv_video411
    opencv_videoio411
)
link_libraries( ${OpenCV_LIBS} )

add_executable( DisplayImage src/display.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

# add_executable( freetype src/freetype.cpp )
# target_link_libraries( freetype ${OpenCV_LIBS} )

add_executable( random_point src/random_point.cpp )
target_link_libraries( random_point ${OpenCV_LIBS} )


add_executable( glutDemo src/glutDemo.cpp )
target_link_libraries( glutDemo ${OpenGL_LIBS} )

add_executable( reflection src/gl-reflection.cpp )
target_link_libraries( reflection ${OpenGL_LIBS} )

add_executable( teapot src/teapot.cpp )
target_link_libraries( teapot ${OpenGL_LIBS} )


add_executable( double src/double.c )
target_link_libraries( double ${OpenGL_LIBS} )



add_executable( accanti C:/download/OpenCV/redbook/accanti.c )
target_link_libraries( accanti ${OpenGL_LIBS} )

add_executable( simple 
    "C:/download/OpenCV/glfw-3.3.2/examples/simple.c"
    "C:/download/OpenCV/glfw-3.3.2/deps/glad_gl.c"
    )
target_link_libraries( simple ${OpenGL_LIBS} )


add_executable( glfwDemo 
    src/glfwDemo.cpp
    "C:/download/OpenCV/glfw-3.3.2/deps/glad_gl.c"
    )
target_link_libraries( glfwDemo ${OpenGL_LIBS} )


