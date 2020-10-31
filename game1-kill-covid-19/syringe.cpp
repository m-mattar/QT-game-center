#include "syringe.h"

Syringe::Syringe(QObject *parent) : QObject(parent) {
    this->setPixmap(QPixmap(syringePicPath).scaled(20, 20));
}

