#ifndef GAME2SCENE_H
#define GAME2SCENE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "board.h"
#include "line.h"
#include "disk.h"
#include "point.h"
#include "strategy.h"
#include "../accounts-and-framework/user.h"

class Game2scene: public QGraphicsScene  {
    Q_OBJECT
public:
    Game2scene();
   // ~Game2scene();

    //will be initialized upon entering the page
    User * curUser = NULL;
    int highscore = 0;

    Board * board;
    QTimer* timer;

    QGraphicsPixmapItem * boardPicture;
    QGraphicsPixmapItem * gameNamePicture;
    QString whiteImage = ":/game2images/WhiteDisk.png";
    QString blackIMage = ":/game2images/BlackDisk.png";

    QLabel * row;
    QLabel * column;
    QLabel * finalScore;
    QLabel * gameName;
    QLabel * rowNumbers;
    QLabel * colNumbers;
    QLineEdit * rowEdit;
    QLineEdit * columnEdit;
    QPushButton * enterMove;
    QPushButton * homeButton;
    QPushButton * restartButton;

    void startGame();
    void changeToPlayer();
    bool legalMovesCheck();
    void updateBoard();
    void gameOver();
    void fillScene();
    void fillSceneHelper(QLabel * label, int fontSize);
    void updateUserScores();
    void cleanPage();

    QGraphicsPixmapItem ***boardGame;
    int gameStatus = -1; // -1 for White and 1 for Black;

public slots:
    void cellClicked();
    void changeTurn();
    void restartGame();

};

#endif // GAME2SCENE_H
