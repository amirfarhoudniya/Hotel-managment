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

    /************************************* check the fields **********************************************************/
    if (ui->firstName_lineEdit->text() == "") {
        ui->firstName_warning_label->setStyleSheet("color : red") ;
        ui->firstName_warning_label->setText("this field can not be empty !") ;
        return ;
    }

    if (ui->lastName_lineEdit->text() == "") {
        ui->lastName_warning_label->setStyleSheet("color : red") ;
        ui->lastName_warning_label->setText("this field can not be empty !") ;
        return ;
    }

    if (ui->id_lineEdit->text() == "") {
        ui->id_warning_label->setStyleSheet("color : red") ;
        ui->id_warning_label->setText("this field can not be empty !") ;
        return ;
    }

    /***************************************** Reserve mechanism ***********************************************/
    long long int randomNum = QRandomGenerator::global()->generate() % 1000000000000 ;
    long long int  reservationNumber = randomNum;

    //get the date and Data
    QString currentDate = QDate::currentDate().toString() ;
    int day = ui->calendarWidget->selectedDate().day();
    int month = ui->calendarWidget->selectedDate().month();
    int year = ui->calendarWidget->selectedDate().year();

    QSqlQuery query;
    //find reservation day
    query.prepare("SELECT * FROM reservation WHERE roomNumber = :roomNumber AND reservationYear = :year AND reservationMonth = :month AND reservationDay = :day") ;
    query.bindValue(":roomNumber" , roomNumber);
    query.bindValue(":year" , year);
    query.bindValue(":month" , month);
    query.bindValue(":day" , day);

    if(query.exec() && query.next()) {
        QSqlRecord record = query.record();

        //has room reserved for this time ?
        if(record.value("reservationYear").toInt() == year && record.value("reservationMonth").toInt() == month &&  record.value("reservationDay").toInt() == day){
            QMessageBox::information(this , "notice" , "the room is reserved in this time .") ;
            return ;
        }
    } else {
        //know the status of that room
        // status 0: Ready , 1: reserved , 2:unchecked and 3: under maintance
        query.prepare("SELECT * FROM rooms WHERE roomNumber = :roomNumber ");
        query.bindValue(":roomNumber", roomNumber );
        if(query.exec() && query.next()){
            QSqlRecord record = query.record();
            if(QDate::currentDate().day() == day && QDate::currentDate().month() == month && QDate::currentDate().year() == year) {
                // if the room status is not "Ready" , get away.
                    if(record.value("status") != 0 ){
                        QMessageBox::critical(this , "Error", "Room is not available");
                        return;
                    }
            }

            //if the room status is "Ready" , add the info the dataBase
            // status 0: Ready , 1: reserved , 2:unchecked and 3: under maintance

                QSqlQuery query1;
                //add resrvation to dataBase
                query1.prepare("INSERT INTO reservation ( reservationNumber , guestId , reservationDate , reservationYear, reservationMonth , reservationDay , roomNumber ) VALUES (? , ? , ? , ? , ? , ? , ?)");
                query1.addBindValue(QString::number(reservationNumber));
                query1.addBindValue(id);
                query1.addBindValue(currentDate);
                query1.addBindValue(year);
                query1.addBindValue(month);
                query1.addBindValue(day);
                query1.addBindValue(roomNumber);
                query1.exec();

                QSqlQuery query3;
                //add guest to dataBase
                query3.prepare("INSERT INTO guests ( name , familyName , id  ) VALUES (? , ? , ?)");
                query3.addBindValue(firstName);
                query3.addBindValue(lastName);
                query3.addBindValue(id);
                query3.exec();

                QSqlQuery query4;
                //reserve room
                query4.prepare("UPDATE rooms SET status = '1' WHERE roomNumber = :roomNumber ");
                query4.bindValue(":roomNumber", roomNumber);
                query4.exec();

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

        }else {
            QMessageBox::information(this , " " , "the query does't exist !") ;
        }
    }
}

