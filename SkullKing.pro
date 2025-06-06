QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    card.cpp \
    card_inheritance.cpp \
    changeinformation.cpp \
    forgotpassword.cpp \
    function.cpp \
    gameofplayer.cpp \
    gameserver.cpp \
    global.cpp \
    history.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    player.cpp \
    serverorclient.cpp \
    sign.cpp \
    signup.cpp

HEADERS += \
    board.h \
    card.h \
    card_inheritance.h \
    changeinformation.h \
    forgotpassword.h \
    function.h \
    gameofplayer.h \
    gameserver.h \
    global.h \
    history.h \
    mainwindow.h \
    menu.h \
    player.h \
    serverorclient.h \
    sign.h \
    signup.h

FORMS += \
    changeinformation.ui \
    forgotpassword.ui \
    gameserver.ui \
    history.ui \
    mainwindow.ui \
    menu.ui \
    serverorclient.ui \
    sign.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
QMAKE_CXXFLAGS+=-std=gnu++11
