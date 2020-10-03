#ifndef USER_H
#define USER_H

#include "json.h"

#include<QObject>
#include<QDate>
#include<QImage>
#include<QJsonObject>
#include<QVector>


class User : public QObject {
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    explicit User(QJsonObject userJson);

    void read(const QJsonObject & json);
    void write(QJsonObject & json) const;

    bool isUnique();
    bool isValid();
    QJsonObject toJsonObject();
    QJsonArray getScoresAsJson(QVector<int>& scores);

    Json json;

    QString firstName;
    QString lastName;
    QString gender;
    QString username;
    QString dateOfBirth;
    QJsonValue picture;

    int hashedpassword;
    int age;
    int game1_highest = 0;
    int game2_highest = 0;

    QVector<int> game1_scores = {0,0,0,0,0} ;
    QVector<int> game2_scores = {0,0,0,0,0} ;

signals:

};

#endif // USER_H
