#ifndef BOARD_H
#define BOARD_H

#include "point.h"
#include "line.h"

class Board {
public:
    Board();

    ~Board();

    int countBlackDisks = 0;
    int countWhiteDisks = 0;

    const int playerWhite = -1;
    const int playerBlack = 1;

    void setScore();
    QList<Point> getChangedTiles(int player);
    bool cannotPlay(int player);

    int **gameboard;
};

#endif // BOARD_H
