#include "board.h"

Board::Board() {
    gameboard = new int*[8];
    for (int i = 0; i < 8; i++) {
        gameboard[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            gameboard[i][j] = 0;
        }
    }
    gameboard[3][4] = playerBlack;
    gameboard[4][3] = playerBlack;
    gameboard[3][3] = playerWhite;
    gameboard[4][4] = playerWhite;
}

/*!
	Count the number of black and white disks in the board
*/
void Board::setScore() {
    countBlackDisks = 0;
    countWhiteDisks = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (gameboard[i][j] == playerWhite) {
                countWhiteDisks++;
            }
            if (gameboard[i][j] == playerBlack) {
                countBlackDisks++;
            }
        }
    }
}

/*!
	Checks if a User or the AI can play or not
	\return True if they can, false if not
*/
bool Board::cannotPlay(int player) {
    return getChangedTiles(player).size() == 0;
}

QList<Point> Board::getChangedTiles(int player){
    QList<Point> res;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(gameboard[i][j] == 0){
                Line curLine(player, Point(i, j), gameboard);
                res.append(curLine.getChangedTiles());
            }
        }
    }
    return res;
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        delete[] gameboard[i];
    }
    delete[] gameboard;
}

