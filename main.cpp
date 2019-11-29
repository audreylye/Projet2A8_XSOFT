#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion  c;
    try {
        c.createConnection();
        w.show();
    } catch (QString s) {
       qDebug()<<s;
    }
    return a.exec();
}
