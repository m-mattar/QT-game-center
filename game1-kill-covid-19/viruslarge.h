#ifndef VIRUSLARGE_H
#define VIRUSLARGE_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class VirusLarge: public QObject, public QGraphicsPixmapItem{
     Q_OBJECT
public:
    explicit VirusLarge(QObject *parent = nullptr);

    QString picturePath = ":/game1images/virus-green.png";
    QString smashedPicPath = ":/game1images/mike.png";

    bool smashed = false;

    int x, y;
    int virusType;

    QTimer * timer;

    void collidedWithSyringe();

signals:

public slots:
    void update();

};

#endif // VIRUSLARGE_H
