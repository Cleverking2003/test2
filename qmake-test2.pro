TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0
CONFIG += ordered
SUBDIRS = text \
            editor \
            tests

editor.depends = text
tests.depends = text
