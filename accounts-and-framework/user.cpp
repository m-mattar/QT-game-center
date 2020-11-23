#include "user.h"


User::User(QObject *parent) : QObject(parent) {
}

/*!
    Returns a user from the users.json
*/
User::User(QJsonObject result){
    firstName = result["First Name"].toString();
    lastName = result["Last Name"].toString();
    username = result["Username"].toString();
    gender = result["Gender"].toString();
    age = result["Age"].toInt();
    dateOfBirth = result["Date of birth"].toString() ;
    hashedpassword = result["Hashed Password"].toInt();
    picture = QJsonValue(result["picture"].toString());
    game1_highest = result["game1_highest"].toInt();
    game2_highest = result["game2_highest"].toInt();

    // Filling game 1 scores
    QVector<int> v1;
    QJsonArray arr1 = result["game1_score"].toArray();
    v1.clear();
    v1.reserve(arr1.size());
    for (int i = 0; i < arr1.size(); ++i) {
        v1.push_back(arr1[i].toInt());
    }
    game1_scores = v1;

    // Filling game 2 scores
    QVector<int> v2;
    QJsonArray arr2 = result["game2_score"].toArray();
    v2.clear();
    v2.reserve(arr2.size());
    for (int i = 0; i < arr2.size(); ++i) {
        v2.push_back(arr2[i].toInt());
    }
    game2_scores = v2;
}

QJsonObject User::toJsonObject(){
    QJsonObject result;
    result["First Name"] = firstName;
    result["Last Name"] = lastName;
    result["Username"] = username;
    result["Gender"] = gender;
    result["Age"] = age;
    result["Date of birth"] = dateOfBirth;
    result["Hashed Password"] = hashedpassword;
    result["picture"] = picture;
    result["game1_score"] = getScoresAsJson(game1_scores);
    result["game2_score"] = getScoresAsJson(game2_scores);
    result["game1_highest"] = this->game1_highest;
    result["game2_highest"] = this->game2_highest;
    return result;
}

bool User::isUnique(){
    QJsonDocument jsonDocument = json.getJsonDocument();
    QJsonArray usersArray = jsonDocument.array();
    for(auto user : usersArray){
        if(user.toObject().value("Username") == username) return false;
    }
    return true;
}

bool User::isValid(){

    if(
        this->firstName.isEmpty() ||
        this->lastName.isEmpty() ||
        this->gender.isEmpty() ||
        this->username.isEmpty() ||
        this->dateOfBirth.isEmpty()
       ) return false;
    return true;
}

QJsonArray User::getScoresAsJson(QVector<int>& scores){
    QJsonArray res;
    for (int i: scores) {
         res.append(QJsonValue(i));
    }
    return res;
}
