#include "signuppage.h"

SignupPage::SignupPage(QWidget *parent) : QWidget(parent) {

   Header = new QLabel("Please Fill the Form Below to Sign Up");
   SignInLabel = new QLabel("Already Have an Account? ");

   FirstNameEdit = new QLineEdit();
   UsernameEdit = new QLineEdit();
   PasswordEdit = new QLineEdit();
   ConfirmPasswordEdit = new QLineEdit();
   SecondNameEdit = new QLineEdit();

   PasswordEdit ->setEchoMode(QLineEdit::Password);
   ConfirmPasswordEdit ->setEchoMode(QLineEdit::Password);


   AgeBox = new QSpinBox();
   DayBox = new QSpinBox();
   MonthBox = new QSpinBox();
   YearBox = new QSpinBox();
   YearBox->setMaximum(3000);

   GenderBox = new QComboBox();

   SignUpButton = new QPushButton("Sign Up!");
   SignInButton = new QPushButton("Sign In!");
   SelectImage = new QPushButton("Select an Image");

   GroupBox = new QGroupBox();

   //Header Setup
   QFont font = Header->font();
   font.setBold(true);
   font.setPixelSize(16);
   Header->setFont(font);

   // Layouts
   BoxLayout = new QVBoxLayout();
   FormLayout = new QFormLayout();
   DateLayout = new QHBoxLayout();
   SignInLayout = new QHBoxLayout();

   // DateLayout Setup
   DateLayout->addWidget(DayBox);
   DateLayout->addWidget(MonthBox);
   DateLayout->addWidget(YearBox);

   //SignIn Layout
   SignInLayout->addWidget(SignInLabel);
   SignInLayout->addWidget(SignInButton);

   FormLayout->addRow(tr("First Name "),FirstNameEdit);
   FormLayout->addRow(tr("Second Name "),SecondNameEdit);
   FormLayout->addRow(tr("Username "),UsernameEdit);
   FormLayout->addRow(tr("Profile Picture "),SelectImage);
   FormLayout->addRow(tr("Age "),AgeBox);
   GenderBox->addItem("Male");
   GenderBox->addItem("Female");
   FormLayout->addRow(tr("Gender "),GenderBox);
   FormLayout->addRow(tr("Birthday dd/MM/yyyy"),DateLayout);
   FormLayout->addRow(tr("Password "),PasswordEdit);
   FormLayout->addRow(tr("Confirm Password "),ConfirmPasswordEdit);
   FormLayout->setSpacing(10);

   //Overall Layout
   BoxLayout->addWidget(Header);
   BoxLayout->addItem(FormLayout);
   BoxLayout->addWidget(SignUpButton);
   BoxLayout->addItem(SignInLayout);

   // Set the Layout
   setLayout(BoxLayout);

   QObject::connect(SignUpButton,SIGNAL(clicked(bool)),this,SLOT(setUser()));
   QObject::connect(SelectImage,SIGNAL(clicked(bool)),this,SLOT(selectImage()));

}

/*
//////////////////////////////// METHODS ////////////////////////////////
*/

/*!
    called from the setUser() SLOT
    Reads the input from the widgets and attemps to create a new user
    if successful, returns the new user (not yet added to users.json)
    else, returns NULL
*/
User* SignupPage::createUser(){
    // checks if the password and ots confirmation are the same, otherwise, returns NULL
    if(PasswordEdit->text() != ConfirmPasswordEdit->text()){
        qWarning("password not matching");
        return NULL;
    }

    // a new instance of a user is created
    User* user = new User();
    user->firstName = FirstNameEdit->text();
    user->lastName = SecondNameEdit->text();
    user->username = UsernameEdit->text();
    user->gender = GenderBox->currentText();
    user->age = AgeBox->value();
    user->dateOfBirth = DayBox->text() + "/" + MonthBox->text() + "/" + YearBox->text();

    // use the util.hashPassword() function to get the hashed version of the user's password
    int hashedPassword = util.hashPassword(PasswordEdit->text());
    user->hashedpassword = hashedPassword;

    /*
     Take the profile picture of the user
     call the json.EncodeImage() method in order to return the corresponding QJsonValue
     updates the user->picture class member
    */
    QImage img;
    auto l = img.load(file_name);
    if(!l){
        qWarning("loading did not work");
    }
    auto pix = QPixmap::fromImage(img);
    auto val = json.EncodeImage(pix);
    user->picture = val;

    // checks if the user is unique, otherwise, deletes the attempted one and returns NULL
    if(!user->isUnique()){
        qWarning("Username already Taken");
        delete user;
        return NULL;
    }

    // if a QLineEdit was left empty, deletes the attempted user and returns NULL
    if(!user->isValid()){
       QMessageBox::information(this,"...","You left something empty!");
       delete user;
       return NULL;
    }

    // Checks if the user's password is secure or not
    if(!util.checkPassword(PasswordEdit->text())){
        qWarning("Password not strong enough");
        PasswordEdit->setText("Password not strong enough");
        PasswordEdit->setStyleSheet("color: red");
        delete user;
        return NULL;
    }

    //We get to this point only after passing all previous conditions
    //The user instance of the class (curUser) gets updated, and the newly created user gets returned
    this->curUser = user;
    return user;
}


/*
//////////////////////////////// SLOTS ////////////////////////////////
*/

/*!
    Called whenever the signup button is pressed
    calls createUser() in order to check all necessary conditions before adding a new user to the users.json file
    if createUser() returned a user, setUser() appends it to users.json
*/
void SignupPage::setUser(){
    User* user = createUser();
    if(user == NULL) return;

    QJsonObject userJsonObject = user -> toJsonObject();
    json.appendToUserDocument(userJsonObject);
}

/*!
    Takes profile picture file path from user
    updates the corresponding class member
*/
void SignupPage::selectImage(){
    this->file_name = QFileDialog::getOpenFileName(this,"Open a File","");
}

