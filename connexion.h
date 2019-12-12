#ifndef CONNEXION_H
#define CONNEXION_H

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>

class connexion
{
private:

public:
    connexion();

    QSqlDatabase db;

    bool createConnection();

};
#endif // CONNEXION_H
