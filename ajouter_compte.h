#ifndef AJOUTER_COMPTE_H
#define AJOUTER_COMPTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ajouter_compte
{
public:
    ajouter_compte();
    ajouter_compte(QString,int,int);
    QString get_username();
    int get_password();
    int get_id();
        bool ajouter(QString username,int password,int id);
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(QString username,int password,int id);
        QSqlQueryModel * recherche(int);

    private:
        QString username;
        int password,id;
};

#endif // AJOUTER_COMPTE_H
