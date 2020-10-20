#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QObject>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QTimer>

#include "../accounts-and-framework/user.h"
#include "rollingbg.h"
#include "viruslarge.h"
#include "syringe.h"
#include "arrow.h"


class Game1scene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit Game1scene();

    RollingBg * rollingbg;
    Syringe * syringe;
    Arrow * arrow;
    VirusLarge * virusLarge;

    QPushButton * homeButton;
    QPushButton * startButton;

    QGraphicsPixmapItem * gameName;
    QGraphicsPixmapItem * circle;

    QTimer * gameNameTimer;
    int gameNamey = 130;

    //will be initialized upon entering the page
    User * curUser = NULL;

    void fixWidgets();
    void fillScene();
    void connectButtons();
    void addCircle();

signals:

public slots:
    void startGame();
    void updateGameName();

};

#endif // GAME1SCENE_H
