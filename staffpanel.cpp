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

    //window title
    this->setWindowTitle("Hotel Managment");

    //set first tab as main tab
    ui->tabWidget->setCurrentIndex(0);

    //connect listWidget Items in "Check Room" tab with handler
    connect(ui->uncheckedRooms_listWidget, &QListWidget::itemClicked, this, &staffPanel::handleUncheckedRoomItemClick);
    connect(ui->underMaintance_listWidget, &QListWidget::itemClicked, this, &staffPanel::handleUnderMaintanceItemClick);

    //choose option menu (runs when click on room pushButtons)
    cho = new chooseOption();


    // Set the background image using stylesheets
    backgroundImage.load(":/pics/pics/black-and-gold-marble-quartz-worktops-granite.jpg");
    backgroundImage = backgroundImage.scaled(this->size() ,  Qt::IgnoreAspectRatio );

    // Create a palette and set the background image
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
    ui->tabWidget->setPalette(palette);

    //tab widget's style
    ui->tabWidget->setStyleSheet("color:yellow");
    ui->tabWidget->setTabText(0 , "Main");
    ui->tabWidget->setTabText(1 , "Reserve");
    ui->tabWidget->setTabText(2 , "Check Room");
    ui->tabWidget->setTabText(3 , "manager panel");
    ui->tabWidget->tabBar()->setCursor(Qt::PointingHandCursor);
    setCentralWidget(ui->tabWidget);
    ui->tab_3->setLayout(ui->gridLayout_4);


    //label's style
    ui->numberOfGuests_label->setAlignment(Qt::AlignCenter);
    ui->numberOfGuests_label->setStyleSheet("color:balck");
    ui->numberOfGuests_label_2->setAlignment(Qt::AlignCenter);
    ui->reservedRooms_label->setAlignment(Qt::AlignCenter);
    ui->reservedRooms_label->setStyleSheet("color:black");
    ui->reservedRooms_label_2->setAlignment(Qt::AlignCenter);
    ui->numberOfGuests_label_2->setStyleSheet("font-size : 34px ; bold ; color : red") ;
    ui->reservedRooms_label_2->setStyleSheet("font-size : 34px ; bold ; color : red") ;

    //pushButton's style
    ui->checkedRooms_pushButton->setCursor(Qt::PointingHandCursor);
    ui->checkedRooms_pushButton->setStyleSheet("background-color:lightGreen; color:black;");
    ui->uncheckedRooms_pushButton->setCursor(Qt::PointingHandCursor);
    ui->uncheckedRooms_pushButton->setStyleSheet("background-color:red; color:black;");
    ui->reserve_pushButton->setCursor(Qt::PointingHandCursor);
    ui->reserve_pushButton->setStyleSheet("background-color:gold; color:black;");

    //frame's style
    ui->frame->setFrameStyle(QFrame::Panel | QFrame::Raised);
    ui->frame->setStyleSheet("background-color:cyan; border-radius:15px;");
    ui->frame->setLineWidth(3);
    ui->frame->setAttribute(Qt::WA_StyleSheet, false);
    ui->reserve_pushButton->setAttribute(Qt::WA_StyleSheet, false);

    //top status frame's style
    // Create a QVBoxLayout to hold the QLabel widgets
    QVBoxLayout *layout = new QVBoxLayout(ui->frame);
    // Add a spacer item at the top to add distance
    QSpacerItem *topSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(topSpacer);
    // Add numberOfGuests_label to the layout and center-align it
    layout->addWidget(ui->numberOfGuests_label, 0, Qt::AlignCenter);
    // Add a small spacer item between the labels
    QSpacerItem *smallSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);
    layout->addItem(smallSpacer);
    // Add numberOfGuests_label_2 to the layout and center-align it
    layout->addWidget(ui->numberOfGuests_label_2, 0, Qt::AlignCenter);
    // Create a spacer item at the bottom to add distance
    QSpacerItem *bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(bottomSpacer);
    // Set the layout as the frame's layout
    ui->frame->setLayout(layout);

    //top status frame's style
    ui->frame_2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    ui->frame_2->setStyleSheet("background-color:orange; border-radius:15px;");
    ui->frame_2->setLineWidth(3);
    // Create a QVBoxLayout to hold the QLabel widgets
    QVBoxLayout *layout2 = new QVBoxLayout(ui->frame_2);
    // Add a spacer item at the top to add distance
    QSpacerItem *topSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout2->addItem(topSpacer2);
    // Add numberOfGuests_label to the layout and center-align it
    layout2->addWidget(ui->reservedRooms_label, 0, Qt::AlignCenter);
    // Add a small spacer item between the labels
    QSpacerItem *smallSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);
    layout2->addItem(smallSpacer2);
    // Add numberOfGuests_label_2 to the layout and center-align it
    layout2->addWidget(ui->reservedRooms_label_2, 0, Qt::AlignCenter);
    // Create a spacer item at the bottom to add distance
    QSpacerItem *bottomSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout2->addItem(bottomSpacer2);
    // Set the layout as the frame's layout
    ui->frame_2->setLayout(layout2);

    //styles of listWidgets in check Room tab
    ui->uncheckedRooms_listWidget->setStyleSheet("font-family: Times New Roman; font-size: 20px;");
    ui->underMaintance_listWidget->setStyleSheet("font-family: Times New Roman; font-size: 20px;");
    ui->uncheckedRooms_listWidget->setCursor(Qt::PointingHandCursor);
    ui->underMaintance_listWidget->setCursor(Qt::PointingHandCursor);


    //styles of manager panel tab
    ui->staffs_listWidget->setStyleSheet("font-family: Times New Roman; font-size: 20px;");
    ui->addStaffs_pushButton->setStyleSheet("font-family: Times New Roman; font-size:20px; "
                                            "border-radius:10px; background-color:yellow; color:black");
    ui->deleteStaffs_pushButton->setStyleSheet("font-family: Times New Roman; font-size: 20px;"
                                               "border-radius:10px; background-color:red; color:black");
    ui->addStaffs_pushButton->setCursor(Qt::PointingHandCursor) ;
    ui->deleteStaffs_pushButton->setCursor(Qt::PointingHandCursor);

    if(loginPage::hierarchy == "manager") {
        ui->tabWidget->setTabEnabled(3 , true);
    } else {
        ui->tabWidget->setTabEnabled(3 , false);       
    }

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


