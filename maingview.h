#ifndef MAINGVIEW_H
#define MAINGVIEW_H

#include <QObject>
#include<QGraphicsView>

#include "accounts-and-framework/loginpage.h"
#include "accounts-and-framework/signuppage.h"
#include "accounts-and-framework/mainwindow.h"
#include "accounts-and-framework/welcomewindow.h"

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

    void connectButtons();


signals:

public slots:
    void login();
    void signup();
    void gotoWelcomeWindow();
    void gotoHome();
    void playAsGuest();
};

#endif // MAINGVIEW_H
