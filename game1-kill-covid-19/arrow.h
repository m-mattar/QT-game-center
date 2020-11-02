#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "syringe.h"


class Arrow : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Arrow(QObject *parent = nullptr);

    Syringe * syringe;

    QString arrowPicPath = ":/game1images/arrow.png";

    int direction = 1; //on the right of the scene
    int rotationDegree = 0;
    int timerRotateSpeed = 70;

    QTimer * timerRotate;
    QTimer * timerShoot;

    void spacePressed();


signals:
    void failure();

public slots:
    void rotate();
    void shoot();

};

#endif // ARROW_H
