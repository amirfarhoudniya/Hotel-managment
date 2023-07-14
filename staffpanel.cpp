#include "staffpanel.h"
#include "ui_staffpanel.h"

staffPanel::staffPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffPanel)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:darkcyan ;");
    setCentralWidget(ui->tabWidget);

    ui->calendarWidget->setCursor(Qt::PointingHandCursor);




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

staffPanel::~staffPanel()
{
    delete ui;
}

void staffPanel::on_room100_pushButton_clicked()
{
    ui->room_lineEdit->setText("100");
}


void staffPanel::on_room101_pushButton_clicked()
{
    ui->room_lineEdit->setText("101");
}


void staffPanel::on_room102_pushButton_clicked()
{
    ui->room_lineEdit->setText("102");
}


void staffPanel::on_room103_pushButton_clicked()
{
    ui->room_lineEdit->setText("103");
}


void staffPanel::on_room104_pushButton_clicked()
{
    ui->room_lineEdit->setText("104");
}


void staffPanel::on_room105_pushButton_clicked()
{
    ui->room_lineEdit->setText("105");
}


void staffPanel::on_room106_pushButton_clicked()
{
    ui->room_lineEdit->setText("106");
}


void staffPanel::on_room107_pushButton_clicked()
{
    ui->room_lineEdit->setText("107");
}


void staffPanel::on_room108_pushButton_clicked()
{
    ui->room_lineEdit->setText("108");
}


void staffPanel::on_room109_pushButton_clicked()
{
    ui->room_lineEdit->setText("109");
}


void staffPanel::on_room110_pushButton_clicked()
{
    ui->room_lineEdit->setText("110");
}


void staffPanel::on_room111_pushButton_clicked()
{
    ui->room_lineEdit->setText("111");
}


void staffPanel::on_room200_pushButton_clicked()
{
    ui->room_lineEdit->setText("200");
}


void staffPanel::on_room201_pushButton_clicked()
{
    ui->room_lineEdit->setText("201");
}


void staffPanel::on_room202_pushButton_clicked()
{
    ui->room_lineEdit->setText("202");
}


void staffPanel::on_room203_pushButton_clicked()
{
    ui->room_lineEdit->setText("203");
}


void staffPanel::on_room204_pushButton_clicked()
{
    ui->room_lineEdit->setText("204");
}


void staffPanel::on_room205_pushButton_clicked()
{
    ui->room_lineEdit->setText("205");
}


void staffPanel::on_room206_pushButton_clicked()
{
    ui->room_lineEdit->setText("206");
}


void staffPanel::on_room207_pushButton_clicked()
{
    ui->room_lineEdit->setText("207");
}


void staffPanel::on_room208_pushButton_clicked()
{
    ui->room_lineEdit->setText("208");
}


void staffPanel::on_room209_pushButton_clicked()
{
    ui->room_lineEdit->setText("209");
}


void staffPanel::on_room210_pushButton_clicked()
{
    ui->room_lineEdit->setText("210");
}


void staffPanel::on_room211_pushButton_clicked()
{
    ui->room_lineEdit->setText("211");
}


void staffPanel::on_room300_pushButton_clicked()
{
    ui->room_lineEdit->setText("300");
}


void staffPanel::on_room301_pushButton_clicked()
{
    ui->room_lineEdit->setText("301");
}


void staffPanel::on_room302_pushButton_clicked()
{
    ui->room_lineEdit->setText("302");
}


void staffPanel::on_room303_pushButton_clicked()
{
    ui->room_lineEdit->setText("303");
}


void staffPanel::on_room304_pushButton_clicked()
{
    ui->room_lineEdit->setText("304");
}


void staffPanel::on_room305_pushButton_clicked()
{
    ui->room_lineEdit->setText("305");
}


void staffPanel::on_room306_pushButton_clicked()
{
    ui->room_lineEdit->setText("306");
}


void staffPanel::on_room307_pushButton_clicked()
{
    ui->room_lineEdit->setText("307");
}


void staffPanel::on_room308_pushButton_clicked()
{
    ui->room_lineEdit->setText("308");
}


void staffPanel::on_room309_pushButton_clicked()
{
    ui->room_lineEdit->setText("309");
}


void staffPanel::on_room310_pushButton_clicked()
{
    ui->room_lineEdit->setText("310");
}


void staffPanel::on_room311_pushButton_clicked()
{
    ui->room_lineEdit->setText("311");
}

