#include "game1scene.h"

Game1scene::Game1scene() {

    int height = 800;
    int width = 600;
    this -> setSceneRect(0, 0, width, height);
    this->setBackgroundBrush(QBrush(QPixmap(":/game1images/bright-lavender-background.jpg").scaled(800,800)));

    gameName = new QGraphicsPixmapItem;
    gameName->setPixmap(QPixmap(":/game1images/game1Name.png").scaled(300, 70));

    gameOver = new QGraphicsPixmapItem;
    gameOver->setPixmap(QPixmap(":/game1images/gameOver.png").scaled(300, 70));

    gameWon = new QGraphicsPixmapItem;
    gameWon->setPixmap(QPixmap(":/game1images/gameWon.png").scaled(300, 70));


    homeButton = new QPushButton("Home");
    startButton = new QPushButton("Start");

    rollingbg = new RollingBg();

    gameNameTimer = new QTimer(this);
    gameNameTimer->start(20);
    gameOverTimer = new QTimer(this);
    gameWonTimer = new QTimer(this);

    highscoreL = new QLabel("Your Highscore is: ");
    currentScoreL = new QLabel("Score: ");
    scoreHistoryL = new QLabel("You Score History is: ");
    scoreHistory = new QLabel;

    fillScene();
    connectButtons();
    setScoreLabels();

}
/*!
    fixes the buttons and adds them to the game Scene
*/
void Game1scene::fillScene(){
    homeButton->setGeometry(520, 600, 100, 30);
    this->addWidget(homeButton);

    startButton->setGeometry(520, 500, 100, 30);
    this ->addWidget(startButton);

    rollingbg->setGeometry(100, 0, 400, 800);
    this -> addWidget(rollingbg);

    gameName->setPos(QPointF(150, 100));
    this -> addItem(gameName);

    gameOver->setPos(QPointF(150,100));
    gameWon->setPos(QPointF(150,100));
}

/*!
    Fixes the score labels and adds them to the scene
*/
void Game1scene::setScoreLabels(){
    highscoreL->setGeometry(520, 100, 200, 30);
    highscoreL -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    highscoreL -> setAttribute(Qt::WA_NoSystemBackground); //no background
    highscoreL -> setStyleSheet("QLabel { font-weight: bold}");
    highscoreL -> setFont(QFont("Arial", 10));
    this->addWidget(highscoreL);

    currentScoreL->setGeometry(520, 220, 200, 100);
    currentScoreL -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    currentScoreL -> setAttribute(Qt::WA_NoSystemBackground); //no background
    currentScoreL -> setStyleSheet("QLabel { font-weight: bold}");
    currentScoreL -> setFont(QFont("Arial", 10));
    this->addWidget(currentScoreL);

    scoreHistoryL ->setGeometry(520, 150, 200, 100);
    scoreHistoryL -> setWindowFlag(Qt::FramelessWindowHint); //No Frame
    scoreHistoryL -> setAttribute(Qt::WA_NoSystemBackground); //no background
    scoreHistoryL -> setStyleSheet("QLabel { font-weight: bold}");
    scoreHistoryL -> setFont(QFont("Arial", 10));
    this->addWidget(scoreHistoryL);
}


/*!
    Connects all slots and buttons except the virus related ones since we keep creating a new virus everytime.
    Check Game1scene::addVirus() to see the virus related slots.
*/
void Game1scene::connectButtons(){
    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    QObject::connect(gameNameTimer, SIGNAL(timeout()), this, SLOT(updateGameName()));
    QObject::connect(gameOverTimer, SIGNAL(timeout()), this, SLOT(updateGameOver()));
    QObject::connect(gameWonTimer, SIGNAL(timeout()), this, SLOT(updateGameWon()));

}

/*!
    Resets the current scores and starts a new game
*/
void Game1scene::startGame(){
    arrow = new Arrow();
    this->addItem(arrow);
    arrow -> setFlag(QGraphicsItem::ItemIsFocusable);
    arrow -> setFocus();

    currentScore = 0;
    countLarge = countSmall = countMedium = 0;
    currentScoreL->setText("Score: " + QString::number(currentScore));

    gameNameTimer->stop();
    gameOverTimer->stop();
    gameWonTimer->stop();
    this->removeItem(gameName);
    this->removeItem(gameOver);
    this->removeItem(gameWon);

    startButton->setEnabled(false);

    QObject::connect(arrow, SIGNAL(failure()), this, SLOT(userFailed()));

    addVirus();
    addCircle();
}

/*!
    Adds the semi-circle that serves as a stand to the arrow
*/
void Game1scene::addCircle(){
    circle = new QGraphicsPixmapItem;
    circle->setPixmap(QPixmap(":/game1images/half-circle.png").scaled(200,75));
    circle->setPos(QPointF(175,600));
    this->addItem(circle);

}

/*!
    Makes gameName label move up and down
*/
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


/*!
    Makes gameOver label move up and down
*/
void Game1scene::updateGameOver(){
    if(gameOver->y() < gameOvery){
        gameOver->setPos(gameOver->x(), gameOver->y() + 2);
        if(gameOver->y() >= gameOvery){
            gameOvery = 90;
        }
    }
    else if(gameOver->y() > gameOvery){
        gameOver->setPos(gameOver->x(), gameOver->y() - 2);
        if(gameOver->y() <= gameOvery){
            gameOvery = 130;
        }
    }
}


