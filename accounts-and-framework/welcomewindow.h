#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QObject>
#include<QGraphicsScene>
#include <QString>
#include <QtWidgets>

#include "user.h"
#include "json.h"

#include <QtWidgets>
#include <QPointF>
#include <QDate>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

/*
    this class acts an intermediate between the user and his games
    Once logged in/ signed up, a user is redirected here.
    He can view his last played games, his highscores and play new games.
*/
class WelcomeWindow : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit WelcomeWindow(QObject *parent = nullptr);

    User* curUser = NULL;
    Json json;

    QLabel * helloLabel;
    QLabel * happyBirthday;

    QGraphicsPixmapItem * game1Pic;
    QGraphicsPixmapItem * game2Pic;
    QGraphicsPixmapItem * profilePicture;

    QPushButton * game1Button;
    QPushButton * game2Button;
    QPushButton * homeButton;

    QLabel * game1Scores;
    QLabel * game2Scores;

    void fixPixmapItems();
    void fixWidgets();
    void fixLabels();
    void fillScene();
    void connectButtons();
    void checkBday();
    void updateProfilePic();
    void updateScores();

signals:

public slots:
    void playGame1();
    void playGame2();
};

#endif // WELCOMEWINDOW_H
