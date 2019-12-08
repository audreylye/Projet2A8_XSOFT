# Projet2A8_XSOFT
Créer un logiciel qui répond aux attentes de la compagnie aérienne 
#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class conge

{
 public:
    conge();
    conge(int,QString,QString,QString,QString);
    QString get_motif();
    QString get_date_debut();
    QString get_date_fin();
    QString get_type();
    int get_id();

     bool ajouter();
     bool modifier(int);
     QSqlQueryModel * afficher();
     bool supprimer(int);
     bool trier();
     bool chercher(QString);
private:
    QString motif,date_debut,date_fin,type;
    int id;
};


#endif // CONGE_H
