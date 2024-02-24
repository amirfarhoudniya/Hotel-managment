#include "staffpanel.h"
#include "ui_staffpanel.h"


int staffPanel::roomNumber = 0 ;
staffPanel *staffPanel::m_instance = nullptr ;


staffPanel::staffPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffPanel)
{
    ui->setupUi(this);

    // open data base
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataBase.db");
    db.open();

    //window icon
    this->setWindowIcon(QIcon(":/icons/icons/hotel.png"));

    //set first tab as main tab
    ui->tabWidget->setCurrentIndex(0);

    //connect listWidget Items in "Check Room" tab with handler
    connect(ui->uncheckedRooms_listWidget, &QListWidget::itemClicked, this, &staffPanel::handleUncheckedRoomItemClick);
    connect(ui->underMaintance_listWidget, &QListWidget::itemClicked, this, &staffPanel::handleUnderMaintanceItemClick);

    //choose option menu (runs when click on room pushButtons)
    cho = new chooseOption();

    //tabWidget's style
    this->setStyleSheet("QWidget {"
                        "  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #FF5757, stop: 1 #8C52FF);"
                        "}");
    ui->tabWidget->setTabText(0 , "Main");
    ui->tabWidget->setTabText(1 , "Reserve");
    ui->tabWidget->setTabText(2 , "Check Room");
    ui->tabWidget->setTabText(3 , "manager panel");
    setCentralWidget(ui->tabWidget);


    //label's style
    ui->numberOfGuests_label->setAlignment(Qt::AlignCenter);
    ui->numberOfGuests_label->setStyleSheet("color:balck");
    ui->numberOfGuests_label_2->setAlignment(Qt::AlignCenter);
    ui->numberOfGuests_label_2->setStyleSheet("color:black");
    ui->reservedRooms_label->setAlignment(Qt::AlignCenter);
    ui->reservedRooms_label->setStyleSheet("color:black");
    ui->reservedRooms_label_2->setAlignment(Qt::AlignCenter);
    ui->reservedRooms_label_2->setStyleSheet("color:black");

    ui->numberOfGuests_label_2->setStyleSheet("font-size : 34px ; bold ; color : red") ;
    ui->reservedRooms_label_2->setStyleSheet("font-size : 34px ; bold ; color : red") ;

    //pushButton's style
    ui->checkedRooms_pushButton->setCursor(Qt::PointingHandCursor);
    ui->checkedRooms_pushButton->setStyleSheet("background-color:lightGreen; color:black;");
    ui->uncheckedRooms_pushButton->setCursor(Qt::PointingHandCursor);
    ui->uncheckedRooms_pushButton->setStyleSheet("background-color:red; color:black;");
    ui->reserve_pushButton->setCursor(Qt::PointingHandCursor);
    ui->reserve_pushButton->setStyleSheet("background-color:gold; color:black ;");

    //frame's style
    ui->frame->setFrameStyle(QFrame::Panel | QFrame::Raised ) ;
    ui->frame->setStyleSheet("background-color:cyan;");
    ui->frame->setLineWidth(3);

    ui->frame_2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    ui->frame_2->setStyleSheet("background-color:orange;");
    ui->frame_2->setLineWidth(3);

    //styles of listWidgets in check Room tab
    ui->uncheckedRooms_listWidget->setStyleSheet("font-family: Times New Roman; font-size: 20px;");
    ui->underMaintance_listWidget->setStyleSheet("font-family: Times New Roman; font-size: 20px;");
    ui->uncheckedRooms_listWidget->setCursor(Qt::PointingHandCursor);
    ui->underMaintance_listWidget->setCursor(Qt::PointingHandCursor);


    //styles of manager panel tab
    ui->staffs_listWidget->setStyleSheet("font-family: Times New Roman; font-size: 20px;");
    ui->addStaffs_pushButton->setStyleSheet("font-family: Times New Roman; font-size: 20px; border-radius:10px; background-color:yellow");
    ui->deleteStaffs_pushButton->setStyleSheet("font-family: Times New Roman; font-size: 20px; border-radius:10px; background-color:red");
    ui->addStaffs_pushButton->setCursor(Qt::PointingHandCursor) ;
    ui->deleteStaffs_pushButton->setCursor(Qt::PointingHandCursor);

    if(loginPage::hierarchy == "manager") {
        ui->tabWidget->setTabEnabled(3 , true);
    } else {
        ui->tabWidget->setTabEnabled(3 , false);
    }

//    addStaff a;
//    connect(&a, &addStaff::closed, this, &staffPanel::refreshTabs);




    //refresh showing data in tabs
    refreshTabs();

}

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




void staffPanel::on_reserve_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void staffPanel::on_tabWidget_tabBarClicked()
{
    refreshTabs();
}

