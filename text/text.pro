TEMPLATE = lib

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += staticlib

SOURCES += append_line.c \
            create_text.c \
            move_crsr.c \
            move_crsr_r.c \
            process_forward.c \
            remove_all.c \
            remove_first_line.c

HEADERS += text.h
