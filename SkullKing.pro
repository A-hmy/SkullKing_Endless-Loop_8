QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    changeinformation.cpp \
    forgotpassword.cpp \
    gameofplayer.cpp \
    gameserver.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    player.cpp \
    sign.cpp \
    signup.cpp

HEADERS += \
    card.h \
    changeinformation.h \
    forgotpassword.h \
    gameofplayer.h \
    gameserver.h \
    mainwindow.h \
    menu.h \
    player.h \
    sign.h \
    signup.h

FORMS += \
    changeinformation.ui \
    forgotpassword.ui \
    gameserver.ui \
    mainwindow.ui \
    menu.ui \
    sign.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
