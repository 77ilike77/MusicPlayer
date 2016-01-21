TEMPLATE = app

QT += qml quick widgets multimedia

SOURCES += main.cpp \
    musicplayer.cpp \
    playlistmodel.cpp \
    musicplaylistitem.cpp \
    musicplaylistmodel.cpp \
    musicanalyst.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    musicplayer.h \
    playlistmodel.h \
    musicplaylistitem.h \
    musicplaylistmodel.h \
    musicanalyst.h

