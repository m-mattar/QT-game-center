#ifndef GAME2SCENE_H
#define GAME2SCENE_H

#include <QObject>
#include <QWidget>

class Game2scene {
    Q_OBJECT
public:
    Game2scene();

    QWidget *centralWidget;
};

#endif // GAME2SCENE_H
