#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "json.h"
#include "util.h"
#include "signuppage.h"


#include<QWidget>
#include<QtWidgets>
#include<QGraphicsScene>
#include<QDebug>

#include "user.h"


/*
    This class is the scene corresponging to the login page.
    A current user can login in order to acess his saved games.
*/
class LoginPage : public QGraphicsScene {
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr);

    void fillScene();
    void fixLabels();

    Json json;
    Util util;
    User* curUser;

    //widgets

    QLabel * loginLabel;
    QLabel * usernameLabel;
    QLabel * passwordLabel;
    QLabel * noAccountLabel;


    QLineEdit * usernameLineEdit;
    QLineEdit * passwordLineEdit;

    QPushButton * loginButton;
    QPushButton * signupButton;
    QPushButton * homeButton;


signals:

public slots:
    void loginUser();
};

#endif // LOGINPAGE_H