void staffPanel::refreshTabs() {

    QSqlQuery query;
    int day = QDate::currentDate().day();
    int month = QDate::currentDate().month();
    int year = QDate::currentDate().year();
    QBarSet *set0 = new QBarSet("Rooms");

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
        return ;
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
        return ;
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
        return ;
    }

    /****************************************** chart view *********************************************************/
    //clear chartItems and widget
    QLayoutItem* chartLayoutItem = ui->chart_gridLayout->takeAt(0);
    if (chartLayoutItem) {
        delete chartLayoutItem->widget();
        delete chartLayoutItem;
    }

    query.prepare("SELECT COUNT(*) FROM rooms WHERE status = 0");
    if(query.exec() && query.next()) {
        set0->append(query.value(0).toInt());
    }

    query.prepare("SELECT COUNT(*) FROM rooms WHERE status = 1");
    if(query.exec() && query.next()) {
        set0->append(query.value(0).toInt());
    }

    query.prepare("SELECT COUNT(*) FROM rooms WHERE status = 2");
    if(query.exec() && query.next()) {
        set0->append(query.value(0).toInt());
    }

    query.prepare("SELECT COUNT(*) FROM rooms WHERE status = 3");
    if(query.exec() && query.next()) {
        set0->append(query.value(0).toInt());
    }


    // make series of dataSets
        QBarSeries *series = new QBarSeries();
        series->append(set0);

    // make chart
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Room status");
        chart->setAnimationOptions(QChart::SeriesAnimations);

    // categories of chart
        QStringList categories;
        categories << "ready" << "reserved" << "unchecked" << "underMaintance" ;

    // configure axisX of chart
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

    // configure axisY of chart
        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,36);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    // add chart to chartView
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->chart_gridLayout->addWidget(chartView) ;
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

    // Get the clicked item's text
    QString clickedItemText = ui->staffs_listWidget->currentItem()->text() ;
    QSqlQuery query ;
    QStringList parts = clickedItemText.split(' ');
    QString name = parts.first();
    QString lastName = parts.last() ;

    query.prepare("DELETE FROM staffs where name = :name AND lastName = :lastName");
    query.bindValue(":name" , name);
    query.bindValue(":lastName" , lastName);

    if(query.exec()) {
           QMessageBox::information(this , "" , "done");
    } else {
        QMessageBox::information(this , "" , query.lastError().text());
    }

    refreshTabs();

}

void staffPanel::on_checkedRooms_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void staffPanel::on_uncheckedRooms_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void staffPanel::resizeEvent(QResizeEvent* event)
{
    // Calculate the new size for the background image
    QPixmap scaledImage = backgroundImage.scaled(event->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, scaledImage);
    this->setPalette(palette);
    ui->tabWidget->setPalette(palette);

    // Call the base class implementation of resizeEvent
    QWidget::resizeEvent(event);
}


void staffPanel::on_tabWidget_tabBarClicked(int index)
{
    if(loginPage::hierarchy != "manager" && !ui->tabWidget->isTabEnabled(index)) {
        QMessageBox::critical(this , "" , "access denied !");
    }
}




