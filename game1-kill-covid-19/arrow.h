#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

class Arrow : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Arrow(QObject *parent = nullptr);

    QString arrowPicPath = ":/game1images/arrow.png";

    int x, y;
    int direction = 1; //on the right of the scene
    int rotationDegree = 0;

    QTimer * timerRotate;
    QTimer * timerShoot;

    void keyPressEvent(QKeyEvent * event);

signals:

public slots:
    void rotate();
    void shoot();

};

#endif // ARROW_H
