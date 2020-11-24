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
    game-2-reversi/board.cpp \
    game-2-reversi/disk.cpp \
    game-2-reversi/game2scene.cpp \
    game-2-reversi/line.cpp \
    game-2-reversi/point.cpp \
    game-2-reversi/strategy.cpp \
    game1-kill-covid-19/arrow.cpp \
    game1-kill-covid-19/game1scene.cpp \
    game1-kill-covid-19/rollingbg.cpp \
    game1-kill-covid-19/syringe.cpp \
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
    game-2-reversi/board.h \
    game-2-reversi/disk.h \
    game-2-reversi/game2scene.h \
    game-2-reversi/line.h \
    game-2-reversi/point.h \
    game-2-reversi/strategy.h \
    game1-kill-covid-19/arrow.h \
    game1-kill-covid-19/game1scene.h \
    game1-kill-covid-19/rollingbg.h \
    game1-kill-covid-19/syringe.h \
    game1-kill-covid-19/viruslarge.h \
    maingview.h \

DISTFILES += \
    JSON/jokes.json \
    JSON/users.json \
    ../../Profile.png \
    README.md \
    Sounds/music.mp3 \
    images/center-background.jpg \
    images/game1icon.jpeg \
    images/game1images/arrow.png \
    images/game1images/bright-lavender-background.jpg \
    images/game1images/game1Name.png \
    images/game1images/gameOver.png \
    images/game1images/gameWon.png \
    images/game1images/half-circle.png \
    images/game1images/mike.png \
    images/game1images/syringe.png \
    images/game1images/vessel.png \
    images/game1images/virus-green.png \
    images/game1images/virus-pink.png \
    images/game1images/virus-purple.png \
    images/game1images/white-blood-cell.png \
    images/game2icon.jpeg \
    images/game2images/BlackChip.png \
    images/game2images/BlackDisk.png \
    images/game2images/BlankChip.png \
    images/game2images/BlankDisk.png \
    images/game2images/Board.png \
    images/game2images/ReversiName.png \
    images/game2images/WhiteDisk.png \
    images/game2images/gamename.jpeg \
    images/main-background.jpg \
    images/red-background.jpg

RESOURCES += \
    images/images.qrc \
    images/images.qrc \
    images/images.qrc \
    res.qrc \
    res.qrc
