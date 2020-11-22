#ifndef GAME2SCENE_H
#define GAME2SCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "board.h"
#include "line.h"
#include "disk.h"
#include "point.h"
#include "strategy.h"

class Game2scene: public QGraphicsScene  {
    Q_OBJECT
public:
    Game2scene();
   // ~Game2scene();

    Board * board;

    QGraphicsPixmapItem * boardPicture;
    QGraphicsPixmapItem * gameNamePixmap;
    QGraphicsPixmapItem * blankDisk;
    QGraphicsPixmapItem * whiteDisk;
    QGraphicsPixmapItem * blackDisk;

    void startGame();
    void gameOver();
    void fillScene();
    void changeToPlayer(int player);
    bool legalMovesCheck();
    void updateBoard();

    Disk ***booardGame;

public slots:
    //void cellClicked(int x, int y);

};

#endif // GAME2SCENE_H
