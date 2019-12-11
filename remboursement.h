#ifndef REMBOURSEMENT_H
#define REMBOURSEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class remboursement
{public:
    remboursement();
    remboursement(QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_cin();
    int get_indice();

    void set_nom();
    void set_prenom();
    void set_cin();
    void set_indice();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * chercher_remboursement ( QString);
    QSqlQueryModel * Trieremboursement();


private:
    QString nom,prenom,cin;
    int indice;

};
#endif // REMBOURSEMENT_H
