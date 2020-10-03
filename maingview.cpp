#include "maingview.h"

MainGView::MainGView(){
    loginpage = new LoginPage();
    signuppage = new SignupPage();
    mainwindow = new MainWindow();
    welcomewindow = new WelcomeWindow();

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
}

/*
//////////////////////SLOTS//////////////////////////////
*/

// gets called whenever switching to the login page is needed
void MainGView::login(){
    signuppage->close();
    this->setScene(loginpage);
    this->show();
}

// opens a widget form to let a new user signup
void MainGView::signup(){
      signuppage->show();
}

/*
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
        welcomewindow->updateScores();
        this -> setScene(welcomewindow);
        this -> show();
    }
}


/*
Home is the main window class.
Here, a new user can be created, a current user can login, or someone can decide to play as a guest.
*/
void MainGView::gotoHome(){
    welcomewindow->happyBirthday->setText("");
    welcomewindow->helloLabel->setText("Hello Guest!");
    loginpage->curUser=NULL;
    signuppage->curUser=NULL;
    welcomewindow->removeItem(welcomewindow->profilePicture);
    welcomewindow->game1Scores->setText("Please Sign up/in to save your scores :)");
    welcomewindow->game2Scores->setText("Please Sign up/in to save your scores :)");
    this->setScene(mainwindow);
    this->show();
}

/*
 gets called whenever switching to the welcome window as a guest is needed.
*/
void MainGView::playAsGuest(){
    welcomewindow -> curUser = NULL;
    this -> setScene(welcomewindow);
    this -> show();
}

