#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

#include<QGraphicsScene>
#include<QGraphicsView>

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "loginpage.h"
#include "signuppage.h"

/*
    This class is the first thing that the user sees once he opens the game.
    the button slots are all implemented inside the maingview.cpp class in order to facilitate switching between the scenes.
*/
class MainWindow : public QGraphicsScene{
    Q_OBJECT
public:
    explicit MainWindow();

    Json json;

    // Widgets

    QLabel * helloLabel;
    QLabel * jokeLabel;
    QLabel * joke;

    QPushButton * loginButton;
    QPushButton * signupButton;
    QPushButton * guestButton;


    // Methods:
    void fixLabels();
    void fillScene();
    void playMusic();

    QString getJoke();


signals:



};

#endif // MAINWIDGET_H
