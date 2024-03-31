TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        configKey.cpp \
        lockGen.cpp \
        main.cpp \
        matrixGen.cpp

HEADERS += \
    configKey.h \
    lockGen.h \
    matrixGen.h
