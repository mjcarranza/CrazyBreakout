QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ball.cpp \
    Client.cpp \
    Commonblk.cpp \
    Deepblk.cpp \
    Doubleblk.cpp \
    Game.cpp \
    Internblk.cpp \
    Paddle.cpp \
    Tripleblk.cpp \
    gameover.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Ball.h \
    Client.h \
    Commonblk.h \
    Deepblk.h \
    Doubleblk.h \
    Game.h \
    Internblk.h \
    Paddle.h \
    Tripleblk.h \
    gameover.h \
    mainwindow.h

FORMS += \
    gameover.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
