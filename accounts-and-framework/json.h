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

    QString filePath = "/media/sf_SharedFolder-EECE435L/Project-game-center/game-center/JSON/users.json";
    Util util;
    QJsonDocument getJsonDocument();
    void appendToUserDocument(QJsonObject user);
    QJsonObject checkUser(QJsonArray & usersArray,QString & username,QString& password);

    QJsonValue EncodeImage(const QPixmap &p);
    QPixmap DecodeImage(QJsonValue val);
};

#endif // JSON_H
