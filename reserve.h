#ifndef RESERVE_H
#define RESERVE_H

#include <QWidget>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class reserve;
}

class reserve : public QWidget
{
    Q_OBJECT

public:
    explicit reserve(QWidget *parent = nullptr);
    ~reserve();

private slots:
    void on_reserve_pushButton_clicked();

private:
    Ui::reserve *ui;
};

#endif // RESERVE_H
