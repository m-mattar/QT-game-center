#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

class Arrow : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Arrow(QObject *parent = nullptr);

    QString arrowPicPath = ":/game1images/arrow.png";

    int x, y, direction;

  //  QTimer * timerRotate;
    QTimer * timerUpdate;
    QTimer * timerShoot;

    void keyPressEvent(QKeyEvent * event);

signals:

public slots:
  //  void rotate();
    void update();
    void shoot();

};

#endif // ARROW_H