void staffPanel::handleUnderMaintanceItemClick(QListWidgetItem *item)
{
    // Get the clicked item's text
    QString clickedItemText = item->text();
    QSqlQuery query ;
    QStringList parts = clickedItemText.split(' ');
    QString roomNumber = parts.first();
    query.prepare("SELECT * FROM rooms where roomNumber = :roomNumber");
    query.bindValue(":roomNumber" , roomNumber);

    if(query.exec() && query.next()) {
        QSqlRecord record = query.record();
        QMessageBox::information(this , roomNumber ,
                                 record.value("details").toString() );
    }

    int ret = QMessageBox::question(this , "" , "Room is ready ?" , QMessageBox::Yes , QMessageBox::No) ;

    if(ret == QMessageBox::Yes) {
        query.prepare("SELECT * FROM rooms where roomNumber = :roomNumber");
        query.bindValue(":roomNumber" , roomNumber);
        if(query.exec() && query.next()) {
            query.prepare("UPDATE rooms SET status = '0' WHERE roomNumber = :roomNumber");
            query.bindValue(":roomNumber" , roomNumber);
            query.exec() ;
            QMessageBox::information(this , "" , "done") ;
        }
    } else {
        return ;
    }
    refreshTabs();
}

void staffPanel::handleUncheckedRoomItemClick(QListWidgetItem *item)
{
    // Get the clicked item's text
    QString clickedItemText = item->text();
    QSqlQuery query ;
    QStringList parts = clickedItemText.split(' ');
    QString roomNumber = parts.first();

    int ret  =  QMessageBox::question(this , "" , "Room checked ? " , QMessageBox::Yes , QMessageBox::Cancel);

    if(ret == QMessageBox::Yes) {

        query.prepare("SELECT * FROM rooms where roomNumber = :roomNumber");
        query.bindValue(":roomNumber" , roomNumber);
        if(query.exec() && query.next()) {
            query.prepare("UPDATE rooms SET status = '0' WHERE roomNumber = :roomNumber");
            query.bindValue(":roomNumber" , roomNumber);
            query.exec() ;
            QMessageBox::information(this , "" , "done") ;
        }
    } else {
        return ;
    }
    refreshTabs();
}

int staffPanel::refreshTabs() {

    QSqlQuery query;
    int day = QDate::currentDate().day();
    int month = QDate::currentDate().month();
    int year = QDate::currentDate().year();

    /********************************* update the guest number frame ***********************************************/
    query.prepare("SELECT COUNT(*) FROM reservation WHERE reservationYear = :year AND reservationMonth = :month AND reservationDay = :day") ;
    query.bindValue(":year" , year) ;
    query.bindValue(":month" , month) ;
    query.bindValue(":day" , day) ;

    if(query.exec() && query.next()) {
        //show the number of guests
        ui->numberOfGuests_label_2->setText(query.value(0).toString()) ;
    } else {
        QMessageBox::information(this , "" , query.lastError().text()) ;
    }

    /********************************* update the resered room frame ***********************************************/
    query.prepare("SELECT COUNT(*) FROM rooms WHERE status = 1") ;

    if(query.exec() && query.next()) {
        //show the number of reserved room in frame
        ui->reservedRooms_label_2->setStyleSheet("font-size : 34px ; bold ; color : red") ;
        ui->reservedRooms_label_2->setText(query.value(0).toString()) ;
    } else {
        QMessageBox::information(this , "" , query.lastError().text()) ;
    }

    /**************************** update unchecked / undermaintance listWidget *************************************/
    //unchecked Rooms
    ui->uncheckedRooms_listWidget->clear();
    query.prepare("SELECT * FROM rooms WHERE status = 2");
    if (query.exec()) {
        while(query.next()) {
            QSqlRecord record = query.record();
            QString itemText = record.value("roomNumber").toString();
            QListWidgetItem *item = new QListWidgetItem(itemText);
            ui->uncheckedRooms_listWidget->addItem(item);
        }

    }else {
        // Handle the error if the query fails
        QMessageBox::information(this , "" , query.lastError().text()) ;
        return -1;
    }

    //underMaintance Rooms
    ui->underMaintance_listWidget->clear();
    query.prepare("SELECT * FROM rooms WHERE status = 3");
    if (query.exec()) {
        while(query.next()) {
            QSqlRecord record = query.record();
            QString itemText = record.value("roomNumber").toString() + QString("\n Reason : ") + record.value("details").toString();
            QListWidgetItem *item = new QListWidgetItem(itemText);
            ui->underMaintance_listWidget->addItem(item);
        }

    }else {
        // Handle the error if the query fails
        QMessageBox::critical(this , "" , query.lastError().text()) ;
        return -1;
    }

    /******************************************* staffs listWidget ***************************************************/
    ui->staffs_listWidget->clear();
    query.prepare("SELECT * FROM staffs");
    if(query.exec()) {
        while (query.next()) {
            QSqlRecord record = query.record() ;
            QString firstName = record.value("name").toString();
            QString lastName = record.value("lastName").toString();
            QString itemText = QString(QString(firstName ) + " " + QString(lastName)) ;
            QListWidgetItem *item = new QListWidgetItem(itemText);
            ui->staffs_listWidget->addItem(item);
        }
    } else {
        QMessageBox::critical(this , "" , query.lastError().text());
        return -1;
    }

    return 1 ;
}

staffPanel &staffPanel::instance()
{
    if(!m_instance) {
        m_instance = new staffPanel() ;
    }
    return *m_instance ;
}


void staffPanel::on_addStaffs_pushButton_clicked()
{
    addStaff *a = new addStaff() ;
    a->show();
}

void staffPanel::on_deleteStaffs_pushButton_clicked()
{
    ui->staffs_listWidget->currentItem() ;
}
