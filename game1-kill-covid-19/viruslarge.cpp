#include "viruslarge.h"

VirusLarge::VirusLarge(QObject *parent): QObject(parent) {

    picturePath = ":/game1images/virus-green.png";

    timer = new QTimer(this);

    x = 350;
    y = 100;

    this->setPixmap(QPixmap(picturePath).scaled(100, 100));
    this ->setPos(x, y);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);

}

void VirusLarge::update(){
    y+= 2;
    setPos(x,y);

//    if(!scene()->collidingItems(this).isEmpty()){
//        scene()->removeItem(this);
//        delete(this);
//    }
    if(y>800){
        scene()->removeItem(this);
        delete this;
    }
}
