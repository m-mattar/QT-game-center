#include "disk.h"

Disk::Disk(int x, int y, QWidget * parent){
    this->x = x;
    this->y = y;

    int i = 35 + 50 * x;
    int j = 35 + 50 * y;

    this->setGeometry(i, j, 50, 50);
}


void Disk::mousePressEvent(QMouseEvent * event) {
    emit isClicked(x, y);
}

//ClickableLabel::~ClickableLabel(){
//	this->hide();
//}
