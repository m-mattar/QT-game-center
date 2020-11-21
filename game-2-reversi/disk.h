#ifndef DISK_H
#define DISK_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class Disk: public QLabel{
    Q_OBJECT
public:
    Disk(int x, int y, QWidget * parent = 0);

signals:
    void isClicked(int x, int y);

protected:
    int x;
    int y;
    void mousePressEvent(QMouseEvent * event);
};

#endif // DISK_H
