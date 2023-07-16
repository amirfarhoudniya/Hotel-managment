#ifndef CHOOSEOPTION_H
#define CHOOSEOPTION_H

#include <QWidget>
#include <reserve.h>

namespace Ui {
class chooseOption;
}

class chooseOption : public QWidget
{
    Q_OBJECT

public:
    explicit chooseOption(QWidget *parent = nullptr);
    reserve *res ;
    ~chooseOption();

private slots:
    void on_reserve_pushButton_clicked();

    void on_release_pushButton_clicked();

    void on_check_pushButton_clicked();

    void on_maintenance_pushButton_clicked();

private:
    Ui::chooseOption *ui;
};

#endif // CHOOSEOPTION_H
