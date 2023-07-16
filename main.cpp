#include "loginpage.h"
#include "staffpanel.h"
#include "chooseoption.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    loginPage w;
//    w.show();

    staffPanel w;
    w.show();


//    chooseOption *cho = new chooseOption ;
//    cho->show();

    //init dateBase
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataBase.db");
    db.open();

    return a.exec();
}
