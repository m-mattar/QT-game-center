#include "rollingbg.h"

RollingBg::RollingBg(QWidget *parent)
    : QWidget(parent)
    , background(":/game1images/vessel.png")
{
    background = background.scaled(400, 1600);
    timer = new QTimer(this);
    width = 400;
    height = background.height()/2;

    //timer SLOT, responsible for the rolling movement of RollingBg
    connect(timer, &QTimer::timeout, [this]{
        offset += 2;
        if (offset >= height)
            offset = 0;

        update();
    });

    resize(width, height);
    timer -> start(timerSpeed);
}

RollingBg::~RollingBg(){}

/*!
	A function to create a QPainter and draw on it	
*/
void RollingBg::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawPixmap(0, 0, background, 0, height - offset, width, height);
}
