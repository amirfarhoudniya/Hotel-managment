#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class loginPage; }
QT_END_NAMESPACE

class loginPage : public QWidget
{
    Q_OBJECT

public:
    loginPage(QWidget *parent = nullptr);
    ~loginPage();

private:
    Ui::loginPage *ui;

private slots :
    void on_login_pushButton_clicked();

    void on_eye_pushButton_pressed();

    void on_eye_pushButton_released();
};
#endif // LOGINPAGE_H
