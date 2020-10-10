QT += widgets
QT += core gui
QT += multimedia

SOURCES += \
    accounts-and-framework/json.cpp \
    accounts-and-framework/loginpage.cpp \
    accounts-and-framework/mainwindow.cpp \
    accounts-and-framework/signuppage.cpp \
    accounts-and-framework/user.cpp \
    accounts-and-framework/util.cpp \
    accounts-and-framework/welcomewindow.cpp \
    game1-kill-covid-19/game1scene.cpp \
    game1-kill-covid-19/rollingbg.cpp \
    game1-kill-covid-19/viruslarge.cpp \
    main.cpp \
    maingview.cpp \

HEADERS += \
    accounts-and-framework/json.h \
    accounts-and-framework/loginpage.h \
    accounts-and-framework/mainwindow.h \
    accounts-and-framework/signuppage.h \
    accounts-and-framework/user.h \
    accounts-and-framework/util.h \
    accounts-and-framework/welcomewindow.h \
    game1-kill-covid-19/game1scene.h \
    game1-kill-covid-19/rollingbg.h \
    game1-kill-covid-19/viruslarge.h \
    maingview.h \

DISTFILES += \
    JSON/jokes.json \
    JSON/users.json \
    ../../Profile.png \
    images/center-background.jpg \
    images/main-background.jpg

RESOURCES += \
    images/images.qrc \
    images/images.qrc \
    res.qrc
