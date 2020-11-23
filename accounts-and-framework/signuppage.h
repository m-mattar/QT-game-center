#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include "user.h"
#include "json.h"
#include "util.h"
#include "loginpage.h"

#include<QWidget>
#include<QtWidgets>
#include<QDebug>
#include<QJsonObject>
#include<QFileDialog>
#include <QImage>
#include <QMessageBox>

/*
    Signup form in order to create a new user
*/
class SignupPage : public QWidget
{
    Q_OBJECT
public:
    explicit SignupPage(QWidget *parent = nullptr);

    User* curUser = NULL;
    Json json;
    Util util;

    //widgets
    QLabel* Header;
    QLabel* SignInLabel;
    QLineEdit* FirstNameEdit;
    QLineEdit* SecondNameEdit;
    QLineEdit* UsernameEdit;
    QLineEdit* PasswordEdit;
    QLineEdit* ConfirmPasswordEdit;
    QComboBox* GenderBox;
    QSpinBox* AgeBox;
    QSpinBox* DayBox;
    QSpinBox* MonthBox;
    QSpinBox* YearBox;
    QPushButton* SignUpButton;
    QPushButton* SignInButton;
    QPushButton* SelectImage;

    // Layouts
    QVBoxLayout* BoxLayout;
    QFormLayout* FormLayout;
    QHBoxLayout* DateLayout;
    QHBoxLayout* SignInLayout;

    //Boxes
    QGroupBox* GroupBox;

    QString file_name;

    User* createUser();
    void cleanPage();

signals:

public slots:
    void setUser();
    void selectImage();
};

#endif // SIGNUPPAGE_H
