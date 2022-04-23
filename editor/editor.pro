TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage

SOURCES = editor.c \
            load.c \
            save.c \
            show.c \
            shownum.c

INCLUDEPATH += ../text

HEADERS = common.h

LIBS += -L../text -ltext -lgcov
TARGET = editor
