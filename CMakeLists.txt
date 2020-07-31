cmake_minimum_required(VERSION 3.12)
project(petzold_pw5e C)
# set(CMAKE_VERBOSE_MAKEFILE ON)#

# NOTE:
# Microsft Visual Studio requires MFC to be installed to compile .rc resources.
#
#
set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTRICT -DCMAKE_GENERATOR_PLATFORM=x64")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_WIN32_WINNT=0x0601 -DWINVER=0x0601")

if (MSVC)
    # MSVC Compiler
else ()
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wpedantic -Wextra")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -Wpedantic -Wextra")
endif ()

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

include_directories(
    "CH04 An Exercise in Text Output/01 SysMets1"
    )
# target_include_directories(004_SysMets1 PRIVATE "CH04 An Exercise in Text Output/01 SysMets1")
# target_include_directories(004_SysMets2 PRIVATE "CH04 An Exercise in Text Output/01 SysMets1")
# target_include_directories(004_SysMets3 PRIVATE "CH04 An Exercise in Text Output/01 SysMets1")
# target_include_directories(005_1_SysMets4 PRIVATE "CH04 An Exercise in Text Output/01 SysMets1")
# target_include_directories(007_8_SysMets PRIVATE "CH04 An Exercise in Text Output/01 SysMets1")

macro(AddDemo name)
    message(STATUS "AddDemo = [${name}]")
    add_executable(${name} WIN32 ${ARGN})
endmacro()

macro(AddLibrary name)
    message(STATUS "AddLibrary = [${name}]")
    add_library(${name} SHARED ${ARGN})
endmacro()


# ================================================================== Chapter 01

AddDemo(001_HelloMsg 
        "CH01 Getting Started/01 HelloMsg/HelloMsg.c")

# ================================================================== Chapter 02

AddDemo(002_ScrnSize 
        "CH02 An Introduction to Unicode/01 ScrnSize/ScrnSize.c")

# ================================================================== Chapter 03
# winmm.lib    - required library
# HelloWin.wav - to be copied to exe directory

AddDemo(003_HelloWin 
        "CH03 Windows and Messages/01 HelloWin/HelloWin.c"
        "CH03 Windows and Messages/01 HelloWin/HelloWin.wav")
target_link_libraries(003_HelloWin winmm.lib)
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/HelloWin.wav"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH03 Windows and Messages/01 HelloWin/HelloWin.wav" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying HelloWin.wav to exe directory"
        DEPENDS "CH03 Windows and Messages/01 HelloWin/HelloWin.wav")
