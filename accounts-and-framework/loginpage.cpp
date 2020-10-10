#include "loginpage.h"

LoginPage::LoginPage(QWidget *parent) : QGraphicsScene(parent) {
    int height = 800;
    int width = 400;
    this -> setSceneRect(0, 0, width, height);
    this -> setBackgroundBrush(QBrush(QImage(":/center-background.jpg"))); //.scaledToWidth(width).scaledToHeight(height)

    loginLabel = new QLabel("Login Page");
    usernameLabel = new QLabel("Username");
    passwordLabel = new QLabel("Password");
    noAccountLabel = new QLabel("Don't have an account?");

    usernameLineEdit = new QLineEdit();
    passwordLineEdit = new QLineEdit();

    loginButton = new QPushButton("Log in");
    signupButton = new QPushButton("Sign up");
    homeButton = new QPushButton("Home");

    fixLabels();
    fillScene();

    QObject::connect(loginButton, SIGNAL(clicked(bool)), this, SLOT(loginUser()));
}


/*
//////////////////////////////// METHODS ////////////////////////////////////
*/

/*
    sets the geometry of all widgets and labels.
    Adds them to the scene
*/
void LoginPage::fillScene(){
    loginLabel -> setGeometry(0, 100, 400, 30);
    loginLabel -> setAlignment(Qt::AlignCenter);

    usernameLabel -> setGeometry(100, 200, 100, 30);

    usernameLineEdit -> setGeometry(200, 200, 150, 30);
    usernameLineEdit -> setAlignment(Qt::AlignCenter);

    passwordLabel -> setGeometry(100, 250, 100, 30);

    passwordLineEdit -> setGeometry(200, 250, 150, 30);
    passwordLineEdit -> setAlignment(Qt::AlignCenter);
    passwordLineEdit ->setEchoMode(QLineEdit::Password);

    noAccountLabel -> setGeometry(100, 400, 200, 40);
    noAccountLabel -> setAlignment(Qt::AlignCenter);

    loginButton -> setGeometry(100, 300, 200, 40);
    signupButton -> setGeometry(100, 450, 200, 40);
    homeButton -> setGeometry(100, 600, 200, 40);


    this -> addWidget(loginLabel);
    this -> addWidget(usernameLabel);
    this -> addWidget(usernameLineEdit);
    this -> addWidget(passwordLabel);
    this -> addWidget(passwordLineEdit);
    this -> addWidget(noAccountLabel);
    this -> addWidget(loginButton);
    this -> addWidget(signupButton);
    this -> addWidget(homeButton);
}

/*!
    adjusts the design of the labels (color, backround, font, ...)
*/
void LoginPage::fixLabels(){
    loginLabel -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    loginLabel -> setAttribute(Qt::WA_NoSystemBackground); //no background
    loginLabel -> setStyleSheet("QLabel { font-weight: bold; color: white}");
    loginLabel -> setFont(QFont("Arial", 20));

    usernameLabel -> setWindowFlag(Qt::FramelessWindowHint);
    usernameLabel -> setAttribute(Qt::WA_NoSystemBackground);
    usernameLabel -> setStyleSheet("QLabel { color: white;}");

    passwordLabel -> setWindowFlag(Qt::FramelessWindowHint);
    passwordLabel -> setAttribute(Qt::WA_NoSystemBackground);
    passwordLabel -> setStyleSheet("QLabel { color: white;}");

    noAccountLabel -> setWindowFlag(Qt::FramelessWindowHint);
    noAccountLabel -> setAttribute(Qt::WA_NoSystemBackground);
    noAccountLabel -> setStyleSheet("QLabel { color: white;}");
}

/*
//////////////////////////////// SLOTS ////////////////////////////////////
*/

/*!
    Gets called after a user has attempted to login.
    using the json.cpp utility class:
        - loads the users.json file using json.getJsonDocument()
        - checks if the attempted login was successful using json.checkUser(usersArray,username,password)
            if successful, the curUser instance gets updated to the currently logged in user
            else, curUser becomes NULL

*/
void LoginPage::loginUser(){
    QJsonDocument jsonDocument = json.getJsonDocument();
    QJsonArray usersArray = jsonDocument.array();
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    QJsonObject userObj = json.checkUser(usersArray,username,password);
    if(userObj.empty()){
        qWarning("Username or Password Incorrect");
        curUser = NULL;
        return;
    }
    curUser = new User(userObj);
}


