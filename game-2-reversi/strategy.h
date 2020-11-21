#ifndef STRATEGY_H
#define STRATEGY_H

#include "board.h"
#include "line.h"
#include "point.h"

class Strategy{
public:
    Strategy(int player);
    void play(Board * board);

private:
    Point getBestMove(Board * board);
    int player;
};

#endif // STRATEGY_H
