#include "loginpage.h"
#include "ui_loginpage.h"
#include "staffpanel.h"


QString loginPage::hierarchy = "";

loginPage::loginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);

    //window title
    this->setWindowTitle("Login Page");

    //set fixed size for window
    this->setFixedSize(this->size());

    // Set the background image using stylesheets
    backgroundImage.load(":/pics/pics/black-and-gold-marble-quartz-worktops-granite.jpg");
    backgroundImage = backgroundImage.scaled(this->size() ,  Qt::IgnoreAspectRatio );

    // Create a palette and set the background image
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);


    //window icon
    this->setWindowIcon(QIcon(":/icons/icons/hotel.png"));

    //eye pushbutton's style
    ui->eye_pushButton->setIcon(QIcon(":/icons/icons/eye.png"));
    ui->eye_pushButton->setCursor(Qt::PointingHandCursor);

    //login pushbutton's style
    ui->login_pushButton->setCursor(Qt::PointingHandCursor) ;

    //set type password for lineEdit
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);


}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_login_pushButton_clicked()
{
    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM staffs WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        query.prepare("SELECT * FROM staffs WHERE password = :password");
        query.bindValue(":password", password);
        if (query.exec() && query.next()) {
            QSqlRecord record = query.record();
            if(record.value("hierarchy") == "manager") {
                hierarchy = "manager" ;
            }
            staffPanel::instance().show();
            this->close();
        }else{
            QMessageBox::critical(this , "login fail" , "uncorrect password !");
        }
    } else {
        QMessageBox::critical(this , "login fail" , "the username doesn't exist !");
    }
}


void loginPage::on_eye_pushButton_pressed()
{
    ui->password_lineEdit->setEchoMode(QLineEdit::Normal);
}

void loginPage::on_eye_pushButton_released()
{
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);
}