add_custom_target(custom_target_hello_win ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/HelloWin.wav")
add_dependencies(003_HelloWin custom_target_hello_win)

# ================================================================== Chapter 04
# -------------------------------------------------------------- 04/01 SysMets1

AddDemo(004_SysMets1 
        "CH04 An Exercise in Text Output/01 SysMets1/SysMets1.c"
        "CH04 An Exercise in Text Output/01 SysMets1/SysMets.h")

# -------------------------------------------------------------- 04/02 SysMets2
#                                                uses header file from SysMets1

AddDemo(004_SysMets2 
        "CH04 An Exercise in Text Output/02 SysMets2/SysMets2.c"
        "CH04 An Exercise in Text Output/01 SysMets1/SysMets.h")

# -------------------------------------------------------------- 04/03 SysMets3
#                                                uses header file from SysMets1

AddDemo(004_SysMets3 
        "CH04 An Exercise in Text Output/03 SysMets3/SysMets3.c"
        "CH04 An Exercise in Text Output/01 SysMets1/SysMets.h")

# ================================================================== Chapter 05

AddDemo(005_1_DevCaps1  "CH05 Basic Drawing/01 DevCaps1/DevCaps1.c")
AddDemo(005_2_SineWave  "CH05 Basic Drawing/02 SineWave/SineWave.c")
AddDemo(005_3_LineDemo  "CH05 Basic Drawing/03 LineDemo/LineDemo.c")
AddDemo(005_4_Bezier  "CH05 Basic Drawing/04 Bezier/Bezier.c")
AddDemo(005_5_AltWind  "CH05 Basic Drawing/05 AltWind/AltWind.c")
AddDemo(005_6_WhatSize  "CH05 Basic Drawing/06 WhatSize/WhatSize.c")
AddDemo(005_7_RandRect  "CH05 Basic Drawing/07 RandRect/RandRect.c")
AddDemo(005_8_Clover  "CH05 Basic Drawing/08 Clover/Clover.c")

# ================================================================== Chapter 06

AddDemo(006_1_SysMets4  "CH06 The Keyboard/01 SysMets4/SysMets4.c"
        "CH04 An Exercise in Text Output/01 SysMets1/SysMets.h")

AddDemo(006_2_KeyView1  "CH06 The Keyboard/02 KeyView1/KeyView1.c")
AddDemo(006_3_StokFont  "CH06 The Keyboard/03 StokFont/StokFont.c")
AddDemo(006_4_KeyView2  "CH06 The Keyboard/04 KeyView2/KeyView2.c")
AddDemo(006_5_Typer  "CH06 The Keyboard/05 Typer/Typer.c")

# ================================================================== Chapter 07

AddDemo(007_1_Connect  "CH07 The Mouse/01 Connect/Connect.c")
AddDemo(007_2_Checker1  "CH07 The Mouse/02 Checker1/Checker1.c")
AddDemo(007_3_Checker2  "CH07 The Mouse/03 Checker2/Checker2.c")
AddDemo(007_4_Checker3  "CH07 The Mouse/04 Checker3/Checker3.c")
AddDemo(007_5_Checker4  "CH07 The Mouse/05 Checker4/Checker4.c")
AddDemo(007_6_BlokOut1  "CH07 The Mouse/06 BlokOut1/BlokOut1.c")
AddDemo(007_7_BlokOut2  "CH07 The Mouse/07 BlockOut2/BlokOut2.c")

AddDemo(007_8_SysMets  "CH07 The Mouse/08 SysMets/SysMets.c"
        "CH04 An Exercise in Text Output/01 SysMets1/SysMets.h")

# ================================================================== Chapter 08

AddDemo(008_Beeper1  "CH08 The Timer/Beeper1.c")
AddDemo(008_Beeper2  "CH08 The Timer/Beeper2.c")
AddDemo(008_Clock  "CH08 The Timer/Clock.c")
AddDemo(008_DigClock  "CH08 The Timer/DigClock.c")
AddDemo(008_WhatClr  "CH08 The Timer/WhatClr.c")

# ================================================================== Chapter 10

AddDemo(009_BtnLook  "CH09 Child Window Controls/BtnLook/BtnLook.c")

AddDemo(009_Colors1  "CH09 Child Window Controls/Colors1/Colors1.c")
target_link_libraries(009_Colors1 Comctl32.lib)

AddDemo(009_Environ  "CH09 Child Window Controls/Environ/Environ.c")

AddDemo(009_Head  "CH09 Child Window Controls/Head/Head.c")
target_link_libraries(009_Head Comctl32.lib)

AddDemo(009_OwnDraw  "CH09 Child Window Controls/OwnDraw/OwnDraw.c")
AddDemo(009_PopPad1  "CH09 Child Window Controls/PopPad1/PopPad1.c")

# ================================================================== Chapter 10

AddDemo(010_IconDemo  "CH10 Menus and Other Resources/IconDemo/IconDemo.c"
        "CH10 Menus and Other Resources/IconDemo/Resource.h"
        "CH10 Menus and Other Resources/IconDemo/IconDemo.rc"
        "CH10 Menus and Other Resources/IconDemo/IconDemo.ico")

AddDemo(010_MenuDemo  "CH10 Menus and Other Resources/MenuDemo/MenuDemo.c"
        "CH10 Menus and Other Resources/MenuDemo/Resource.h"
        "CH10 Menus and Other Resources/MenuDemo/MenuDemo.rc")

AddDemo(010_NoPopups  "CH10 Menus and Other Resources/NoPopups/NoPopups.c"
        "CH10 Menus and Other Resources/NoPopups/Resource.h"
        "CH10 Menus and Other Resources/NoPopups/NoPopups.rc")

AddDemo(010_PopMenu  "CH10 Menus and Other Resources/PopMenu/PopMenu.c"
        "CH10 Menus and Other Resources/PopMenu/Resource.h"
        "CH10 Menus and Other Resources/PopMenu/PopMenu.rc")

AddDemo(010_PoePoem  "CH10 Menus and Other Resources/PoePoem/PoePoem.c"
        "CH10 Menus and Other Resources/PoePoem/Resource.h"
        "CH10 Menus and Other Resources/PoePoem/PoePoem.rc"
        "CH10 Menus and Other Resources/PoePoem/PoePoem.ico"
        "CH10 Menus and Other Resources/PoePoem/PoePoem.txt")

AddDemo(010_PoorMenu  "CH10 Menus and Other Resources/PoorMenu/PoorMenu.c")

AddDemo(010_PopPad2  "CH10 Menus and Other Resources/PopPad2/PopPad2.c"
        "CH10 Menus and Other Resources/PopPad2/Resource.h"
        "CH10 Menus and Other Resources/PopPad2/PopPad2.rc"
        "CH10 Menus and Other Resources/PopPad2/PopPad2.ico")

# ================================================================== Chapter 11

AddDemo(011_About1  "CH11 Dialog Boxes/About1/About1.c"
        "CH11 Dialog Boxes/About1/Resource.h"
        "CH11 Dialog Boxes/About1/About1.rc"
        "CH11 Dialog Boxes/About1/About1.ico")

AddDemo(011_About2  "CH11 Dialog Boxes/About2/About2.c"
        "CH11 Dialog Boxes/About2/Resource.h"
        "CH11 Dialog Boxes/About2/About2.rc"
        "CH11 Dialog Boxes/About2/About2.ico")

AddDemo(011_About3  "CH11 Dialog Boxes/About3/About3.c"
        "CH11 Dialog Boxes/About3/Resource.h"
        "CH11 Dialog Boxes/About3/About3.rc"
        "CH11 Dialog Boxes/About3/About3.ico")

AddDemo(011_Colors2  "CH11 Dialog Boxes/Colors2/Colors2.c"
        "CH11 Dialog Boxes/Colors2/Resource.h"
        "CH11 Dialog Boxes/Colors2/Colors2.rc")

AddDemo(011_Colors3  "CH11 Dialog Boxes/Colors3/Colors3.c"
        "CH11 Dialog Boxes/HexCalc/Resource.h"
        "CH11 Dialog Boxes/HexCalc/HexCalc.rc"
        "CH11 Dialog Boxes/HexCalc/HexCalc.dlg"
        "CH11 Dialog Boxes/HexCalc/HexCalc.ico")

AddDemo(011_HexCalc  "CH11 Dialog Boxes/HexCalc/HexCalc.c"
        "CH11 Dialog Boxes/HexCalc/Resource.h"
        "CH11 Dialog Boxes/HexCalc/HexCalc.rc"
        "CH11 Dialog Boxes/HexCalc/HexCalc.dlg"
        "CH11 Dialog Boxes/HexCalc/HexCalc.ico")

AddDemo(011_PopPad3  "CH11 Dialog Boxes/PopPad3/PopPad.c"
        "CH11 Dialog Boxes/PopPad3/PopFile.c"
        "CH11 Dialog Boxes/PopPad3/PopFind.c"
        "CH11 Dialog Boxes/PopPad3/PopFont.c"
        "CH11 Dialog Boxes/PopPad3/PopPrntNull.c"
        "CH11 Dialog Boxes/PopPad3/PopPad.h"
        "CH11 Dialog Boxes/PopPad3/Resource.h"
        "CH11 Dialog Boxes/PopPad3/PopPad.rc"
        "CH11 Dialog Boxes/PopPad3/PopPad.ico")

# ================================================================== Chapter 13

AddDemo(012_ClipText  "CH12 The Clipboard/ClipText/ClipText.c")
AddDemo(012_ClipView  "CH12 The Clipboard/ClipView/ClipView.c")

# ================================================================== Chapter 13

AddDemo(013_DevCaps2  "CH13 Using the Printer/DevCaps2/DevCaps2.c"
        "CH13 Using the Printer/DevCaps2/Resource.h"
        "CH13 Using the Printer/DevCaps2/DevCaps2.rc")

AddDemo(013_FormFeed  "CH13 Using the Printer/FormFeed/FormFeed.c"
        "CH13 Using the Printer/FormFeed/GetPrnDC.c"
        "CH13 Using the Printer/FormFeed/Print.h")

AddDemo(013_Print1  "CH13 Using the Printer/Print1/Print1.c"
        "CH13 Using the Printer/Print1/Print.c"
        "CH13 Using the Printer/FormFeed/GetPrnDC.c")


AddDemo(013_Print2  "CH13 Using the Printer/Print2/Print2.c"
        "CH13 Using the Printer/Print1/Print.c"
        "CH13 Using the Printer/FormFeed/GetPrnDC.c")

AddDemo(013_Print3  "CH13 Using the Printer/Print3/Print3.c"
        "CH13 Using the Printer/Print1/Print.c"
        "CH13 Using the Printer/FormFeed/GetPrnDC.c"
        "CH13 Using the Printer/Print3/Resource.h"
        "CH13 Using the Printer/Print3/Print.rc")

AddDemo(013_PopPrnt  "CH13 Using the Printer/PopPrnt/PopPrnt.c"
        "CH11 Dialog Boxes/PopPad3/PopPad.c"
        "CH11 Dialog Boxes/PopPad3/PopFile.c"
        "CH11 Dialog Boxes/PopPad3/PopFind.c"
        "CH11 Dialog Boxes/PopPad3/PopFont.c"
        "CH11 Dialog Boxes/PopPad3/PopPad.h"
        "CH11 Dialog Boxes/PopPad3/Resource.h"
        "CH11 Dialog Boxes/PopPad3/PopPad.rc"
        "CH11 Dialog Boxes/PopPad3/PopPad.ico")

# ================================================================== Chapter 14

AddDemo(014_BitBlt  "CH14 Bitmaps and Bitblts/BitBlt/BitBlt.c")

AddDemo(014_BitMask  "CH14 Bitmaps and Bitblts/BitMask/BitMask.c"
        "CH14 Bitmaps and Bitblts/BitMask/Resource.h"
        "CH14 Bitmaps and Bitblts/BitMask/BitMask.rc"
        "CH14 Bitmaps and Bitblts/BitMask/Matthew.bmp")

AddDemo(014_Blowup  "CH14 Bitmaps and Bitblts/Blowup/Blowup.c"
        "CH14 Bitmaps and Bitblts/Blowup/Resource.h"
        "CH14 Bitmaps and Bitblts/Blowup/Blowup.rc")

AddDemo(014_Bounce1  "CH14 Bitmaps and Bitblts/Bounce1/Bounce1.c")

AddDemo(014_Bricks1  "CH14 Bitmaps and Bitblts/Bricks1/Bricks1.c"
        "CH14 Bitmaps and Bitblts/Bricks1/Resource.h"
        "CH14 Bitmaps and Bitblts/Bricks1/Bricks1.rc"
        "CH14 Bitmaps and Bitblts/Bricks1/Bricks.bmp")

AddDemo(014_Bricks2  "CH14 Bitmaps and Bitblts/Bricks2/Bricks2.c")

# TODO: The resources for Bricks1 and Bricks3 are identical.
AddDemo(014_Bricks3  "CH14 Bitmaps and Bitblts/Bricks3/Bricks3.c"
        "CH14 Bitmaps and Bitblts/Bricks3/Resource.h"
        "CH14 Bitmaps and Bitblts/Bricks3/Bricks3.rc"
        "CH14 Bitmaps and Bitblts/Bricks3/Bricks.bmp")

AddDemo(014_GrafMenu  "CH14 Bitmaps and Bitblts/GrafMenu/GrafMenu.c"
        "CH14 Bitmaps and Bitblts/GrafMenu/Resource.h"
        "CH14 Bitmaps and Bitblts/GrafMenu/GrafMenu.rc"
        "CH14 Bitmaps and Bitblts/GrafMenu/BigHelp.bmp"
        "CH14 Bitmaps and Bitblts/GrafMenu/EditLabl.bmp"
        "CH14 Bitmaps and Bitblts/GrafMenu/FileLabl.bmp"
        "CH14 Bitmaps and Bitblts/GrafMenu/FontLabl.bmp")

AddDemo(014_HelloBit  "CH14 Bitmaps and Bitblts/HelloBit/HelloBit.c"
        "CH14 Bitmaps and Bitblts/HelloBit/Resource.h"
        "CH14 Bitmaps and Bitblts/HelloBit/HelloBit.rc")

AddDemo(014_Scramble  "CH14 Bitmaps and Bitblts/Scramble/Scramble.c")
AddDemo(014_Sketch  "CH14 Bitmaps and Bitblts/Sketch/Sketch.c")
AddDemo(014_Stretch  "CH14 Bitmaps and Bitblts/Stretch/Stretch.c")

# ================================================================== Chapter 15

set(APOLLO_DEPENDENCIES11 "CH15 The Device Independent Bitmap/Apollo11/Apollo11.bmp"
        "CH15 The Device Independent Bitmap/Apollo11/ApolloTD.bmp")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Apollo11.bmp"
        "${EXECUTABLE_OUTPUT_PATH}/ApolloTD.bmp"
        COMMAND ${CMAKE_COMMAND} -E copy ${APOLLO_DEPENDENCIES11} "${EXECUTABLE_OUTPUT_PATH}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Copying Apollo11 bmo files to exe directory"
        DEPENDS ${APOLLO_DEPENDENCIES11})
