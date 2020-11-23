#include "game2scene.h"

Game2scene::Game2scene(){
    startGame();
    changeToPlayer();
}

void Game2scene::startGame(){
    boardPicture = new QGraphicsPixmapItem;
    boardPicture->setPixmap(QPixmap(":/game2images/Board.png").scaled(600, 600));

    gameNamePixmap = new QGraphicsPixmapItem();
    gameNamePixmap->setPixmap(QPixmap(":/game1images/game1Name.png").scaled(300, 70));

    boardPicture->setPos(100, 100);
    this->addItem(boardPicture);

    timer = new QTimer(this);

    board = new Board();

    boardGame = new QGraphicsPixmapItem**[8];
    for(int i =0;i<8;i++){
        boardGame[i] = new QGraphicsPixmapItem*[8];
        for(int j =0;j<8;j++){
            boardGame[i][j] = new QGraphicsPixmapItem;
            if(board->gameboard[i][j] == -1){
                boardGame[i][j] ->setPixmap(QPixmap(":/game2images/WhiteDisk.png").scaled(50, 50));
                boardGame[i][j] ->setPos(150 + i*65, 150 + j*65);
                this->addItem(boardGame[i][j]);
            }
            if(board->gameboard[i][j] == 1){
                boardGame[i][j] ->setPixmap(QPixmap(":/game2images/BlackDisk.png").scaled(50, 50));
                boardGame[i][j] ->setPos(150 + i*65, 150 + j*65);
                this->addItem(boardGame[i][j]);
            }
        }
    }

    row = new QLabel("Please Enter the row");
    column = new QLabel("Please Enter the column");
    finalScore = new QLabel("");


    rowEdit = new QLineEdit();
    columnEdit = new QLineEdit();

    row -> setGeometry(700,200,100,50);
    rowEdit -> setGeometry(700,255,100,50);
    column -> setGeometry(700,310,100,50);
    columnEdit -> setGeometry(700,360,100,50);
    finalScore ->setGeometry(700,430,100,50);

    enterMove = new QPushButton("Play");
    enterMove->setGeometry(700,410,100,50);
    this->addWidget(row);
    this->addWidget(rowEdit);
    this->addWidget(column);
    this->addWidget(columnEdit);
    this->addWidget(enterMove);

     QObject::connect(enterMove, SIGNAL(clicked(bool)), this, SLOT(cellClicked()));
}

void Game2scene::changeToPlayer(){
     gameStatus *= -1;
     if(legalMovesCheck()){
         gameStatus*=-1;
         if(legalMovesCheck()){
             gameOver();
             return;
         }
         gameStatus*=-1;
         changeToPlayer();
     }
     if(gameStatus == 1){ // AI to play
        Strategy * bot = new Strategy(gameStatus);
        bot->play(board);
        updateBoard();
        changeToPlayer();
     }
}

bool Game2scene::legalMovesCheck(){
    return board ->cannotPlay(gameStatus);
}

void Game2scene::updateBoard(){
    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            if(board->gameboard[i][j] == -1){
                boardGame[i][j] ->setPixmap(QPixmap(":/game2images/WhiteDisk.png").scaled(50, 50));
                boardGame[i][j] ->setPos(150 + i*65, 150 + j*65);
                this->addItem(boardGame[i][j]);
            }
            if(board->gameboard[i][j] == 1){
                boardGame[i][j] ->setPixmap(QPixmap(":/game2images/BlackDisk.png").scaled(50, 50));
                boardGame[i][j] ->setPos(150 + i*65, 150 + j*65);
                this->addItem(boardGame[i][j]);
            }
        }
    }
}

void Game2scene::gameOver(){
    board -> setScore();
    int white = board->countWhiteDisks;
    int black = board->countBlackDisks;
    finalScore->setText("White has " + QString::number(white) + "& black has " + QString::number(black));
    if(white>black){
        finalScore->setText(finalScore->text() + ". WHITE WON!!");
    }
    else{
        finalScore->setText(finalScore->text() + ". BLACK WON!!");
    }
    this->addWidget(finalScore);
}

void Game2scene::cellClicked(){
    int i = rowEdit->text().toInt();
    int j = columnEdit->text().toInt();
    Line  l(-1,Point(j,i),board->gameboard);
    QList<Point> changed = l.getChangedTiles();
    if(changed.size() > 0){
        for(int i=0;i<changed.size();i++){
            Point current = changed[i];
            board->gameboard[current.x][current.y] = -1;
        }
        updateBoard();
//        timer->start(4000);
//        connect(timer, &QTimer::timeout, [this]{
//                    timer->stop();
//            changeToPlayer();
//        });
        changeToPlayer();
    }
    else{

    }
}
