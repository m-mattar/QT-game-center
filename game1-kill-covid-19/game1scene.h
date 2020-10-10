#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QObject>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QTimer>

#include "../accounts-and-framework/user.h"
#include "rollingbg.h"
#include "viruslarge.h"


class Game1scene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit Game1scene();

    RollingBg * rollingbg;
    VirusLarge * virusLarge;

    QPushButton * homeButton;
    QPushButton * startButton;

    QGraphicsPixmapItem * gameName;

    QTimer * gameNameTimer;
    int gameNamey = 130;

    //will be initialized upon entering the page
    User * curUser = NULL;

    void fixWidgets();
    void fillScene();
    void connectButtons();

signals:

public slots:
    void startGame();
    void updateGameName();

};

#endif // GAME1SCENE_H