add_custom_target(custom_target_apollo11 ALL DEPENDS "${APOLLO_DEPENDENCIES11}")

AddDemo(015_Apollo11  "CH15 The Device Independent Bitmap/Apollo11/Apollo11.c"
        "CH15 The Device Independent Bitmap/ShowDib1/DibFile.c"
        "CH15 The Device Independent Bitmap/ShowDib1/DibFile.h"
        "CH15 The Device Independent Bitmap/ShowDib1/Resource.h"
        "CH15 The Device Independent Bitmap/ShowDib1/ShowDib1.rc"
        ${APOLLO_DEPENDENCIES11})
add_dependencies(015_Apollo11 custom_target_apollo11)

AddDemo(015_DibConv  "CH15 The Device Independent Bitmap/DibConv/DibConv.c"
        "CH15 The Device Independent Bitmap/DibConv/Resource.h"
        "CH15 The Device Independent Bitmap/DibConv/DibConv.rc")
add_dependencies(015_DibConv custom_target_apollo11)

AddDemo(015_DibHeads  "CH15 The Device Independent Bitmap/DibHeads/DibHeads.c"
        "CH15 The Device Independent Bitmap/DibHeads/Resource.h"
        "CH15 The Device Independent Bitmap/DibHeads/DibHeads.rc")
