# Projet2A8_XSOFT
Créer un logiciel qui répond aux attentes de la compagnie aérienne 
#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Agent
{
public:
   Agent();
   Agent(int,QString,QString,int,int,int,QString,QString);
   QString get_nom();
   QString get_prenom();
   int get_age();
   int get_salaire();
   int get_tel_agent();
   QString get_role();
   QString get_type_conge();
   int get_id();

    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool trier();
    bool affecter_Agent(int ,QString );
    bool on_recherche_textChanged(const QString );
private:
   QString nom,prenom,role,type_conge;
   int id,age,salaire,tel_agent;
};

#endif // AGENT_H
