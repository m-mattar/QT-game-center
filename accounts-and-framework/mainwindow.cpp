#include "mainwindow.h"


MainWindow::MainWindow() : QGraphicsScene() {
    QString jokeStr = getJoke();

    // personalizing the scene
    int height = 800;
    int width = 400;
    this -> setSceneRect(0, 0, width, height);
    this -> setBackgroundBrush(QBrush(QImage(":/center-background.jpg"))); //.scaledToWidth(width).scaledToHeight(height)

    //instanciating the widgets
    loginButton = new QPushButton("Log in");
    signupButton = new QPushButton("Sign up");
    guestButton = new QPushButton("Play as Guest");

    helloLabel = new QLabel("Welcome to the game center!");
    jokeLabel = new QLabel("Here's a random joke for you!");
    joke = new QLabel(jokeStr);

    fixLabels();
    fillScene();
    playMusic();
}

/*
//////////////////////METHODS//////////////////////////////
*/


/*
    sets the geometry of all widgets and labels.
    Adds them to the scene
*/
void MainWindow::fillScene(){
    helloLabel -> setGeometry(0, 100, 400, 30);
    helloLabel -> setAlignment(Qt::AlignCenter);

    jokeLabel -> setGeometry(0, 170, 400, 30);
    jokeLabel -> setAlignment(Qt::AlignCenter);

    joke -> setGeometry(0, 200, 400, 60);
    joke -> setAlignment(Qt::AlignCenter);
    joke ->setWordWrap(true);

    loginButton -> setGeometry(100, 300, 200, 40);
    signupButton -> setGeometry(100, 350, 200, 40);
    guestButton -> setGeometry(100, 400, 200, 40);

    this -> addWidget(helloLabel);
    this -> addWidget(jokeLabel);
    this -> addWidget(joke);

    this -> addWidget(loginButton);
    this -> addWidget(signupButton);
    this -> addWidget(guestButton);
}

/*
    adjusts the design of the labels (color, backround, font, ...)
*/
void MainWindow::fixLabels(){
    helloLabel -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    helloLabel -> setAttribute(Qt::WA_NoSystemBackground); //no background
    helloLabel -> setStyleSheet("QLabel { font-weight: bold; color: white}");
    helloLabel -> setFont(QFont("Arial", 20));

    jokeLabel -> setWindowFlag(Qt::FramelessWindowHint);
    jokeLabel -> setAttribute(Qt::WA_NoSystemBackground);
    jokeLabel -> setStyleSheet("QLabel { font-weight: bold; color: white;}");
    jokeLabel -> setFont(QFont("Arial", 13));

    joke -> setWindowFlag(Qt::FramelessWindowHint);
    joke -> setAttribute(Qt::WA_NoSystemBackground);
    joke -> setStyleSheet("QLabel { color: white;}");
    joke -> setFont(QFont("Arial", 10));
}




// METHODS
/*
    loads the jokes.json document
    selects a random joke from it
    returns it as a QString
*/
QString MainWindow::getJoke(){
    srand(time(NULL));
    const QString filePath = "/home/eece435l/Desktop/435L/project-eece435l-game-center/JSON/jokes.json";
//    QString filePath = "/home/eece435l/Desktop/435L-Project/project-eece435l-game-center/JSON/jokes.json";
//    QString filePath = "../JSON/jokes.json"; //location of the jokes JSON file

    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll(), &jsonParseError);
    QJsonArray jokesArray = jsonDocument.array();
    int randi = rand() % (jokesArray.size());
    QJsonValue val = jokesArray[randi];
    QJsonObject obj = val.toObject();
    return obj["setup"].toString() + "\n" + obj["punchline"].toString();
}

void MainWindow::playMusic(){

    //Play music
//        QMediaPlayer* music = new QMediaPlayer();
//        music->setMedia(QUrl("qrc:/sounds/Sounds/music.mp3"));
//        music->play();

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/Sounds/music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();


}