add_dependencies(015_DibHeads custom_target_apollo11)

AddDemo(015_DibSect  "CH15 The Device Independent Bitmap/DibSect/DibSect.c"
        "CH15 The Device Independent Bitmap/DibSect/Resource.h"
        "CH15 The Device Independent Bitmap/DibSect/DibSect.rc")
add_dependencies(015_DibSect custom_target_apollo11)

AddDemo(015_SeqDisp  "CH15 The Device Independent Bitmap/SeqDisp/SeqDisp.c"
        "CH15 The Device Independent Bitmap/SeqDisp/Resource.h"
        "CH15 The Device Independent Bitmap/SeqDisp/SeqDisp.rc")
add_dependencies(015_SeqDisp custom_target_apollo11)

AddDemo(015_ShowDib1  "CH15 The Device Independent Bitmap/ShowDib1/ShowDib1.c"
        "CH15 The Device Independent Bitmap/ShowDib1/DibFile.c"
        "CH15 The Device Independent Bitmap/ShowDib1/DibFile.h"
        "CH15 The Device Independent Bitmap/ShowDib1/Resource.h"
        "CH15 The Device Independent Bitmap/ShowDib1/ShowDib1.rc")
add_dependencies(015_ShowDib1 custom_target_apollo11)

AddDemo(015_ShowDib2  "CH15 The Device Independent Bitmap/ShowDib2/Showdib2.c"
        "CH15 The Device Independent Bitmap/ShowDib1/DibFile.c"
        "CH15 The Device Independent Bitmap/ShowDib1/DibFile.h"
        "CH15 The Device Independent Bitmap/ShowDib2/Resource.h"
        "CH15 The Device Independent Bitmap/ShowDib2/ShowDib2.rc")
