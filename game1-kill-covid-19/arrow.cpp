#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent) {
   // timerRotate = new QTimer(this);
    timerUpdate = new QTimer(this);

    x = 300;
    y = 100;

    this->setPixmap(QPixmap(arrowPicPath).scaled(60, 60));
    this ->setPos(x, y);


    QObject::connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    timerUpdate->start(30);
}


void Arrow::update(){
    y+= 2;
    setPos(x,y);

//    if(!scene()->collidingItems(this).isEmpty()){
//        scene()->removeItem(this);
//        delete(this);
//    }

    if(y>800){
        //sends signal that user lost
        scene()->removeItem(this);
        delete this;
    }
}
