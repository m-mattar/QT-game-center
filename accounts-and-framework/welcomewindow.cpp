#include "welcomewindow.h"

WelcomeWindow::WelcomeWindow(QObject *parent) : QGraphicsScene(parent) {
    int height = 800;
    int width = 400;
    this -> setSceneRect(0, 0, width, height);
    this -> setBackgroundBrush(QBrush(QImage(":/center-background.jpg")));

    QString username = (curUser != NULL) ? curUser->firstName+" "+curUser->lastName : "Guest";
    helloLabel = new QLabel(QString("Hello " + username + "!"));

    game1Scores = new QLabel("");
    game2Scores = new QLabel("");
    happyBirthday = new QLabel("");

    game1Pic = new QGraphicsPixmapItem;
    game2Pic = new QGraphicsPixmapItem;
    profilePicture = new QGraphicsPixmapItem;

    game1Button = new QPushButton("Kill Covid-19");
    game2Button = new QPushButton("Reversi");
    homeButton = new QPushButton("Home");


    fixPixmapItems();
    fixWidgets();
    fixLabels();
    fillScene();
    checkBday();

}

/*!
    Sets the icons of the games in their corresponding place on the scene
*/
void WelcomeWindow:: fixPixmapItems(){
    game1Pic->setPixmap(QPixmap(":/game1icon.jpeg").scaled(150, 120));
    game1Pic->setPos(QPointF(10, 250));

    game2Pic -> setPixmap(QPixmap(":/game2icon.jpeg").scaled(150, 120));
    game2Pic->setPos(QPointF(240, 250));
}

/*!
    Sets the geometry of the widgets
*/
void WelcomeWindow:: fixWidgets(){
    game1Button->setGeometry(10, 380, 150, 30);
    game2Button->setGeometry(240, 380, 150, 30);
    homeButton->setGeometry(160, 600, 100, 30);

    game1Scores->setGeometry(10,440,150,80);
    game1Scores->setWordWrap(true);

    game2Scores->setGeometry(240,440,150,80);
    game2Scores->setWordWrap(true);
}

/*!
    Decodes a user's profile picture from a QJsonValue into a QPixmap
    sets the Pixmap p to the corresponding profile pic location on the scene
*/
void WelcomeWindow::updateProfilePic(){
    if(curUser && (curUser->picture).toString() != ""){
        QJsonValue val = curUser->picture;
        auto const encoded = val.toString().toLatin1();
        QPixmap p;
        p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
        profilePicture->setPixmap(p.scaled(150, 120));
        profilePicture->setPos(QPointF(400,65));
        this -> addItem(profilePicture);
    }
}

/*!
	Function used to fix Labels - For readability
*/
void WelcomeWindow:: fixLabels(){
    helloLabel -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    helloLabel -> setAttribute(Qt::WA_NoSystemBackground); //no background
    helloLabel -> setStyleSheet("QLabel { font-weight: bold; color: white}");
    helloLabel -> setFont(QFont("Arial", 20));

    helloLabel -> setGeometry(0, 100, 400, 40);
    helloLabel -> setAlignment(Qt::AlignCenter);

    happyBirthday -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    happyBirthday -> setAttribute(Qt::WA_NoSystemBackground); //no background
    happyBirthday -> setStyleSheet("QLabel { font-weight: bold; color: white}");
    happyBirthday -> setFont(QFont("Arial", 15));

    happyBirthday -> setGeometry(0, 160, 400, 40);
    happyBirthday -> setAlignment(Qt::AlignCenter);

    game1Scores -> setAttribute(Qt::WA_NoSystemBackground);
    game1Scores -> setStyleSheet("QLabel { font-weight: bold; color: white}");

    game2Scores -> setAttribute(Qt::WA_NoSystemBackground);
    game2Scores -> setStyleSheet("QLabel { font-weight: bold; color: white}");

}

/*!
	Function Used to fill the Scene - For readability
*/
void WelcomeWindow:: fillScene(){
    this -> addWidget(helloLabel);

    this -> addItem(game1Pic);
    this -> addItem(game2Pic);
    this -> addItem(profilePicture);

    this -> addWidget(game1Button);
    this -> addWidget(game2Button);
    this -> addWidget(homeButton);

    this -> addWidget(game1Scores);
    this -> addWidget(game2Scores);


}


/*!
    Displays a user's scores to the scene for each corresponding game
*/
void WelcomeWindow::updateScores(){
    QString res = "Your last 5 scores are:";
    QVector<int> game1 = curUser->game1_scores;
    for(int i :game1){
        res = res + QString::number(i)+",";
    }

    res.remove(res.size()-1, 1);
    res = res + "\n\nYour highest score is " + QString::number(curUser->game1_highest);
    game1Scores->setText(res);


    QString res2 = "Your last 5 scores are:";
    QVector<int> game2 = curUser->game2_scores;
    for(int i :game2){
        res2 = res2 + QString::number(i)+",";
    }

    res2.remove(res2.size()-1, 1);
    res2 = res2+ "\n\nYour highest score is " + QString::number(curUser->game2_highest);
    game2Scores->setText(res2);
}

/*!
    checks if its the current user's birthday.
    if so, displays a happy birthday message
*/
void WelcomeWindow::checkBday(){
    QString date = (curUser != NULL) ? curUser->dateOfBirth : "0/0/0";
    int pos=date.lastIndexOf(QChar('/'));
    date.remove(pos, 5);

    QString curDate = QDate::currentDate().toString("dd/MM/yyyy");
    int pos2 = curDate.lastIndexOf(QChar('/'));
    curDate.remove(pos2, 5);
    if(curDate[0] == '0') curDate.remove(0, 1);

    if(date == curDate) happyBirthday->setText("Our team wishes you a Happy Birthday!");
    else{happyBirthday -> setText("");}

    if(happyBirthday->text() != "") this -> addWidget(happyBirthday);
}

/*!
    Called when we need to go to the maingview
    Cleans all widgets in order to prepare for another user to login/signup
*/
void WelcomeWindow:: cleanPage(){
    this->curUser = NULL;
    this->happyBirthday->setText("");
    this->helloLabel->setText("Hello Guest!");
    this->removeItem(profilePicture);
    this->game1Scores->setText("Please Sign up/in to save your scores :)");
    this->game2Scores->setText("Please Sign up/in to save your scores :)");
}

