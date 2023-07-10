#include "staffpanel.h"
#include "ui_staffpanel.h"

staffPanel::staffPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffPanel)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:gray ; color : gold");
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
