#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QObject>
#include <QtWidgets>
#include <QGraphicsScene>

#include "../accounts-and-framework/user.h"
#include "rollingbg.h"

class Game1scene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit Game1scene();

    RollingBg * rollingbg;
    QPushButton * homeButton;

    //will be initialized upon entering the page
    User * curUser = NULL;

    void fixWidgets();
    void fillScene();

signals:

public slots:
    void connectButtons();

};

#endif // GAME1SCENE_H
