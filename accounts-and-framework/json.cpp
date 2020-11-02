#include "json.h"

Json::Json(){}

/*!
    Returns users.json as a QJsonDocument
*/
QJsonDocument Json::getJsonDocument(){
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll(), &jsonParseError);
    file.close();

    if(file.error() != QFile::NoError){
        qWarning("Parsing error!");
    }
    return jsonDocument;
}

/*!
    Takes a newly created user and appends it to the users.json document
*/
void Json::appendToUserDocument(QJsonObject user){
    QJsonDocument jsonDocument = getJsonDocument();
    QJsonArray usersArray = jsonDocument.array();
    usersArray.append(user);
    jsonDocument.setArray(usersArray);

    QFile file(filePath);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(jsonDocument.toJson());
    file.close();
}

/*!
    Checks if a user who attempted to login has already signed up before
    if the login was successful, returns the user as a QJsonObject
    else returns an empty QJSonObject
*/
QJsonObject Json::checkUser(QJsonArray &usersArray, QString &username, QString &password){
    int hashed = util.hashPassword(password);
    for(auto user : usersArray){
        if(user.toObject().value("Username") == username
                && user.toObject().value("Hashed Password").toInt() == hashed){
                return user.toObject();
        }
    }
    return QJsonObject();
}

void Json::updateUserScores(QString username, QVector<int> gameScores, char gameNumber){
    QJsonDocument jsonDocument = getJsonDocument();
    QJsonArray usersArray = jsonDocument.array();

    //get scores as JSON
    QJsonArray res;
    for (int i: gameScores) {
         res.append(QJsonValue(i));
    }

    //search for user

//    for(auto user : usersArray){

//        if(user.toObject().value("Username") == username){
//            user.toObject().value("game" + QString(gameNumber) + "_score") = res;
//        }
//    }

    jsonDocument.setArray(usersArray);

    QFile file(filePath);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(jsonDocument.toJson());
    file.close();
}

/*!
    Takes a picture, encodes it, and returns the corresponding hashed QJsonValue
*/
QJsonValue Json::EncodeImage(const QPixmap &p){
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    p.save(&buffer, "PNG");
    auto const encoded = buffer.data().toBase64();
    return {QLatin1String(encoded)};
}

/*!
    Takes a QJsonValue corresponding to a picture, decodes it, and returns the corresponding QPixmap
*/
QPixmap DecodeImage(QJsonValue val) {
  auto const encoded = val.toString().toLatin1();
  QPixmap p;
  p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
  return p;
}


