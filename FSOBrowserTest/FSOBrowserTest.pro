QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++17
TEMPLATE = app

INCLUDEPATH += /Users/tobiasz/Projekty/C++/FSOBrowser
SOURCES +=  \
    tst_fsobrowsertest.cpp \
    /Users/tobiasz/Projekty/C++/FSOBrowser/stringprocessor.cpp \
    /Users/tobiasz/Projekty/C++/FSOBrowser/engine.cpp
HEADERS += \
    /Users/tobiasz/Projekty/C++/FSOBrowser/stringprocessor.h \
    /Users/tobiasz/Projekty/C++/FSOBrowser/engine.h
