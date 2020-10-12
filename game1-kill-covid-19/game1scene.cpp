#include "game1scene.h"

Game1scene::Game1scene() {
    int height = 800;
    int width = 600;
    this -> setSceneRect(0, 0, width, height);
    this->setBackgroundBrush(QBrush(QPixmap(":/game1images/bright-lavender-background.jpg").scaled(800,800)));

    gameName = new QGraphicsPixmapItem;
    gameName->setPixmap(QPixmap(":/game1images/game1Name.png").scaled(300, 70));

    homeButton = new QPushButton("Home");
    startButton = new QPushButton("Start");

    rollingbg = new RollingBg();

    gameNameTimer = new QTimer(this);
    gameNameTimer->start(20);

    fillScene();
    connectButtons();
}

void Game1scene::fillScene(){
    homeButton->setGeometry(520, 600, 100, 30);
    this->addWidget(homeButton);

    startButton->setGeometry(520, 500, 100, 30);
    this ->addWidget(startButton);

    rollingbg->setGeometry(100, 0, 400, 800);
    this -> addWidget(rollingbg);

    gameName->setPos(QPointF(150, 100));
    this -> addItem(gameName);
}

void Game1scene::connectButtons(){
    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    QObject::connect(gameNameTimer, SIGNAL(timeout()), this, SLOT(updateGameName()));
}

void Game1scene::startGame(){
    virusLarge = new VirusLarge();
    this->addItem(virusLarge);

    arrow = new Arrow();
    this->addItem(arrow);

    syringe = new Syringe();
    this->addItem(syringe);

    gameNameTimer->stop();
    this->removeItem(gameName);

   // startButton->setEnabled(false);
}

void Game1scene::updateGameName(){
    if(gameName->y() < gameNamey){
        gameName->setPos(gameName->x(), gameName->y() + 2);
        if(gameName->y() >= gameNamey){
            gameNamey = 90;
        }
    }
    else if(gameName->y() > gameNamey){
        gameName->setPos(gameName->x(), gameName->y() - 2);
        if(gameName->y() <= gameNamey){
            gameNamey = 130;
        }
    }
}
