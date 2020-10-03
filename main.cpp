#include<QApplication>

#include "maingview.h"
#include <QGraphicsView>
#include <QMediaPlayer>

#include "accounts-and-framework/signuppage.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    MainGView * gview = new MainGView();

    gview -> setFixedSize(800, 800);
    gview -> show();

    return app.exec();

}
