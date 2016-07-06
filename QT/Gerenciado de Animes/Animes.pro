#-------------------------------------------------
#
# Project created by QtCreator 2016-03-24T18:19:50
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Animes
TEMPLATE = app
RC_FILE = anime.rc


SOURCES += main.cpp\
        principal.cpp \
    formulario.cpp \
    addedit.cpp \
    conexao.cpp \
    get_set.cpp \
    animedao.cpp \
    get_set2.cpp

HEADERS  += principal.h \
    formulario.h \
    addedit.h \
    conexao.h \
    get_set.h \
    animedao.h \
    get_set2.h

FORMS    += principal.ui \
    formulario.ui \
    addedit.ui

RESOURCES +=
