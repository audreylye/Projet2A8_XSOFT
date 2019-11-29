#ifndef AJOUTER_AG_H
#define AJOUTER_AG_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ajouter_ag
{
public:
    ajouter_ag();
    ajouter_ag(QString,QString,int);
    QString get_nom();
    QString get_lieu();
        int get_nb();
        bool ajouter(QString nom,QString lieu,int nb_employee);
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(QString nom,QString lieu,int nb_employee);
        QSqlQueryModel * recherche(int);

    private:
        QString nom,lieu;
        int nb_employee;
};

#endif // AJOUTER_AG_H
