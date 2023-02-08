TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/board.cpp \
    src/position.cpp \
    src/bruteforce.cpp \
    src/weighted.cpp

HEADERS += \
    src/board.h \
    src/position.h \
    src/bruteforce.h \
    src/leastMovements.h \
    src/weighted.h
