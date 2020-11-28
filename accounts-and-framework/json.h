#ifndef JSON_H
#define JSON_H

#include<QtWidgets>
#include<QJsonDocument>

#include "util.h"

class Json{
public:
    Json();

    QString filePath = "/home/eece435l/Desktop/435L/project-eece435l-game-center/JSON/users.json";
    //QString filePath = "/media/sf_SharedFolder-EECE435L/Project-game-center/game-center/JSON/users.json";
    //QString filePath = "../JSON/users.json";
    Util util;
    QJsonDocument getJsonDocument();
    void appendToUserDocument(QJsonObject user);
    void updateUserScores(QString username, QVector<int> gameScores, int highscore, int gameNumber);
    QJsonObject checkUser(QJsonArray & usersArray,QString & username,QString& password);

    QJsonValue EncodeImage(const QPixmap &p);
    QPixmap DecodeImage(QJsonValue val);
};

#endif // JSON_H
