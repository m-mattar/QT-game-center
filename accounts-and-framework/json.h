#ifndef JSON_H
#define JSON_H

#include<QtWidgets>
#include<QJsonDocument>

#include "util.h"

/*
This class acts as a utility wrapper to all functions related to accounts and JSON files
*/
class Json{
public:
    Json();

    QString filePath = "/home/eece435l/Desktop/435L/project-eece435l-game-center/JSON/users.json";
    //QString filePath = "/home/eece435l/Desktop/435L-Project/project-eece435l-game-center/JSON/users.json";
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
