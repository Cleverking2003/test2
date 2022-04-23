TEMPLATE = lib

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += staticlib

QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage

SOURCES += append_line.c \
            create_text.c \
            move_crsr.c \
            move_crsr_r.c \
            process_forward.c \
            remove_all.c \
            remove_first_line.c

LIBS += -lgcov

HEADERS += text.h
