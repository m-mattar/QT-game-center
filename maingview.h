#ifndef MAINGVIEW_H
#define MAINGVIEW_H

#include <QObject>
#include<QGraphicsView>

#include "accounts-and-framework/loginpage.h"
#include "accounts-and-framework/signuppage.h"
#include "accounts-and-framework/mainwindow.h"
#include "accounts-and-framework/welcomewindow.h"
#include "accounts-and-framework/json.h"

#include "game1-kill-covid-19/game1scene.h"
#include "game-2-reversi/game2scene.h"

/*
This class acts as a switch between the other scene.
*/

class MainGView : public QGraphicsView {
    Q_OBJECT
public:
    explicit MainGView();

    LoginPage * loginpage;
    SignupPage * signuppage;
    MainWindow * mainwindow;
    WelcomeWindow * welcomewindow;
    Game1scene * game1scene;
    Game2scene * game2scene;
    Json * json;

    void connectButtons();


signals:

public slots:
    void login();
    void signup();
    void gotoWelcomeWindow();
    void gotoHome();
    void playAsGuest();
    void playGame1();
    void playGame2();
};

#endif // MAINGVIEW_H
