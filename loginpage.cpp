#include "loginpage.h"
#include "ui_loginpage.h"
#include "staffpanel.h"


QString loginPage::hierarchy = "manager";

loginPage::loginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);

    this->setWindowTitle("Login Page");

    //window icon
    this->setWindowIcon(QIcon(":/icons/icons/hotel.png"));

    //
    this->setStyleSheet("background-color: #8C52FF ");

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
//            QMessageBox::information(this, "Success", "Login successful");
            staffPanel *s = new staffPanel();
            s->show();
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

