QT       += core gui
QT       += core gui multimedia
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    main.cpp \
    mainscreen.cpp \
    mainscreen_second.cpp \
    monster.cpp \
    none.cpp \
    player.cpp \
    widget.cpp \
    dialog.cpp \
    firstwin.cpp \
    goldbuy.cpp \
    youlose.cpp \
    lastwin.cpp \
    monster_bullet.cpp \
    bullet.cpp \
    audiothread.cpp

HEADERS += \
    background.h \
    config.h \
    mainscreen.h \
    mainscreen_second.h \
    monster.h \
    none.h \
    player.h \
    widget.h \
    dialog.h \
    firstwin.h \
    goldbuy.h \
    youlose.h \
    lastwin.h \
    monster_bullet.h \
    bullet.h \
    audiothread.h

FORMS += \
    mainscreen.ui \
    mainscreen_second.ui \
    none.ui \
    widget.ui \
    dialog.ui \
    firstwin.ui \
    goldbuy.ui \
    youlose.ui \
    lastwin.ui

TRANSLATIONS += \
    qtgame_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
CONFIG += resources_big
