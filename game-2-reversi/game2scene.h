#ifndef GAME2SCENE_H
#define GAME2SCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "board.h"
#include "line.h"
#include "disk.h"
#include "point.h"
#include "strategy.h"
#include <QtWidgets>

class Game2scene: public QGraphicsScene  {
    Q_OBJECT
public:
    Game2scene();
   // ~Game2scene();

    Board * board;
    QTimer* timer;

    QGraphicsPixmapItem * boardPicture;
    QGraphicsPixmapItem * gameNamePixmap;
    QString whiteImage = ":/game2images/WhiteDisk.png";
    QString blackIMage = ":/game2images/BlackDisk.png";

    QLabel * row;
    QLabel * column;
    QLabel * finalScore;
    QLineEdit * rowEdit;
    QLineEdit * columnEdit;
    QPushButton * enterMove;



    void startGame();
    void changeToPlayer();
    bool legalMovesCheck();
    void updateBoard();
    void gameOver();

    QGraphicsPixmapItem ***boardGame;
    int gameStatus = -1; // -1 for White and 1 for Black;

public slots:
    void cellClicked();

};

#endif // GAME2SCENE_H
