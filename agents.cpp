# Projet2A8_XSOFT
Créer un logiciel qui répond aux attentes de la compagnie aérienne 
La#include "agent.h"
#include "ui_agent.h"
#include "conge.h"

Agent::Agent()
{
 id=0;
 nom="";
 prenom="";
 age=0;
 salaire=0;
 tel_agent=0;
 role="";
 type_conge="";
}

Agent::Agent(int id,QString nom,QString prenom,int age,int salaire,int tel_agent,QString role,QString type_conge)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
  this->salaire=salaire;
  this->tel_agent=tel_agent;
  this->role=role;
  this->type_conge=type_conge;

}
QString Agent::get_nom(){return  nom;}
QString Agent::get_prenom(){return prenom;}
int Agent::get_age(){return age;}
int Agent::get_salaire(){return salaire;}
int Agent::get_tel_agent(){return tel_agent;}
QString Agent::get_role(){return role;}
QString Agent::get_type_conge(){return  type_conge;}

bool Agent::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Agent (id, NOM, PRENOM, AGE, SALAIRE, TEL_AGENT, ROLE, TYPE_CONGE) "
                    "VALUES (:id, :nom, :prenom, :AGE, :SALAIRE, :TEL_AGENT, :ROLE, :TYPE_CONGE)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":tel_agent", tel_agent);
query.bindValue(":role", role);
query.bindValue(":type_conge", type_conge);

return    query.exec();
}

bool Agent::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("UPDATE AGENTS SET NOM=:nom,PRENOM=:prenom,AGE=:age,TEL_AGENT=:tel_agent,ROLE=:role,TYPE_CONGE=:type_conge, WHERE ID=:id");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":tel_agent", tel_agent);
query.bindValue(":role", role);
query.bindValue(":type_conge", type_conge);

return    query.exec();
}

QSqlQueryModel * Agent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from AGENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("type_conge"));

    return model;
}

QSqlQueryModel * Agent::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Agent");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_conge"));

    return model;
}

bool Agent::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from AGENTS where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Agent::affecter_Agent(int id,QString role)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE agent SET role=:role WHERE ID=:id");
    query.bindValue(":id", res);
    query.bindValue(":role", role);

    return    query.exec();
}

QSqlQueryModel * Agent::chercher_Agent(QString nom)

{
    QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from agent where nom=:nom ");
query.bindValue(":nom", nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_conge"));

    return model;

bool Agent::on_tabWidget_3_destroyed()
{
    // trier
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM CONGE order by type ")  ;
    query2.exec();
    model->setQuery(query2);
    ui->tableView_2-> setModel(model);
}
