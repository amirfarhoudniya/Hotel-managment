#ifndef STAFFPANEL_H
#define STAFFPANEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>

namespace Ui {
class staffPanel;
}

class staffPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit staffPanel(QWidget *parent = nullptr);
    ~staffPanel();

private:
    Ui::staffPanel *ui;
};

#endif // STAFFPANEL_H