/*!
    Makes gameWon label move up and down
*/
void Game1scene::updateGameWon(){
    if(gameWon->y() < gameWony){
        gameWon->setPos(gameWon->x(), gameWon->y() + 2);
        if(gameWon->y() >= gameWony){
            gameWony = 90;
        }
    }
    else if(gameWon->y() > gameWony){
        gameWon->setPos(gameWon->x(), gameWon->y() - 2);
        if(gameWon->y() <= gameWony){
            gameWony = 130;
        }
    }
}

/*!
    updates the score labels on the gameScene
*/
void Game1scene::displayScores(){
    //get last 5 scores

    if(curUser){
        QString res = "";
        QVector<int> game1 = curUser->game1_scores;
        for(int i :game1){
            res = res + QString::number(i)+",";
        }
        res.remove(res.size()-1, 1);
        scoreHistoryL->setText("You Score History is:\n " + res);
    }

    if(currentScore > highscore){
        highscore = currentScore;
    }

    highscoreL->setText("Your highscore is: " + QString::number(highscore));

    currentScoreL->setText("Score: " + QString::number(currentScore)
                           + "\nLarge Viruses Hit: " + QString::number(countLarge)
                           + "\nMedium Viruses Hit: " + QString::number(countMedium)
                           + "\nSmall Viruses Hit: " + QString::number(countSmall)
                           );
}

/*!
    Creates a new virus and adds it to the game scene
*/
void Game1scene::addVirus(){
    virusLarge = new VirusLarge(nullptr, levelSpeed);
    QObject::connect(virusLarge, SIGNAL(collision()), this, SLOT(collisionVirusSyring()));
    QObject::connect(virusLarge, SIGNAL(failure()), this, SLOT(userFailed()));

    this->addItem(virusLarge);
}

/*!
    Slot to the collision() signal emitted by the virusLarge class
*/
void Game1scene::collisionVirusSyring(){
    arrow->timerRotate->start(arrow->timerRotateSpeed);
    arrow->timerShoot->stop();

    int virustp = virusLarge->virusType;

    currentScore += virusLarge->virusScore;

    if(virustp == 1){
        countLarge += 1;
    } else if(virustp == 2){
        countMedium += 1;
    }else{
        countSmall += 1;
    }

    counter++;
    if(counter == 5){
        increaseLevel();
        counter = 0;
    }

    currentScoreL->setText("Score: " + QString::number(currentScore));

    if(currentScore >= 150){
        userWon();
    }
    else{
        this -> addVirus();
    }

    delete arrow->syringe;
}

/*!
    whenever the user reaches a score >= 150 this function signals that the user wins and ends the current game
*/
void Game1scene::userWon(){
    arrow->timerRotate->stop();
    arrow->timerShoot->stop();

    displayScores();
    updateUserScores();
    delete arrow;

    this->addItem(gameWon);
    gameWonTimer->start(20);


    //this->removeItem(virusLarge);
    startButton->setEnabled(true);

}

/*!
  Whenever the arrow goes out of bound or when a virus leaves the boundary without being hit,
  this function receives the failure() signal and ends the current game
*/
void Game1scene::userFailed(){
    arrow->timerRotate->stop();
    arrow->timerShoot->stop();

    displayScores();
    updateUserScores();
    delete arrow;

    this->addItem(gameOver);
    gameOverTimer->start(20);

    this->removeItem(virusLarge);
    delete virusLarge;
    startButton->setEnabled(true);
}

/*!
    Edits the current User's vector of game1 scores as well as his highscore
*/
void Game1scene::updateUserScores(){
    if(curUser){
        curUser->game1_scores.push_back(currentScore);
        curUser->game1_scores.removeAt(0);
        curUser->game1_highest = highscore;
    }
}

/*!
    Called whenever the user hits 5 viruses.
    increases the speed of rotation of arrows as well as the speed of the viruses (levelSpeed) and rolling background
*/
void Game1scene::increaseLevel(){
    if(levelSpeed > 10){
        levelSpeed-=10;
        rollingbg->timer->stop();
        rollingbg->timerSpeed = levelSpeed;
        rollingbg->timer->start(rollingbg->timerSpeed);
    }

    if(arrow->timerRotateSpeed > 30){
        arrow->timerRotate->stop();
        arrow->timerRotateSpeed-=10;
        arrow->timerRotate->start(arrow->timerRotateSpeed);
    }
}

/*!
    A handler for all key events:
    - Space -> shooting on a virus
    - F1 -> start game
*/
void Game1scene::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_F1){
        if(startButton->isEnabled()){
            startGame();
        }
    }
    else if(event->key() == Qt::Key_Space){
        arrow->spacePressed();
    }

}

/*!
    Resets the page before admitting a new user
*/
void Game1scene::cleanPage(){
    highscore = 0;
    currentScore = 0;
    countLarge = 0;
    countSmall = 0;
    countMedium = 0;

    currentScoreL->setText("Score: " + QString::number(currentScore));
    highscoreL->setText("Your highscore is: " + QString::number(highscore));
    scoreHistoryL->setText("You Score History is: ");

    gameNameTimer->stop();
    gameOverTimer->stop();
    gameWonTimer->stop();
    this->removeItem(gameName);
    this->removeItem(gameOver);
    this->removeItem(gameWon);


    this->addItem(gameName);
    gameNameTimer->start(20);
}