add_dependencies(015_ShowDib2 custom_target_apollo11)

# ================================================================== Chapter 16

AddDemo(016_Grays1  "CH16 The Palette Manager/Grays1/Grays1.c")
AddDemo(016_Grays2  "CH16 The Palette Manager/Grays2/Grays2.c")
AddDemo(016_Grays3  "CH16 The Palette Manager/Grays3/Grays3.c")

AddDemo(016_SysPal1  "CH16 The Palette Manager/SysPal1/SysPal1.c")
AddDemo(016_SysPal2  "CH16 The Palette Manager/SysPal2/SysPal2.c")
AddDemo(016_SysPal3  "CH16 The Palette Manager/SysPal3/SysPal3.c")

AddDemo(016_Bounce  "CH16 The Palette Manager/Bounce/Bounce.c"
        "CH16 The Palette Manager/Bounce/PalAnim.c")

AddDemo(016_Fader  "CH16 The Palette Manager/Fader/Fader.c"
        "CH16 The Palette Manager/Bounce/PalAnim.c")

AddDemo(016_AllColor  "CH16 The Palette Manager/AllColor/AllColor.c"
        "CH16 The Palette Manager/Bounce/PalAnim.c")

AddDemo(016_Pipes  "CH16 The Palette Manager/Pipes/Pipes.c"
        "CH16 The Palette Manager/Bounce/PalAnim.c")

AddDemo(016_Tunnel  "CH16 The Palette Manager/Tunnel/Tunnel.c"
        "CH16 The Palette Manager/Bounce/PalAnim.c")

AddDemo(016_ShowDib3  "CH16 The Palette Manager/ShowDib3/ShowDib3.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.h"
        "CH16 The Palette Manager/ShowDib3/Resource.h"
        "CH16 The Palette Manager/ShowDib3/ShowDib3.rc")
add_dependencies(016_ShowDib3 custom_target_apollo11)

AddDemo(016_ShowDib4  "CH16 The Palette Manager/ShowDib4/ShowDib4.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.h"
        "CH16 The Palette Manager/ShowDib4/Resource.h"
        "CH16 The Palette Manager/ShowDib4/ShowDib4.rc")
add_dependencies(016_ShowDib4 custom_target_apollo11)

AddDemo(016_ShowDib5  "CH16 The Palette Manager/ShowDib5/ShowDib5.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.h"
        "CH16 The Palette Manager/ShowDib5/Resource.h"
        "CH16 The Palette Manager/ShowDib5/ShowDib5.rc")
add_dependencies(016_ShowDib5 custom_target_apollo11)

AddDemo(016_ShowDib6  "CH16 The Palette Manager/ShowDib6/ShowDib6.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.h"
        "CH16 The Palette Manager/ShowDib6/Resource.h"
        "CH16 The Palette Manager/ShowDib6/ShowDib6.rc")
add_dependencies(016_ShowDib6 custom_target_apollo11)

AddDemo(016_ShowDib7  "CH16 The Palette Manager/ShowDib7/ShowDib7.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.h"
        "CH16 The Palette Manager/ShowDib7/Resource.h"
        "CH16 The Palette Manager/ShowDib7/ShowDib7.rc")
add_dependencies(016_ShowDib7 custom_target_apollo11)

AddDemo(016_ShowDib8  "CH16 The Palette Manager/ShowDib8/ShowDib8.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.c"
        "CH16 The Palette Manager/ShowDib3/PackeDib.h"
        "CH16 The Palette Manager/ShowDib8/Resource.h"
        "CH16 The Palette Manager/ShowDib8/ShowDib8.rc")
add_dependencies(016_ShowDib8 custom_target_apollo11)

AddDemo(016_Dibble  "CH16 The Palette Manager/Dibble/Dibble.c"
        "CH16 The Palette Manager/Dibble/DibConv.c"
        "CH16 The Palette Manager/Dibble/DibConv.h"
        "CH16 The Palette Manager/Dibble/DibHelp.c"
        "CH16 The Palette Manager/Dibble/DibHelp.h"
        "CH16 The Palette Manager/Dibble/DibPal.c"
        "CH16 The Palette Manager/Dibble/DibPal.h"
        "CH16 The Palette Manager/Dibble/Resource.h"
        "CH16 The Palette Manager/Dibble/Dibble.rc")

# ================================================================== Chapter 17

