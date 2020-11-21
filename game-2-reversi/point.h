#ifndef POINT_H
#define POINT_H


class Point {
public:
    int x;
    int y;

    bool operator != (Point point);
    bool operator == (Point point);

    Point();

    Point(int x, int y);

};

#endif // POINT_H
