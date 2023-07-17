#include "reserve.h"
#include "ui_reserve.h"
#include "staffpanel.h"

reserve::reserve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reserve)
{
    ui->setupUi(this);

    //window icon
    this->setWindowIcon(QIcon(":/icons/icons/hotel.png"));

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

    static QRandomGenerator randomGenerator;
    quint64 randomNum = randomGenerator.generate64();
    quint64 reservationNumber = randomNum % 1000000000000;


    //get the date and Data
    QString currentDate = QDate::currentDate().toString() ;
    int day = ui->calendarWidget->selectedDate().day();
    int month = ui->calendarWidget->selectedDate().month();
    int year = ui->calendarWidget->selectedDate().year();

    QSqlQuery query;
    //add resrvation to dataBase
    query.prepare("INSERT INTO reservation ( reservationNumber , guestId , reservationDate , reservationYear, reservationMonth , reservationDay , roomNumber ) VALUES (? , ? , ? , ? , ? , ? , ?)");
    query.addBindValue(QString::number(reservationNumber));
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
    query3.prepare("UPDATE rooms SET status = '1' WHERE roomNumber = :roomNumber ");
    query3.bindValue(":roomNumber", roomNumber);
    query3.exec();

    QMessageBox msgBox ;
    msgBox.setText( QString("Name : " )+ QString(firstName) +
                                             QString("\n lastName : ")+ QString(lastName) +
                                             QString("\n reservationNumber : ")+ QString::number(reservationNumber) +
                                             QString("\n Room : ") + QString::number(roomNumber));
    msgBox.setStandardButtons(QMessageBox::Ok);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok) {
        this->close();
    }
}

