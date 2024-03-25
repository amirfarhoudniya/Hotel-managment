#ifndef UNDERMAINTANCE_H
#define UNDERMAINTANCE_H

#include <QWidget>
#include "staffpanel.h"

namespace Ui {
class underMaintance;
}

class underMaintance : public QWidget
{
    Q_OBJECT

public:
    explicit underMaintance(QWidget *parent = nullptr);
    ~underMaintance();

private slots:
    void on_apply_pushButton_clicked();

private:
    Ui::underMaintance *ui;
};

#endif // UNDERMAINTANCE_H
