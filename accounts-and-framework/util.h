#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QString>
#include <string>
#include <QHash>

/*
    A utility class that contains various useful functions
*/
class Util : public QObject
{
    Q_OBJECT
public:
    explicit Util(QObject *parent = nullptr);
    int hashPassword(QString password);
    bool checkPassword(QString password);

signals:

public slots:
};

#endif // UTIL_H
