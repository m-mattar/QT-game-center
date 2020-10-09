#include "game1scene.h"

Game1scene::Game1scene() {
    int height = 800;
    int width = 600;
    this -> setSceneRect(0, 0, width, height);
    this->setBackgroundBrush(QBrush(QPixmap(":/game1images/bright-lavender-background.jpg").scaled(800,800)));

    homeButton = new QPushButton("Home");
    rollingbg = new RollingBg();

    fillScene();
    connectButtons();
}

void Game1scene::fillScene(){
    rollingbg->setGeometry(100, 0, 400, 800);
    this -> addWidget(rollingbg);
    homeButton->setGeometry(520, 600, 100, 30);
    this->addWidget(homeButton);
}

void Game1scene::connectButtons(){

}
