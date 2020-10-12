#ifndef SYRINGE_H
#define SYRINGE_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Syringe : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Syringe(QObject *parent = nullptr);

    QString syringePicPath = ":/game1images/syringe.png";

    QTimer * timer;

    int x, y, direction;

signals:

public slots:
    void update();

};

#endif // SYRINGE_H
