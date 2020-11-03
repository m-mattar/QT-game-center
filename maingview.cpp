#include "maingview.h"

MainGView::MainGView(){
    loginpage = new LoginPage();
    signuppage = new SignupPage();
    mainwindow = new MainWindow();
    welcomewindow = new WelcomeWindow();
    game1scene = new Game1scene();
    json = new Json();

    this->setScene(mainwindow);
    connectButtons();
}

void MainGView::connectButtons(){
    QObject::connect(mainwindow->loginButton, SIGNAL(clicked(bool)), this, SLOT(login()));
    QObject::connect(mainwindow->signupButton, SIGNAL(clicked(bool)), this, SLOT(signup()));
    QObject::connect(mainwindow->guestButton, SIGNAL(clicked(bool)), this, SLOT(playAsGuest()));

    QObject::connect(signuppage->SignInButton, SIGNAL(clicked(bool)), this, SLOT(login()));
    QObject::connect(signuppage->SignUpButton, SIGNAL(clicked(bool)), this, SLOT(gotoWelcomeWindow()));

    QObject::connect(loginpage->signupButton, SIGNAL(clicked(bool)), this, SLOT(signup()));
    QObject::connect(loginpage->homeButton, SIGNAL(clicked(bool)), this, SLOT(gotoHome()));
    QObject::connect(loginpage->loginButton, SIGNAL(clicked(bool)), this, SLOT(gotoWelcomeWindow()));

    QObject::connect(welcomewindow->homeButton, SIGNAL(clicked(bool)), this, SLOT(gotoHome()));
    QObject::connect(welcomewindow->game1Button, SIGNAL(clicked(bool)), this, SLOT(playGame1()));
    QObject::connect(welcomewindow->game2Button, SIGNAL(clicked(bool)), this, SLOT(playGame2()));

    QObject::connect(game1scene->homeButton, SIGNAL(clicked(bool)), this, SLOT(gotoHome()));
}

/*
//////////////////////SLOTS//////////////////////////////
*/

/*!
 * gets called whenever switching to the login page is needed
*/
void MainGView::login(){
    signuppage->close();
    loginpage->usernameLineEdit->setText("");
    loginpage->passwordLineEdit->setText("");
    this->setScene(loginpage);
    this->show();
}

// opens a widget form to let a new user signup
void MainGView::signup(){
    this->hide();
    signuppage->cleanPage();
    signuppage->show();
}

/*!
 gets called whenever switching to the welcome window as a logged in/ signed up user is needed.
 The welcome window acts as a medium between the user and the games.
 From there he can choose which game to play, see his highscore, and the log of his last played games.
*/
void MainGView::gotoWelcomeWindow(){
    //from signup page to welcome window
    if(signuppage->curUser != NULL){ // A new user was created successfully
        signuppage->close();
        loginpage -> curUser = NULL;
        welcomewindow -> curUser = signuppage -> curUser;
        welcomewindow -> helloLabel->setText(QString("Hello " + signuppage->curUser->firstName+" "+signuppage->curUser->lastName + "!"));
        welcomewindow -> checkBday();
        welcomewindow -> updateProfilePic();
        welcomewindow->updateScores();
        this->setScene(welcomewindow);
        this->show();
    }
    //from login page to welcome window
    else if(loginpage->curUser != NULL) { // An old user was found
        signuppage -> curUser = NULL;
        welcomewindow -> curUser = loginpage -> curUser;
        welcomewindow -> helloLabel->setText(QString("Hello " + loginpage->curUser->firstName+" "+loginpage->curUser->lastName+ "!"));
        welcomewindow -> checkBday();
        welcomewindow -> updateProfilePic();
        welcomewindow-> updateScores();
        this -> setScene(welcomewindow);
        this -> show();
    }
}


/*!
Home is the main window class.
Here, a new user can be created, a current user can login, or someone can decide to play as a guest.
*/
void MainGView::gotoHome(){
    loginpage->curUser=NULL;
    signuppage->curUser=NULL;

    if(game1scene->curUser){
        json->updateUserScores(game1scene->curUser->username, game1scene->curUser->game1_scores, game1scene->curUser->game1_highest, 1);
    }

    game1scene->cleanPage();
    welcomewindow -> cleanPage();
    this->setScene(mainwindow);
    this->show();
}

/*!
 gets called whenever switching to the welcome window as a guest is needed.
*/
void MainGView::playAsGuest(){
    welcomewindow -> cleanPage();
    this -> setScene(welcomewindow);
    this -> show();
}

/*!
    - Redirects to Game1: Kill covid 19
    - SLOT is connected only to welcome page
*/
void MainGView:: playGame1(){
    game1scene -> curUser = welcomewindow -> curUser;
    if(game1scene->curUser){
        game1scene->highscore = game1scene->curUser->game1_highest;
    }

    this ->setScene(game1scene);
    this ->show();
}

/*!
    - Redirects to Game2: Reversi
    - SLOT is connected only to welcome page
*/
void MainGView:: playGame2() {

}
