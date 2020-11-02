#include "viruslarge.h"

VirusLarge::VirusLarge(QObject *parent, int levelSpeed): QObject(parent) {
    timer = new QTimer(this);
    timerSpeed = levelSpeed;

    //random type
    virusType = rand() % 3 + 1;

    int randBit = rand() % 2;
    if(randBit == 1){
        x = 100;
    }else{
        x = 400;
    }
    y = 100;

    // 1 = large virus
    // 2 = medium virus
    // 3 = small virus
    if(virusType == 1){
        virusScore = 3;
        picturePath = ":/game1images/virus-green.png";
        this->setPixmap(QPixmap(picturePath).scaled(100, 100));

    } else if(virusType == 2){
        virusScore = 5;
        picturePath = ":/game1images/virus-pink.png";
        this->setPixmap(QPixmap(picturePath).scaled(70, 70));

    } else{
        virusScore = 7;
        picturePath = ":/game1images/virus-purple.png";
        this->setPixmap(QPixmap(picturePath).scaled(50, 50));

    }

    this ->setPos(x, y);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(timerSpeed);
}

void VirusLarge::update(){
    y+= 2;
    setPos(x,y);

    if(y>800){
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem *> list = collidingItems() ;
    foreach(QGraphicsItem * i , list){
        Syringe * item= dynamic_cast<Syringe *>(i);
        if (item){
            this->collidedWithSyringe();
        }
    }

    if(y > 700){
        userFailed();
    }


}

void VirusLarge::collidedWithSyringe(){
    this->setPixmap(QPixmap(smashedPicPath).scaled(100, 100));
    QTimer * timerCollided = new QTimer(this);

    emit collision();

    timerCollided->start(500);
    connect(timerCollided, &QTimer::timeout, [this]{
        scene()->removeItem((this));
        delete this;
    });
}

void VirusLarge::userFailed(){
    timer->stop();
    emit failure();
}
