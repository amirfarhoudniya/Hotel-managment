#include "reserve.h"
#include "ui_reserve.h"
#include "staffpanel.h"

reserve::reserve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reserve)
{
    ui->setupUi(this);

    ui->calendarWidget->setCursor(Qt::PointingHandCursor);
    ui->reserve_pushButton->setCursor(Qt::PointingHandCursor);


    ui->room_lineEdit->setText(QString::number(staffPanel::roomNumber));

}

reserve::~reserve()
{
    delete ui;
}

void reserve::on_reserve_pushButton_clicked()
{
    QString firstName = ui->firstName_lineEdit->text();
    QString lastName = ui->lastName_lineEdit->text();
    int id = ui->id_lineEdit->text().toInt() ;
    int roomNumber =  ui->room_lineEdit->text().toInt() ;

    QRandomGenerator randomGenerator;
    quint64 randomNum = randomGenerator.generate64();
    int reservationNumber = randomNum % 1000000000000;


    //get the date and Data
    QString currentDate = QDate::currentDate().toString() ;
    int day = ui->calendarWidget->selectedDate().day();
    int month = ui->calendarWidget->selectedDate().month();
    int year = ui->calendarWidget->selectedDate().year();

    QSqlQuery query;
    //add resrvation to dataBase
    query.prepare("INSERT INTO reservation ( reservationNumber , guestId , reservationDate , reservationYear, reservationMonth , reservationDay , roomNumber ) VALUES (? , ? , ? , ? , ? , ? , ?)");
    query.addBindValue(reservationNumber);
    query.addBindValue(id);
    query.addBindValue(currentDate);
    query.addBindValue(year);
    query.addBindValue(month);
    query.addBindValue(day);
    query.addBindValue(roomNumber);
    query.exec();

    QSqlQuery query2;
    //add guest to dataBase
    query2.prepare("INSERT INTO guests ( name , familyName , id  ) VALUES (? , ? , ?)");
    query2.addBindValue(firstName);
    query2.addBindValue(lastName);
    query2.addBindValue(id);
    query2.exec();

    QSqlQuery query3;
    //reserve room
    // status 0 : Ready , 1: reserved , 2:unchecked and 3 : under maintance
    query3.prepare("INSERT INTO rooms ( roomNumber , status ) VALUES (? , ?)");
    query3.addBindValue(staffPanel::roomNumber);
    query3.addBindValue(1);
    query3.exec();

    QMessageBox::information(this , "Reservation done !" ,  QString("Name : " )+ QString(firstName) +
                                                             QString("\n lastName : ")+ QString(lastName) +
                                                             QString("\n reservationNumber : ")+ QString::number(reservationNumber) +
                                                             QString("\n Room : ") + QString::number(roomNumber));
}

