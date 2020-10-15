#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent) {
   // timerRotate = new QTimer(this);
    timerUpdate = new QTimer(this);
    timerShoot = new QTimer(this);

    this->setEnabled(true);

    x = 300;
    y = 100;
    direction = 1; //on the right of the scene

    this->setPixmap(QPixmap(arrowPicPath).scaled(60, 60));
    this ->setPos(x, y);


    QObject::connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    QObject::connect(timerShoot, SIGNAL(timeout()), this, SLOT(shoot()));
    timerUpdate->start(30);

    timerShoot->start(30);
}

//SLOTS

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

void Arrow::shoot(){
    x-=3;

    if(x < 0){
        x = 0;
        timerShoot->stop();
    }

    this->setPos(x, y);



}



//KEY EVENTS
void Arrow:: keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Right){
        timerShoot->start(30);
        timerUpdate->stop();
    }
    timerShoot->start(30);

}
