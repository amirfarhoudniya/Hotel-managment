#include "staffpanel.h"
#include "ui_staffpanel.h"

int staffPanel::roomNumber = 0 ;

staffPanel::staffPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffPanel)
{
    ui->setupUi(this);

    //window icon
    this->setWindowIcon(QIcon(":/icons/icons/hotel.png"));

    cho = new chooseOption() ;



    this->setStyleSheet("background-color:darkcyan ;");
    setCentralWidget(ui->tabWidget);

    //
    ui->numberOfGuests_label->setAlignment(Qt::AlignCenter);
    ui->numberOfGuests_label->setStyleSheet("color:balck");
    ui->numberOfGuests_label_2->setAlignment(Qt::AlignCenter);
    ui->numberOfGuests_label_2->setStyleSheet("color:black");
    ui->unreservedRooms_label->setAlignment(Qt::AlignCenter);
    ui->unreservedRooms_label->setStyleSheet("color:black");
    ui->unreservedRooms_label_2->setAlignment(Qt::AlignCenter);
    ui->unreservedRooms_label_2->setStyleSheet("color:black");

    //
    ui->checkedRooms_pushButton->setCursor(Qt::PointingHandCursor);
    ui->checkedRooms_pushButton->setStyleSheet("background-color:lightGreen; color:black;");
    ui->uncheckedRooms_pushButton->setCursor(Qt::PointingHandCursor);
    ui->uncheckedRooms_pushButton->setStyleSheet("background-color:red; color:black;");
    ui->reserve_pushButton->setCursor(Qt::PointingHandCursor);
    ui->reserve_pushButton->setStyleSheet("background-color:gold; color:black ;");

    //
    ui->frame->setFrameStyle(QFrame::Panel | QFrame::Raised ) ;
    ui->frame->setStyleSheet("background-color:cyan;");
    ui->frame->setLineWidth(3);

    ui->frame_2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    ui->frame_2->setStyleSheet("background-color:orange;");
    ui->frame_2->setLineWidth(3);


}

//int staffPanel::getRoomNumber()
//{
//    return this->roomNumber ;
//}

//void staffPanel::setRoomNumber(int _value)
//{
//    this->roomNumber = _value ;
//}

staffPanel::~staffPanel()
{
    delete ui;
}

void staffPanel::on_room100_pushButton_clicked()
{
    roomNumber = 100;
//    this->setRoomNumber(100);
    cho->show() ;
}


void staffPanel::on_room101_pushButton_clicked()
{
    roomNumber = 101;
//    this->setRoomNumber(101);
    cho->show() ;
}


void staffPanel::on_room102_pushButton_clicked()
{
    roomNumber = 102;
//    this->setRoomNumber(102);
    cho->show() ;
}


void staffPanel::on_room103_pushButton_clicked()
{
    roomNumber = 103;
//    this->setRoomNumber(103);
    cho->show() ;
}


void staffPanel::on_room104_pushButton_clicked()
{
    roomNumber = 104;
//    this->setRoomNumber(104);
    cho->show() ;
}


void staffPanel::on_room105_pushButton_clicked()
{
    roomNumber = 105;
//    this->setRoomNumber(105);
    cho->show() ;
}


void staffPanel::on_room106_pushButton_clicked()
{
    roomNumber = 106;
//    this->setRoomNumber(106);
    cho->show() ;
}


void staffPanel::on_room107_pushButton_clicked()
{
    roomNumber = 107;
//    this->setRoomNumber(107);
    cho->show() ;
}


void staffPanel::on_room108_pushButton_clicked()
{
    roomNumber = 108;
//    this->setRoomNumber(108);
    cho->show() ;
}


void staffPanel::on_room109_pushButton_clicked()
{
    roomNumber = 109;
//    this->setRoomNumber(109);
    cho->show() ;
}


void staffPanel::on_room110_pushButton_clicked()
{
    roomNumber = 110;
//    this->setRoomNumber(110);
    cho->show() ;
}


