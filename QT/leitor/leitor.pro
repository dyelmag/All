#-------------------------------------------------
#
# Project created by QtCreator 2016-06-28T10:37:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = leitor
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    addedit.cpp \
    addcap.cpp \
    get_set.cpp \
    get_set2.cpp \
    mangadao.cpp \
    conexao.cpp \
    leitor.cpp

HEADERS  += principal.h \
    addedit.h \
    addcap.h \
    get_set.h \
    get_set2.h \
    mangadao.h \
    conexao.h \
    leitor.h

FORMS    += principal.ui \
    addedit.ui \
    addcap.ui \
    leitor.ui
