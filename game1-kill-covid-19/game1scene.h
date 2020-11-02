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
    QGraphicsPixmapItem * gameOver;
    QGraphicsPixmapItem * gameWon;
    QGraphicsPixmapItem * circle;

    QTimer * gameNameTimer;
    QTimer * gameOverTimer;
    QTimer * gameWonTimer;
    int gameNamey = 130, gameOvery = 130, gameWony = 130;

    //will be initialized upon entering the page
    User * curUser = NULL;


    QLabel * highscoreL;
    QLabel * currentScoreL;
    QLabel * scoreHistoryL;
    QLabel * scoreHistory;
    int highscore = 0;
    int currentScore = 0;
    int countLarge = 0, countMedium = 0, countSmall = 0;
    int counter = 0;
    int levelSpeed = 50;

    void fixWidgets();
    void fillScene();
    void setScoreLabels();
    void connectButtons();
    void addCircle();
    void displayScores();
    void addVirus();
    void updateUserScores();
    void increaseLevel();
    void userWon();
    void cleanPage();

private:
    void keyPressEvent(QKeyEvent * event);


signals:

public slots:
    void startGame();
    void updateGameName();
    void updateGameOver();
    void updateGameWon();
    void collisionVirusSyring();
    void userFailed();

};

#endif // GAME1SCENE_H
