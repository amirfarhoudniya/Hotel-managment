#include "chooseoption.h"
#include "ui_chooseoption.h"
#include <QMessageBox>
#include "staffpanel.h"
#include <QSqlRecord>
#include "undermaintance.h"
#include <QInputDialog>

chooseOption::chooseOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseOption)
{
    ui->setupUi(this);
}

chooseOption::~chooseOption()
{
    delete ui;
}

void chooseOption::on_reserve_pushButton_clicked()
{
    res = new reserve();
    res->show();
    this->close();
}


void chooseOption::on_release_pushButton_clicked()
{

    int _roomNumber = staffPanel::roomNumber ;
    QSqlQuery query;

    query.prepare("SELECT status FROM rooms WHERE roomNumber = :roomNumber");
    query.bindValue(":roomNumber",_roomNumber);

    if(query.exec() && query.next()){
        QMessageBox msgBox ;
        msgBox.setText(QString("Room Number : ") + QString::number(_roomNumber) );
        msgBox.setInformativeText("Do you want to Release Room ?") ;
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No) ;
        msgBox.setDefaultButton(QMessageBox::Yes);
        int _ret = msgBox.exec();

        if(_ret == QMessageBox::Yes) {         
            QSqlQuery query2 ;
            // status 0 : Ready , 1: reserved , 2:unchecked and 3 : under maintance
            query2.prepare("UPDATE rooms SET status = '2' WHERE roomNumber = :roomNumber ");
            query2.bindValue(":roomNumber", _roomNumber);

            if(query2.exec()){
                QMessageBox::information(this, "Room Released", "Room has been released successfully.");
                this->close();
            }else{
                QMessageBox::warning(this, "Error", "Failed to release the room.");
            }
        }else {
            return ;
        }
    }
}


void chooseOption::on_check_pushButton_clicked()
{
    QSqlQuery query;

    QMessageBox msgBox ;
    msgBox.setText(QString("Room Number : ") + QString::number(staffPanel::roomNumber) );
    msgBox.setInformativeText("room has checked?") ;
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No) ;
    msgBox.setDefaultButton(QMessageBox::Yes);
    int _ret = msgBox.exec();

    if(_ret == QMessageBox::Yes) {
        //the room has checked by personels
        // status 0 : Ready , 1: reserved , 2:unchecked and 3 : under maintance
        query.prepare("UPDATE rooms SET status = '0' WHERE roomNumber = :roomNumber ");
        query.bindValue(":roomNumber", staffPanel::roomNumber);
        query.exec();
        this->close();
    }else{
        return ;
    }

}


void chooseOption::on_maintenance_pushButton_clicked()
{
    this->close();
    underMaintance *und = new underMaintance() ;
    und->show();

}


void chooseOption::on_deleteReservation_pushButton_clicked()
{
    QSqlQuery query;

    QString reservationNumber = QInputDialog::getText(this, "", "Reservation Number ?");

    query.prepare("SELECT COUNT(*) FROM reservation WHERE reservationNumber = :reservationNumber");
    query.bindValue(":reservationNumber",reservationNumber);

    if (query.exec() && query.next()){
        //if reservation Number exist, delete the reservation row
        if(query.value(0).toInt() > 0) {

            query.prepare("DELETE FROM reservation WHERE reservationNumber = :reservationNumber");
            query.bindValue(":reservationNumber",reservationNumber);

            if(query.exec()) {
                QMessageBox::information(this , " " , "Delete successfuly") ;
            } else {
                QMessageBox::information(this , "" , query.lastError().text()) ;
            }
        } else {
            QMessageBox::information(this , "" , "the reservation number invalid !") ;
        }
    }



}
