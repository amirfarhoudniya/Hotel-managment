#include "undermaintance.h"
#include "ui_undermaintance.h"

underMaintance::underMaintance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::underMaintance)
{
    ui->setupUi(this);

    ui->roomNumber_label->setAlignment(Qt::AlignCenter);
    ui->roomNumber_label->setText(QString::number(staffPanel::roomNumber));
    ui->roomNumber_label->setStyleSheet("font-size:24px ; color : red");

    ui->plainTextEdit->setPlaceholderText("reason .. ");

    QSqlQuery query;
    //Find the selected date's note
    query.prepare("SELECT details FROM rooms WHERE roomNumber = :roomNumber ");
    query.bindValue(":roomNumber ", staffPanel::roomNumber );

    if(query.exec() && query.next()){
        //find the detail of selected room and set to plainText
        QSqlRecord record = query.record();
        ui->plainTextEdit->setPlainText(record.value("details").toString());
    }
}

underMaintance::~underMaintance()
{
    delete ui;
}

void underMaintance::on_apply_pushButton_clicked()
{
        QSqlQuery query;

        QMessageBox msgBox ;
        msgBox.setText(QString("Room Number : ") + QString::number(staffPanel::roomNumber) );
        msgBox.setInformativeText("make the room status under maintance ?") ;
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No) ;
        msgBox.setDefaultButton(QMessageBox::Yes);
        int _ret = msgBox.exec();

        if(_ret == QMessageBox::Yes) {
            //room status going to be under maintance
            // status 0 : Ready , 1: reserved , 2:unchecked and 3 : under maintance
            query.prepare("UPDATE rooms SET status = '3' , details = :detail WHERE roomNumber = :roomNumber ");
            query.bindValue(":roomNumber", staffPanel::roomNumber);
            query.bindValue(":detail" , ui->plainTextEdit->toPlainText());
            query.exec();
            this->close();
        }else{
            return ;
        }
}

