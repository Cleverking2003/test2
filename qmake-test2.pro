TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

CONFIG += ordered
SUBDIRS = text \
            editor \
            tests

editor.depends = text
tests.depends = text
