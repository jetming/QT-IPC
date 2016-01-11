QT += core
QT -= gui
QT += network

TARGET = ipc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ipcmsghandler.cpp \
    signalforward.cpp \
    sigtest.cpp \
    IPC/ihandlemsg.cpp \
    IPC/ipcclient.cpp \
    IPC/ipcserver.cpp

HEADERS += \
    ipcmsghandler.h \
    signalforward.h \
    sigtest.h \
    IPC/ihandlemsg.h \
    IPC/ipcclient.h \
    IPC/ipcserver.h

