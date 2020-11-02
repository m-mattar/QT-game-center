#include "arrow.h"
\

Arrow::Arrow(QObject *parent) : QObject(parent) {
    timerRotate = new QTimer(this);
    timerShoot = new QTimer(this);

    this->setEnabled(true);

    this->setPixmap(QPixmap(arrowPicPath).scaled(60, 150));
    this ->setPos(250, 550);

    QObject::connect(timerRotate, SIGNAL(timeout()), this, SLOT(rotate()));
    QObject::connect(timerShoot, SIGNAL(timeout()), this, SLOT(shoot()));

    this->setTransformOriginPoint(75, 500);
    timerRotate->start(timerRotateSpeed);
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
    if(rotationDegree > 1){
        syringe->setPos(syringe->x() + 0.6 * (rotationDegree), syringe->y() - 2 * (rotationDegree));
    }
    else if(rotationDegree <= 1 && rotationDegree >= -1){
        syringe->setPos(syringe->x(), syringe->y() - 2);
    }
    else{
        syringe->setPos(syringe->x() + 0.6 * (rotationDegree), syringe->y() + 2 * (rotationDegree));
    }

    if(syringe->x() > 450.0|| syringe->x() < 70.0|| syringe->y() < 0.0){
        scene()->removeItem(syringe);
        delete syringe;
        emit failure();
    }
}



//KEY EVENTS
void Arrow::spacePressed(){
    syringe = new Syringe();
    syringe->setPos(x(), y());
    syringe->setTransformOriginPoint(75, 500);
    syringe->setRotation(rotationDegree);
    scene()->addItem(syringe);

    timerShoot->start(30);
    timerRotate->stop();


}

