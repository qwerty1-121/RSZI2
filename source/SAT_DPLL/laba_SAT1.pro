QT -= gui

CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app
TARGET = laba_SAT1

SOURCES += \
    main.cpp \
    BBV.cpp \
    boolequation.cpp \
    boolinterval.cpp \
    ../../external/Allocator/Allocator.cpp

HEADERS += \
    BBV.h \
    boolequation.h \
    boolinterval.h \
    NodeBoolTree.h \
    ../../external/Allocator/Allocator.h \
    ../../external/Allocator/DataTypes.h

INCLUDEPATH += \
    ../../external/Allocator