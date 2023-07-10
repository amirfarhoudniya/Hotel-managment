#include "loginpage.h"
#include "staffpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    loginPage w;
//    w.show();
    staffPanel w;
    w.show();

    //init dateBase
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataBase.db");
    db.open();

    return a.exec();
}
