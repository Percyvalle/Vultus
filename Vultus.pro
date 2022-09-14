QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

UI_DIR = .build
MOC_DIR = .build
OBJECTS_DIR = .build

include(modules/SingleApplication/singleapplication.pri)
DEFINES += QAPPLICATION_CLASS=QApplication

SOURCES += \
    src/VultusCommand.cpp \
    src/VultusRegistrationDialog.cpp \
    src/VultusResponseHandler.cpp \
    src/VultusServiceClient.cpp \
    src/main.cpp \
    src/VultusMainWindow.cpp

HEADERS += \
    src/VultusCommand.h \
    src/VultusMainWindow.h \
    src/VultusRegistrationDialog.h \
    src/VultusResponseHandler.h \
    src/VultusServiceClient.h

FORMS += \
    src/VultusMainWindow.ui \
    src/VultusRegistrationDialog.ui

RESOURCES += \
    resource.qrc

