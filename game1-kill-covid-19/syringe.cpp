#include "syringe.h"

Syringe::Syringe(QObject *parent) : QObject(parent) {
    timer = new QTimer(this);

    x = 350;
    y = 100;

    this->setPixmap(QPixmap(syringePicPath).scaled(60, 60));
    this ->setPos(x, y);


    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);

}


void Syringe::update(){
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
