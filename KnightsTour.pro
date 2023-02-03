TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/bruteforce.cpp \
    src/board.cpp \
    src/position.cpp

HEADERS += \
    src/bruteforce.h \
    src/board.h \
    src/position.h
