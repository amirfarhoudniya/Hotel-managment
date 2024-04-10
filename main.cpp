#include "loginpage.h"
#include "staffpanel.h"
#include "chooseoption.h"
#include <QApplication>
#include <dataBase.h>

#include "addstaff.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   loginPage w;
   w.show();

//    staffPanel *s = new staffPanel();
//    s->show();

    // staffPanel::instance().show();


    //init dateBase
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataBase.db");
    db.open();


    return a.exec();
}
