#include "connexion.h"
#include <QDebug>

connexion::connexion( )
{

}
bool connexion::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("selim");
    db.setPassword("esprit");
    if(!db.open())
    {
        qDebug() << "ERROR CANNOT CONNECT TO DATABASE..." ;
        return false;
    }
    else
    {
        qDebug()<< "CONNECTION ESTABLISHED TO DATABASE..." ;
        return true;
    }
}
