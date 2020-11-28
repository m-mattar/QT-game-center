#include "line.h"

Line::Line(int diskColor, Point point, int** board) {
    this->diskColor = diskColor;
    this->point = point;
    boardgame = new int*[8];
    for(int i = 0; i < 8; i++){
        boardgame[i] = new int[8];
        for(int j = 0; j < 8; j++){
            boardgame[i][j] = board[i][j];
        }
    }
}

/*!
	A function that get all the changed tiles that are affected by choosing the point attribute
	\return A list of all changed points on the board
*/
QList<Point> Line::getChangedTiles() {
    boardgame[point.x][point.y] = diskColor;

    QList<Point> res;

    QVector<Point> patterns = {Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0), //vertical
                              Point(1, 1), Point(-1, -1), Point(-1, 1), Point(1, -1) //diagonal
                              };

    for(int i = 0; i < patterns.size(); i++){
        res.append(checkLine(patterns[i]));
    }

    if (res.size() > 0) {
        res.append(Point(point.x, point.y));
        return res;
    } else {
        boardgame[point.x][point.y] = 0;
        return res;
    }

}
/*!
	A function used by getChangedTiles to see whether a line is affected by the point
	\return If it is affected, it returns a list of all points affected. If not, it just returns an empty list
*/
QList<Point> Line::checkLine(Point pattern) {
    bool isChanged = false;
    QList<Point> res;

    int x = point.x + pattern.x, y = point.y + pattern.y;
    while((x >= 0 && x < 8) && (y >= 0 && y < 8)){

        if (boardgame[x][y] == 0) break;

        else if (boardgame[x][y] == diskColor) {
            isChanged = true;
            break;
        }
        else {
            res.push_back(Point(x, y));
        }

        x += pattern.x; y += pattern.y;
    }
    if (isChanged) {
        return res;
    } else {
        return QList<Point>();
    }
}

Line::~Line() {

    for(int i = 0; i < 8; i++){
        delete [] boardgame[i];
    }
    delete [] boardgame;
}
