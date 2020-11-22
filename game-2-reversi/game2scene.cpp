#include "game2scene.h"

Game2scene::Game2scene(){
        boardPicture = new QGraphicsPixmapItem;
        boardPicture->setPixmap(QPixmap(":/game2images/Board.png").scaled(600, 600));

        gameNamePixmap = new QGraphicsPixmapItem();
        gameNamePixmap->setPixmap(QPixmap(":/game1images/game1Name.png").scaled(300, 70));

        blankDisk = new QGraphicsPixmapItem;
        blankDisk->setPixmap(QPixmap(":/game1images/game1Name.png").scaled(50, 50));

        whiteDisk = new QGraphicsPixmapItem;
        whiteDisk->setPixmap(QPixmap(":/game2images/WhiteDisk.png").scaled(50, 50));

        blackDisk = new QGraphicsPixmapItem;
        blackDisk->setPixmap(QPixmap(":/game2images/BlackDisk.png").scaled(50, 50));

        fillScene();
}

void Game2scene::startGame(){

}

void Game2scene::gameOver(){

}

void Game2scene::fillScene(){
    boardPicture->setPos(100, 100);
    this->addItem(boardPicture);

    whiteDisk->setPos(165, 165);
    this->addItem(whiteDisk);

    blackDisk->setPos(225, 165);
    this->addItem(blackDisk);


}

void Game2scene::changeToPlayer(int player){

}

bool Game2scene::legalMovesCheck(){
    return true;
}

void Game2scene::updateBoard(){

}
