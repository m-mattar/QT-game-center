#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Arrow : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Arrow(QObject *parent = nullptr);

    QString arrowPicPath = ":/game1images/arrow.png";

    int x, y, direction;

  //  QTimer * timerRotate;
    QTimer * timerUpdate;

signals:

public slots:
  //  void rotate();
    void update();

};

#endif // ARROW_H
