TEMPLATE = app

CONFIG += c++11

QT += qml quick

LIBS += -lnanomsg
LIBS += -lmsgpack

SOURCES += main.cpp \
    comm.cpp \
    qtqml.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    comm.h \
    msgevent.h \
    qtqml.h
