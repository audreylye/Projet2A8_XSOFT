#include "connexion.h"
#include <QSqlError>
Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("mybase1");
                           db.setUserName("mehdi1");//inserer nom de l'utilisateur
                           db.setPassword("1234");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;


return  test;
}
void Connexion::fermerConnexion()
{db.close();}
