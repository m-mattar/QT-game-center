#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent) {
    timerRotate = new QTimer(this);
    timerShoot = new QTimer(this);

    this->setEnabled(true);

    x = 250;
    y = 550;

    this->setPixmap(QPixmap(arrowPicPath).scaled(60, 150));
    this ->setPos(x, y);

    QObject::connect(timerRotate, SIGNAL(timeout()), this, SLOT(rotate()));
    //QObject::connect(timerShoot, SIGNAL(timeout()), this, SLOT(shoot()));

    this->setTransformOriginPoint(75, 500);
    this->setRotation(90);
    timerRotate->start(100);
}

//SLOTS


void Arrow::rotate(){
    rotationDegree = rotationDegree + direction * 2;
    this->setRotation(rotationDegree);

    if(rotationDegree >= 12 || rotationDegree <= -12){
        direction *= -1;
    }

}

void Arrow::shoot(){
    x-=3;
    //timerRotate->stop();
    if(x < 100){
        x = 100;
        timerShoot->stop();
    }

    this->setPos(x, y);
}



//KEY EVENTS
void Arrow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Space){
        timerShoot->start(30);
    }

}