AddDemo(017_PickFont  "CH17 Text and Fonts/PickFont/PickFont.c"
        "CH17 Text and Fonts/PickFont/Resource.h"
        "CH17 Text and Fonts/PickFont/PickFont.rc")

AddDemo(017_EZTest  "CH17 Text and Fonts/EZTest/EZTest.c"
        "CH17 Text and Fonts/EZTest/EZFont.c"
        "CH17 Text and Fonts/EZTest/EZFont.h"
        "CH17 Text and Fonts/EZTest/FontDemo.c"
        "CH17 Text and Fonts/EZTest/Resource.h"
        "CH17 Text and Fonts/EZTest/FontDemo.rc")

AddDemo(017_FontRot  "CH17 Text and Fonts/FontRot/FontRot.c"
        "CH17 Text and Fonts/EZTest/EZFont.c"
        "CH17 Text and Fonts/EZTest/EZFont.h"
        "CH17 Text and Fonts/EZTest/FontDemo.c"
        "CH17 Text and Fonts/EZTest/Resource.h"
        "CH17 Text and Fonts/EZTest/FontDemo.rc")

AddDemo(017_ChosFont  "CH17 Text and Fonts/ChosFont/ChosFont.c"
        "CH17 Text and Fonts/ChosFont/Resource.h"
        "CH17 Text and Fonts/ChosFont/ChosFont.rc")

AddDemo(017_Unichars  "CH17 Text and Fonts/UniChars/Unichars.c"
        "CH17 Text and Fonts/UniChars/Resource.h"
        "CH17 Text and Fonts/UniChars/Unichars.rc")

AddDemo(017_Justify1  "CH17 Text and Fonts/Justify1/Justify1.c"
        "CH17 Text and Fonts/Justify1/Resource.h"
        "CH17 Text and Fonts/Justify1/Justify1.rc")

AddDemo(017_Justify2  "CH17 Text and Fonts/Justify2/Justify2.c"
        "CH17 Text and Fonts/Justify2/Resource.h"
        "CH17 Text and Fonts/Justify2/Justify2.rc")

AddDemo(017_EndJoin  "CH17 Text and Fonts/EndJoin/EndJoin.c")

AddDemo(017_FontOut1  "CH17 Text and Fonts/FontOut1/FontOut1.c"
        "CH17 Text and Fonts/EZTest/EZFont.c"
        "CH17 Text and Fonts/EZTest/EZFont.h"
        "CH17 Text and Fonts/EZTest/FontDemo.c"
        "CH17 Text and Fonts/EZTest/Resource.h"
        "CH17 Text and Fonts/EZTest/FontDemo.rc")

AddDemo(017_FontOut2  "CH17 Text and Fonts/FontOut2/FontOut2.c"
        "CH17 Text and Fonts/EZTest/EZFont.c"
        "CH17 Text and Fonts/EZTest/EZFont.h"
        "CH17 Text and Fonts/EZTest/FontDemo.c"
        "CH17 Text and Fonts/EZTest/Resource.h"
        "CH17 Text and Fonts/EZTest/FontDemo.rc")

AddDemo(017_FontFill  "CH17 Text and Fonts/FontFill/FontFill.c"
        "CH17 Text and Fonts/EZTest/EZFont.c"
        "CH17 Text and Fonts/EZTest/EZFont.h"
        "CH17 Text and Fonts/EZTest/FontDemo.c"
        "CH17 Text and Fonts/EZTest/Resource.h"
        "CH17 Text and Fonts/EZTest/FontDemo.rc")

AddDemo(017_FontClip  "CH17 Text and Fonts/FontClip/FontClip.c"
        "CH17 Text and Fonts/EZTest/EZFont.c"
        "CH17 Text and Fonts/EZTest/EZFont.h"
        "CH17 Text and Fonts/EZTest/FontDemo.c"
        "CH17 Text and Fonts/EZTest/Resource.h"
        "CH17 Text and Fonts/EZTest/FontDemo.rc")

# ================================================================== Chapter 18

AddDemo(018_Emf01  "CH18 Metafiles/Emf01/Emf01.c")

