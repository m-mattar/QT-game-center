#include "strategy.h"


Strategy::Strategy(int player){
    this->player = player;
}

/*!
	A funciton used by the AI to play its strategy
*/
void Strategy::play(Board * board){
    Point bestMove = getBestMove(board);
    Line line(player, bestMove, board->gameboard);

    QList<Point> res = line.getChangedTiles();
    for (int i = 0; i < res.size(); i++) {
        board->gameboard[res.at(i).x][res.at(i).y] = player;
    }
}

/*!
	A funciton used by the play function to get the best Point to be played by the AI
	\return The best point
*/
Point Strategy::getBestMove(Board * board) {
    int bestMoveCount = 0;
    Point bestMove = Point(0, 0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board->gameboard[i][j] == 0) {
                Point point(i, j);
                Line curLine(player, Point(i, j), board->gameboard);

                if (curLine.getChangedTiles().size() > bestMoveCount) {
                    if (point == Point(0, 0)
                            || point == Point(8, 0)
                            || point == Point(8, 8)
                            || point == Point(0, 8)) {
                        return point;
                    }
                    bestMoveCount = curLine.getChangedTiles().size();
                    bestMove = Point(i, j);
                }
            }
        }
    }
    return bestMove;
}
