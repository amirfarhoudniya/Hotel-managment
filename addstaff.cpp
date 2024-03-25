#include "addstaff.h"
#include "ui_addstaff.h"
#include "staffpanel.h"




addStaff::addStaff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStaff)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color : gray");
    this->setWindowTitle("add/edit staffs");

    //roles in hotel
    ui->role_comboBox->addItem("janitor") ;
    ui->role_comboBox->addItem("doorkeeper") ;
    ui->role_comboBox->addItem("counter manager") ;
    ui->role_comboBox->addItem("cheff") ;
    ui->role_comboBox->addItem("Procurement Manager") ;
    ui->role_comboBox->addItem("procurement officer") ;
    ui->role_comboBox->addItem("manager") ;

    setStyles();

}


addStaff::~addStaff()
{
    delete ui;
}


void addStaff::on_add_pushButton_clicked()
{
    if(checkFields() == false) {
        return ;
    }

    QString firstName = ui->firstName_lineEdit->text();
    QString lastName = ui->lastName_lineEdit->text() ;
    QString id = ui->id_lineEdit->text() ;
    QString brithYear = ui->year_lineEdit->text() ;
    QString phoneNumber = ui->phoneNumber_lineEdit->text() ;
    QString userName = ui->userName_lineEdit->text() ;
    QString password = ui->password_lineEdit->text() ;
    QString role = ui->role_comboBox->currentText() ;


    QSqlQuery query ;
    query.prepare("INSERT INTO staffs ( name , lastName , id , phoneNumber , brithYear , userName , password , hierarchy ) "
                  "VALUES (? , ? , ? , ? , ? , ? , ? , ?)");
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(id);
    query.addBindValue(phoneNumber) ;
    query.addBindValue(brithYear) ;
    query.addBindValue(userName) ;
    query.addBindValue(password) ;
    query.addBindValue(role) ;

    int ret = QMessageBox::information(this, "" , "Are you sure ? " , QMessageBox::Yes , QMessageBox::No);

    if(ret == QMessageBox::Yes) {
        query.exec() ;
        QMessageBox::information(this , "" , "done");
        staffPanel::instance().refreshTabs();
        this->close();
    } else {
        return ;
    }

}


bool addStaff::checkFields()
{
    //check for empty fields
    if(ui->firstName_lineEdit->text() == "") {
        ui->firstName_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                              "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->firstName_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }
    if(ui->lastName_lineEdit->text() == "") {
        ui->lastName_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                              "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->lastName_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }
    if(ui->id_lineEdit->text() == "") {
        ui->id_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                       "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->id_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }
    if(ui->year_lineEdit->text() == "") {
        ui->year_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                         "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->year_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }
    if(ui->phoneNumber_lineEdit->text() == "") {
        ui->phoneNumber_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                                "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->phoneNumber_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }
    if(ui->userName_lineEdit->text() == "") {
        ui->userName_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                             "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->userName_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }
    if(ui->password_lineEdit->text() == "") {
        ui->password_lineEdit->setStyleSheet("border-radius:10px; background-color:white; color:black; "
                                             "; font-family: Times New Roman; font-size:14px; color: red;") ;
        ui->password_lineEdit->setPlaceholderText("this field can not be empty!");
       return false ;
    }

    return true ;
}



void addStaff::setStyles()
{
    //styles
    ui->firstName_lineEdit->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->lastName_lineEdit->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->id_lineEdit->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->year_lineEdit->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->phoneNumber_lineEdit ->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->userName_lineEdit->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->password_lineEdit->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->role_comboBox->setStyleSheet("border-radius:10px ; background-color:white ; color:black ; font-family: Times New Roman ; font-size:20px");
    ui->add_pushButton->setStyleSheet("border-radius:5px ; background-color:yellow ; color:black ; font:bold ; font-family: Times New Roman ; font-size:16px");
    ui->add_pushButton->setCursor(Qt::PointingHandCursor);
}


void addStaff::on_firstName_lineEdit_cursorPositionChanged()
{
    setStyles();
}

void addStaff::on_lastName_lineEdit_cursorPositionChanged()
{
    setStyles();
}

void addStaff::on_id_lineEdit_cursorPositionChanged()
{
    setStyles();
}

void addStaff::on_year_lineEdit_cursorPositionChanged()
{
    setStyles();
}

void addStaff::on_phoneNumber_lineEdit_cursorPositionChanged()
{
    setStyles();
}

void addStaff::on_userName_lineEdit_cursorPositionChanged()
{
    setStyles();
}

void addStaff::on_password_lineEdit_cursorPositionChanged()
{
    setStyles();
}




