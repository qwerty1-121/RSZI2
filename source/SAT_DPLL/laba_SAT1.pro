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
    NodeBoolTree.cpp \
    ../../external/Allocator/Allocator.cpp \
    allocator_experiment/AllocatorTestObject.cpp \
    allocator_experiment/AllocatorExperiment.cpp \
    variable_selection/FirstVariableSelector.cpp \
    variable_selection/MinUndefinedSelector.cpp

HEADERS += \
    BBV.h \
    boolequation.h \
    boolinterval.h \
    NodeBoolTree.h \
    ../../external/Allocator/Allocator.h \
    ../../external/Allocator/DataTypes.h \
    allocator_experiment/AllocatorTestObject.h \
    allocator_experiment/AllocatorExperiment.h \
    variable_selection/IVariableSelector.h \
    variable_selection/FirstVariableSelector.h \
    variable_selection/MinUndefinedSelector.h

INCLUDEPATH += \
    ../../external/Allocator \
    allocator_experiment \
    variable_selection