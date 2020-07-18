QT += widgets

HEADERS       = ../mainwindow.hpp
SOURCES       = ../qt-process.cpp \
                ../mainwindow.cpp
#! [0]
# RESOURCES     = application.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target
