#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlRecord>
#include <QCloseEvent>

#include "dataBase.h"


namespace Ui {
class addStaff;
}

class addStaff : public QWidget
{
    Q_OBJECT

public:
    explicit addStaff(QWidget *parent = nullptr);
    ~addStaff();


private slots:

    void on_add_pushButton_clicked();

    bool checkFields() ;

    void setStyles() ;

    void on_firstName_lineEdit_cursorPositionChanged();

    void on_lastName_lineEdit_cursorPositionChanged();

    void on_id_lineEdit_cursorPositionChanged();

    void on_year_lineEdit_cursorPositionChanged();

    void on_phoneNumber_lineEdit_cursorPositionChanged();

    void on_userName_lineEdit_cursorPositionChanged();

    void on_password_lineEdit_cursorPositionChanged();


private:
    Ui::addStaff *ui;

};

#endif // ADDSTAFF_H