AddDemo(018_Emf02  "CH18 Metafiles/Emf02/Emf02.c")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf02.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf02/Emf02.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf02.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf02/Emf02.emf")
add_custom_target(custom_target_emf02 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf02.emf")
add_dependencies(018_Emf02 custom_target_emf02)

AddDemo(018_Emf03  "CH18 Metafiles/Emf03/Emf03.c"
        "CH18 Metafiles/Emf03/Emf03.emf")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf03.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf03/Emf03.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf03.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf03/Emf03.emf")
add_custom_target(custom_target_emf03 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf03.emf")
add_dependencies(018_Emf03 custom_target_emf03)

AddDemo(018_Emf04  "CH18 Metafiles/Emf04/Emf04.c"
        "CH18 Metafiles/Emf04/Emf04.emf")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf04.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf04/Emf04.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf04.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf04/Emf04.emf")
add_custom_target(custom_target_emf04 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf04.emf")
add_dependencies(018_Emf04 custom_target_emf04)

AddDemo(018_Emf05  "CH18 Metafiles/Emf05/Emf05.c"
        "CH18 Metafiles/Emf03/Emf03.emf")
add_dependencies(018_Emf05 custom_target_emf03)

AddDemo(018_Emf06  "CH18 Metafiles/Emf06/Emf06.c"
        "CH18 Metafiles/Emf03/Emf03.emf")
add_dependencies(018_Emf06 custom_target_emf03)

AddDemo(018_Emf07  "CH18 Metafiles/Emf07/Emf07.c"
        "CH18 Metafiles/Emf07/Emf07.emf")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf07.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf07/Emf07.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf07.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf07/Emf07.emf")
add_custom_target(custom_target_emf07 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf07.emf")
add_dependencies(018_Emf07 custom_target_emf03 custom_target_emf07)

AddDemo(018_Emf08  "CH18 Metafiles/Emf08/Emf08.c"
        "CH18 Metafiles/Emf08/Emf.c"
        "CH18 Metafiles/Emf08/Emf.h"
        "CH18 Metafiles/Emf08/Resource.h"
        "CH18 Metafiles/Emf08/Emf.rc"
        "CH18 Metafiles/Emf08/Emf08.emf")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf08.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf08/Emf08.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf08.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf08/Emf08.emf")
add_custom_target(custom_target_emf08 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf08.emf")
add_dependencies(018_Emf08 custom_target_emf08)

AddDemo(018_Emf09  "CH18 Metafiles/Emf09/Emf09.c"
        "CH18 Metafiles/Emf08/Emf.c"
        "CH18 Metafiles/Emf08/Emf.h"
        "CH18 Metafiles/Emf08/Resource.h"
        "CH18 Metafiles/Emf08/Emf.rc"
        "CH18 Metafiles/Emf08/Emf08.emf")
add_dependencies(018_Emf09 custom_target_emf08)

AddDemo(018_Emf10  "CH18 Metafiles/Emf10/Emf10.c"
        "CH18 Metafiles/Emf08/Emf.c"
        "CH18 Metafiles/Emf08/Emf.h"
        "CH18 Metafiles/Emf08/Resource.h"
        "CH18 Metafiles/Emf08/Emf.rc"
        "CH18 Metafiles/Emf08/Emf08.emf")
add_dependencies(018_Emf10 custom_target_emf08)

AddDemo(018_Emf11  "CH18 Metafiles/Emf11/Emf11.c"
        "CH18 Metafiles/Emf11/Emf11.emf"
        "CH18 Metafiles/Emf08/Emf.c"
        "CH18 Metafiles/Emf08/Emf.h"
        "CH18 Metafiles/Emf08/Resource.h"
        "CH18 Metafiles/Emf08/Emf.rc")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf11.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf11/Emf11.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf11.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf11/Emf11.emf")
add_custom_target(custom_target_emf11 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf11.emf")
add_dependencies(018_Emf11 custom_target_emf11)

AddDemo(018_Emf12  "CH18 Metafiles/Emf12/Emf12.c"
        "CH18 Metafiles/Emf12/Emf12.emf"
        "CH18 Metafiles/Emf08/Emf.c"
        "CH18 Metafiles/Emf08/Emf.h"
        "CH18 Metafiles/Emf08/Resource.h"
        "CH18 Metafiles/Emf08/Emf.rc")
add_custom_command(
        OUTPUT "${EXECUTABLE_OUTPUT_PATH}/Emf12.emf"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/CH18 Metafiles/Emf12/Emf12.emf" "${EXECUTABLE_OUTPUT_PATH}"
        COMMENT "Copying Emf12.emf to exe directory"
        DEPENDS "CH18 Metafiles/Emf12/Emf12.emf")
add_custom_target(custom_target_emf12 ALL
        DEPENDS "${EXECUTABLE_OUTPUT_PATH}/Emf12.emf")
add_dependencies(018_Emf12 custom_target_emf12)

AddDemo(018_Emf13  "CH18 Metafiles/Emf13/Emf13.c"
        "CH18 Metafiles/Emf08/Emf.c"
        "CH18 Metafiles/Emf08/Emf.h"
        "CH18 Metafiles/Emf08/Resource.h"
        "CH18 Metafiles/Emf08/Emf.rc")
add_dependencies(018_Emf13 custom_target_emf11)

AddDemo(018_EmfView  "CH18 Metafiles/EmfView/EmfView.c"
        "CH18 Metafiles/EmfView/Resource.h"
        "CH18 Metafiles/EmfView/EmfView.rc")

AddDemo(018_Metafile  "CH18 Metafiles/MetaFile/Metafile.c")

# ================================================================== Chapter 19

AddDemo(019_MDIDemo  "CH19 The Multiple-Document Interface/MDIDemo/MDIDemo.c" 
    "CH19 The Multiple-Document Interface/MDIDemo/MDIDemo.rc")

# ================================================================== Chapter 20

AddDemo(020_BigJob1  "CH20 Multitasking and Multithreading/BigJob1/BigJob1.c")
AddDemo(020_BigJob2  "CH20 Multitasking and Multithreading/BigJob2/BigJob2.c")

AddDemo(020_Multi1  "CH20 Multitasking and Multithreading/Multi1/Multi1.c")
AddDemo(020_Multi2  "CH20 Multitasking and Multithreading/Multi2/Multi2.c")

# ================================================================== Chapter 21

AddDemo(021_RndRctMT  "CH20 Multitasking and Multithreading/RndRectMT/RndRctMT.c")
AddDemo(021_EdrTest  "CH21 Dynamic-Link Libraries/EdrTest/EdrTest.c"
        "CH21 Dynamic-Link Libraries/EdrTest/EdrLib.c")

# add_custom_target(BITLIBFILE ALL DEPENDS "${EXECUTABLE_OUTPUT_PATH}/BITLIB.lib")
add_library(BITLIB SHARED 
    "CH21 Dynamic-Link Libraries/ShowBit/BitLib.c"
    "CH21 Dynamic-Link Libraries/ShowBit/BitLib.rc")
AddDemo(021_ShowBit  "CH21 Dynamic-Link Libraries/ShowBit/ShowBit.c")
# add_dependencies(021_ShowBit BITLIBFILE)
add_dependencies(021_ShowBit BITLIB)

AddDemo(021_StrProg  "CH21 Dynamic-Link Libraries/StrProg/StrProg.c"
        "CH21 Dynamic-Link Libraries/StrProg/StrLib.c")

# ================================================================== Chapter 22

AddDemo(022_AddSynth  "CH22 Sound and Music/AddSynth/AddSynth.c"
        "CH22 Sound and Music/AddSynth/AddSynth.h"
        "CH22 Sound and Music/AddSynth/Resource.h"
        "CH22 Sound and Music/AddSynth/AddSynth.rc")
target_link_libraries(022_AddSynth winmm.lib)

AddDemo(022_BachTocc  "CH22 Sound and Music/BachTocc/BachTocc.c")
target_link_libraries(022_BachTocc winmm.lib)

AddDemo(022_Drum  "CH22 Sound and Music/Drum/Drum.c"
        "CH22 Sound and Music/Drum/DrumFile.c"
        "CH22 Sound and Music/Drum/DrumFile.h"
        "CH22 Sound and Music/Drum/DrumTime.c"
        "CH22 Sound and Music/Drum/DrumTime.h"
        "CH22 Sound and Music/Drum/Resource.h"
        "CH22 Sound and Music/Drum/Drum.ico"
        "CH22 Sound and Music/Drum/Drum.rc")
target_link_libraries(022_Drum winmm.lib)

AddDemo(022_KBMidi  "CH22 Sound and Music/KBMidi/KBMidi.c")
target_link_libraries(022_KBMidi winmm.lib)

AddDemo(022_Record1  "CH22 Sound and Music/Record1/Record1.c"
        "CH22 Sound and Music/Record1/Resource.h"
        "CH22 Sound and Music/Record1/Record.rc")
target_link_libraries(022_Record1 winmm.lib)

AddDemo(022_Record2  "CH22 Sound and Music/Record2/Record2.c"
        "CH22 Sound and Music/Record1/Resource.h"
        "CH22 Sound and Music/Record1/Record.rc")
target_link_libraries(022_Record2 winmm.lib)

AddDemo(022_Record3  "CH22 Sound and Music/Record3/Record3.c"
        "CH22 Sound and Music/Record1/Resource.h"
        "CH22 Sound and Music/Record1/Record.rc")
target_link_libraries(022_Record3 winmm.lib)

AddDemo(022_SineWaveGen  "CH22 Sound and Music/SineWaveGen/SineWaveGen.c"
        "CH22 Sound and Music/SineWaveGen/Resource.h"
        "CH22 Sound and Music/SineWaveGen/SineWaveGen.rc")
target_link_libraries(022_SineWaveGen winmm.lib)

AddDemo(022_TestMci  "CH22 Sound and Music/TextMCI/TestMci.c"
        "CH22 Sound and Music/SineWaveGen/Resource.h"
        "CH22 Sound and Music/SineWaveGen/SineWaveGen.rc")
target_link_libraries(022_TestMci winmm.lib)

AddDemo(022_WakeUp  "CH22 Sound and Music/WakeUp/WakeUp.c")
target_link_libraries(022_WakeUp winmm.lib comctl32.lib)

# ================================================================== Chapter 23

AddDemo(023_NetTime  "CH23 A Taste of the Internet/NetTime/NetTime.c"
        "CH23 A Taste of the Internet/NetTime/NetTime.rc"
        "CH23 A Taste of the Internet/NetTime/Resource.h")
target_link_libraries(023_NetTime Ws2_32.lib)

AddDemo(023_UpdDemo  "CH23 A Taste of the Internet/UpdDemo/UpdDemo.c"
        "CH23 A Taste of the Internet/UpdDemo/Resource.h"
        "CH23 A Taste of the Internet/UpdDemo/UpdDemo.rc")
target_link_libraries(023_UpdDemo Wininet.lib)

# ========================================================================= EOF