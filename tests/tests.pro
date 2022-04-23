include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov -L../text/ -ltext

DEFINES += INPUTDIR=\\\"$$PWD/\\\"

HEADERS += tests.h

SOURCES +=  main.cpp \
            ../editor/load.c \
            ../editor/show.c \
            ../editor/shownum.c

INCLUDEPATH += ../text

DISTFILES += input.txt
