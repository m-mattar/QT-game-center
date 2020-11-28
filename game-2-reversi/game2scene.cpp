#include "game2scene.h"

Game2scene::Game2scene(){
    fillScene();
    startGame();
}

/*!
	A function Used by the constructor to start the game and initalize the board and images
*/
void Game2scene::startGame(){
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(changeTurn()));

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
    changeToPlayer();

}
/*!
	A function used to do the logic whenever we change the player's turn
*/
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
/*!
	Checks if the play or AI can make a move
	\return True if they can, false if not
*/
bool Game2scene::legalMovesCheck(){
    return board ->cannotPlay(gameStatus);
}

/*!
	Updates the board's pixmaps whenever a turn is finished.
*/
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

/*!
	A function used to do the logic when a game finishes.
*/
void Game2scene::gameOver(){
    board -> setScore();
    int white = board->countWhiteDisks;
    int black = board->countBlackDisks;

    finalScore->setText("You have " + QString::number(white) + "\nPC has " + QString::number(black));
    if(white>black){
        finalScore->setText(finalScore->text() + ".\nYOU WON!!");
    }
    else if(white< black){
        finalScore->setText(finalScore->text() + ".\nPC WON!!");
    }else{
        finalScore->setText(finalScore->text() + ".\nDRAW!!");
    }
    this->addWidget(finalScore);
    updateUserScores();
}

/*!
	A function used to change turns between players
*/
void Game2scene::changeTurn(){
    timer->stop();
    changeToPlayer();
}

/*!
	A function that updates the board whenever an input from the user is given.
*/
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
        timer->start(2000);
    }
}

/*!
    Edits the current User's vector of game2 scores as well as his highscore
*/
void Game2scene::updateUserScores(){
    if(curUser){
        if(board->countWhiteDisks > highscore){
            highscore = board->countWhiteDisks;
        }
        curUser->game2_scores.push_back(board->countWhiteDisks);
        curUser->game2_scores.removeAt(0);
        curUser->game2_highest = highscore;
    }
}

/*!
	A helper function to fill the Scene
*/
void Game2scene::fillSceneHelper(QLabel * label, int fontSize){
    label -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    label -> setAttribute(Qt::WA_NoSystemBackground); //no background
    label -> setStyleSheet("QLabel { font-weight: bold}");
    label -> setFont(QFont("Arial", fontSize));
}
/*!
	A function to fill the scene
*/
void Game2scene::fillScene(){
    boardPicture = new QGraphicsPixmapItem;
    boardPicture->setPixmap(QPixmap(":/game2images/Board.png").scaled(650, 650));
    boardPicture->setPos(75, 75);
    this->addItem(boardPicture);

            //CHAR CONST
//    gameNamePicture = new QGraphicsPixmapItem;
//    gameNamePicture->setPixmap(QPixmap(":/game2images/gamename.jpeg").scaled(500,500));
//    gameNamePicture->setPos(100, 50);
//    this->addItem(gameNamePicture);

    gameName = new QLabel("Reversi");
    gameName-> setGeometry(350, 50, 100, 50);
    fillSceneHelper(gameName, 20);
    this->addWidget(gameName);

    enterMove = new QPushButton("Play");
    enterMove->setGeometry(700,410,100,50);

    row = new QLabel("Select Row:");
    column = new QLabel("Select Column:");
    rowNumbers = new QLabel("  0     1     2     3     4     5     6     7");
    colNumbers = new QLabel("");//"0\n\n1\n\n2\n\n3\n\n4\n\n5\n\n6\n\n7");
    finalScore = new QLabel("");
    rowEdit = new QLineEdit();
    columnEdit = new QLineEdit();

    row -> setGeometry(700,200,100,50);
    rowEdit -> setGeometry(700,255,100,50);
    column -> setGeometry(700,310,100,50);
    columnEdit -> setGeometry(700,360,100,50);
    finalScore ->setGeometry(700,430,100,200);

    rowNumbers->setGeometry(150, 95, 650, 50);
    colNumbers->setGeometry(120, 95, 50, 650);

    fillSceneHelper(row, 10);
    fillSceneHelper(column, 10);
    fillSceneHelper(rowNumbers, 25);
    fillSceneHelper(colNumbers, 25);
    fillSceneHelper(finalScore, 15);

    this->addWidget(row);
    this->addWidget(rowEdit);
    this->addWidget(column);
    this->addWidget(columnEdit);
    this->addWidget(enterMove);
    this->addWidget(rowNumbers);
    this->addWidget(colNumbers);

    homeButton = new QPushButton("Home");
    restartButton = new QPushButton("Restart");
    homeButton->setGeometry(30, 500, 100, 50);
    restartButton->setGeometry(30, 550, 100, 50);

    this->addWidget(homeButton);
    this->addWidget(restartButton);

    QObject::connect(enterMove, SIGNAL(clicked(bool)), this, SLOT(cellClicked()));
    QObject::connect(restartButton, SIGNAL(clicked(bool)), this, SLOT(restartGame()));
}

/*!
	A function that cleans the page and remove items from the board when a user chooses to go back to the home page
*/
void Game2scene::cleanPage(){
    delete board;
    board = new Board();

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->removeItem(boardGame[i][j]);
        }
    }
    gameStatus = -1;
    rowEdit->setText("");
    columnEdit->setText("");
    updateBoard();
    startGame();
}

/*!
	A function used to restart the game whenever the button is clicked
*/
void Game2scene::restartGame(){
    cleanPage();
    startGame();
}
