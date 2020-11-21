#ifndef LINE_H
#define LINE_H

#include <qlist.h>
#include <QVector>
#include "point.h"

class Line{
public:
    int diskColor;
    Point point;
    int **boardgame;

    QList<Point> getChangedTiles();
    QList<Point> checkLine(Point pattern);

    Line(int diskColor, Point point, int** board);

    ~Line();
};

#endif // LINE_H
