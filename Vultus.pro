QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

UI_DIR = .build
MOC_DIR = .build
OBJECTS_DIR = .build

SOURCES += \
    src/VultusServiceClient.cpp \
    src/main.cpp \
    src/VultusMainWindow.cpp

HEADERS += \
    src/VultusMainWindow.h \
    src/VultusServiceClient.h

FORMS += \
    src/VultusMainWindow.ui

RESOURCES += \
    resource.qrc

