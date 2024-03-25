#ifndef STAFFPANEL_H
#define STAFFPANEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlRecord>
#include <QListWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts>


#include "chooseoption.h"
#include "dataBase.h"
#include "addstaff.h"
#include "loginpage.h"

namespace Ui {
class staffPanel;
}

class staffPanel : public QMainWindow
{
    Q_OBJECT

public:

    chooseOption *cho ;
    static int roomNumber ;
    void refreshTabs();
    static staffPanel &instance() ;
    ~staffPanel();

private :
    explicit staffPanel(QWidget *parent = nullptr);
    staffPanel(const staffPanel&) = delete;
    staffPanel& operator=(const staffPanel&) = delete;
    static staffPanel* m_instance;



private slots:

    void handleUnderMaintanceItemClick(QListWidgetItem *item);

    void handleUncheckedRoomItemClick(QListWidgetItem *item);

    void on_tabWidget_tabBarClicked() ;

    void on_room100_pushButton_clicked();

    void on_room101_pushButton_clicked();

    void on_room102_pushButton_clicked();

    void on_room103_pushButton_clicked();

    void on_room104_pushButton_clicked();

    void on_room105_pushButton_clicked();

    void on_room106_pushButton_clicked();

    void on_room107_pushButton_clicked();

    void on_room108_pushButton_clicked();

    void on_room109_pushButton_clicked();

    void on_room110_pushButton_clicked();

    void on_room111_pushButton_clicked();

    void on_room200_pushButton_clicked();

    void on_room201_pushButton_clicked();

    void on_room202_pushButton_clicked();

    void on_room203_pushButton_clicked();

    void on_room204_pushButton_clicked();

    void on_room205_pushButton_clicked();

    void on_room206_pushButton_clicked();

    void on_room207_pushButton_clicked();

    void on_room208_pushButton_clicked();

    void on_room209_pushButton_clicked();

    void on_room210_pushButton_clicked();

    void on_room211_pushButton_clicked();

    void on_room300_pushButton_clicked();

    void on_room301_pushButton_clicked();

    void on_room302_pushButton_clicked();

    void on_room303_pushButton_clicked();

    void on_room304_pushButton_clicked();

    void on_room305_pushButton_clicked();

    void on_room306_pushButton_clicked();

    void on_room307_pushButton_clicked();

    void on_room308_pushButton_clicked();

    void on_room309_pushButton_clicked();

    void on_room310_pushButton_clicked();

    void on_room311_pushButton_clicked();

    void on_reserve_pushButton_clicked();

    void on_addStaffs_pushButton_clicked();

    void on_deleteStaffs_pushButton_clicked();

private:
    Ui::staffPanel *ui;
};





#endif // STAFFPANEL_H