void staffPanel::on_room111_pushButton_clicked()
{
    roomNumber = 111;
//    this->setRoomNumber(111);
    cho->show() ;
}


void staffPanel::on_room200_pushButton_clicked()
{
    roomNumber = 200;
//    this->setRoomNumber(200);
    cho->show() ;
}


void staffPanel::on_room201_pushButton_clicked()
{
    roomNumber = 201;
//    this->setRoomNumber(201);
    cho->show() ;
}


void staffPanel::on_room202_pushButton_clicked()
{
    roomNumber = 202;
//    this->setRoomNumber(202);
    cho->show() ;
}


void staffPanel::on_room203_pushButton_clicked()
{
    roomNumber = 203;
//    this->setRoomNumber(203);
    cho->show() ;
}


void staffPanel::on_room204_pushButton_clicked()
{
    roomNumber = 204;
//    this->setRoomNumber(204);
    cho->show() ;
}


void staffPanel::on_room205_pushButton_clicked()
{
    roomNumber = 205;
//    this->setRoomNumber(205);
    cho->show() ;
}


void staffPanel::on_room206_pushButton_clicked()
{
    roomNumber = 206;
//    this->setRoomNumber(206);
    cho->show() ;
}


void staffPanel::on_room207_pushButton_clicked()
{
    roomNumber = 207;
//    this->setRoomNumber(207);
    cho->show() ;
}


void staffPanel::on_room208_pushButton_clicked()
{
    roomNumber = 208;
//    this->setRoomNumber(208);
    cho->show() ;
}


void staffPanel::on_room209_pushButton_clicked()
{
    roomNumber = 209;
//    this->setRoomNumber(209);
    cho->show() ;
}


void staffPanel::on_room210_pushButton_clicked()
{
    roomNumber = 210;
//    this->setRoomNumber(210);
    cho->show() ;
}


void staffPanel::on_room211_pushButton_clicked()
{
    roomNumber = 211;
//    this->setRoomNumber(211);
    cho->show() ;
}


void staffPanel::on_room300_pushButton_clicked()
{
    roomNumber = 300;
//    this->setRoomNumber(300);
    cho->show() ;
}


void staffPanel::on_room301_pushButton_clicked()
{
    roomNumber = 301;
//    this->setRoomNumber(301);
    cho->show() ;
}


void staffPanel::on_room302_pushButton_clicked()
{
    roomNumber = 302;
//    this->setRoomNumber(302);
    cho->show() ;
}


void staffPanel::on_room303_pushButton_clicked()
{
    roomNumber = 303;
//    this->setRoomNumber(303);
    cho->show() ;
}


void staffPanel::on_room304_pushButton_clicked()
{
    roomNumber = 304;
//    this->setRoomNumber(304);
    cho->show() ;
}


void staffPanel::on_room305_pushButton_clicked()
{
    roomNumber = 305;
//    this->setRoomNumber(305);
    cho->show() ;
}


void staffPanel::on_room306_pushButton_clicked()
{
    roomNumber = 306;
//    this->setRoomNumber(306);
    cho->show() ;
}


void staffPanel::on_room307_pushButton_clicked()
{
    roomNumber = 307;
//    this->setRoomNumber(307);
    cho->show() ;
}


void staffPanel::on_room308_pushButton_clicked()
{
    roomNumber = 308;
//    this->setRoomNumber(308);
    cho->show() ;
}


void staffPanel::on_room309_pushButton_clicked()
{
    roomNumber = 309;
//    this->setRoomNumber(309);
    cho->show() ;
}


void staffPanel::on_room310_pushButton_clicked()
{
    roomNumber = 310;
//    this->setRoomNumber(310);
    cho->show() ;
}


void staffPanel::on_room311_pushButton_clicked()
{
    roomNumber = 311;
//    this->setRoomNumber(311);
    cho->show() ;
}



