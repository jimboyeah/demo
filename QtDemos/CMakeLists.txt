cmake_minimum_required(VERSION 2.8)
# SET(CMAKE_C_COMPILER "c:/Qt/Tools/mingw530_32/bin/gcc.exe")
# SET(CMAKE_CXX_COMPILER "c:/Qt/Tools/mingw530_32/bin/g++.exe")

# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOGEN ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)

project( qtDemo )

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -Wall -O2")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -g -Wall -O2 -std=c++11")
set(CMAKE_C_FLAGS "-std=c99 -ffunction-sections -fdata-sections")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wl,-Map=object.map,--cref,--gc-section" )

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
    "c:/Qt/5.9/mingw53_32/include/" 
    "c:/Qt/5.9/mingw53_32/include/QtCore/" 
    "c:/Qt/5.9/mingw53_32/include/QtGui/" 
    "c:/Qt/5.9/mingw53_32/include/QtWidgets/" 
    )

link_directories(
    "c:/Qt/5.9/mingw53_32/lib/"
    )

link_libraries(
    Qt5Core Qt5Gui Qt5Widgets Qt53DAnimation Qt53DCore Qt53DExtras Qt53DInput Qt53DLogic Qt53DQuick Qt53DQuickAnimation Qt53DQuickExtras Qt53DQuickInput Qt53DQuickRender Qt53DQuickScene2D Qt53DRender Qt5AccessibilitySupport Qt5AxBase Qt5AxContainer Qt5AxServer Qt5Bluetooth Qt5Bootstrap Qt5Charts Qt5Concurrent Qt5DataVisualization Qt5DBus Qt5Designer Qt5DesignerComponents Qt5DeviceDiscoverySupport Qt5DeviceDiscoverySupport Qt5EglSupport Qt5EventDispatcherSupport Qt5EventDispatcherSupport Qt5FbSupport Qt5FontDatabaseSupport Qt5Help Qt5Location Qt5Multimedia Qt5MultimediaQuick_p Qt5MultimediaWidgets Qt5Network Qt5NetworkAuth Qt5Nfc Qt5OpenGL Qt5OpenGLExtensions Qt5PacketProtocol Qt5Positioning Qt5PrintSupport Qt5Purchasing Qt5Qml Qt5QmlDebug Qt5QmlDevTools Qt5Quick Qt5QuickControls2 Qt5QuickParticles Qt5QuickTemplates2 Qt5QuickTest Qt5QuickWidgets Qt5RemoteObjects Qt5Script Qt5ScriptTools Qt5Scxml Qt5Sensors Qt5SerialBus Qt5SerialPort Qt5Sql Qt5Svg Qt5Test Qt5TextToSpeech Qt5ThemeSupport Qt5UiTools Qt5WebChannel Qt5WebSockets Qt5WinExtras Qt5Xml Qt5XmlPatterns qtfreetype qtlibpng qtmain)

macro(AddQtDemo name)
    message(STATUS AddQtDemo=${name})
    add_executable(${name} ${ARGN})
endmacro()

message("Qt DEMOS LIST:")
aux_source_directory("src/" qtsrc)
foreach(item ${qtsrc})
    string(REGEX REPLACE ".*/\(.*\)\\..*" "\\1" name ${item})
    if(name STREQUAL "mainwindow")
        continue()
    endif(name STREQUAL "mainwindow")
    if(name STREQUAL "qt-process")
        # AddQtDemo(${name} ${item}  "${PROJECT_SOURCE_DIR}/src/mainwindow.cpp")
        continue()
    endif(name STREQUAL "qt-process")
    AddQtDemo(${name} ${item})
endforeach(item)

