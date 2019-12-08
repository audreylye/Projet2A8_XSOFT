# Projet2A8_XSOFT
Créer un logiciel qui répond aux attentes de la compagnie aérienne 
#include "conge.h"
#include "ui_conge.h"

conge::conge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conge)
{
    ui->setupUi(this);
}

conge::~conge()
{
    delete ui;
}

int id ;
QString motif;
QString date_debut;
QString date_fin;
QString type;


conge::conge()
{
id=0;
motif="";
date_debut="";
date_fin="";
type="";
}
conge::conge(int id,QString motif,QString date_debut,QString date_fin,QString type)
{
  this->id=id;
  this->motif=motif;
  this->date_debut=date_debut;
  this->date_fin=date_fin;
  this->type=type;
}
QString conge::get_motif(){return  motif;}
QString conge::get_date_debut(){return date_debut;}
QString conge::get_date_fin(){return date_fin;}
QString conge::get_type(){return type;}

bool conge::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO clients (id, MOTIF, DATE_DEBUT, DATE_FIN, TYPE) "
                    "VALUES (:id, :motif, :date_debut, :date_fin, :type)");
query.bindValue(":id", res);
query.bindValue(":motif", motif);
query.bindValue(":date_debut", date_debut);
query.bindValue(":date_fin", date_fin);
query.bindValue(":type", type);

return    query.exec();
}

bool conge::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("UPDATE CONGES SET MOTIF=:motif,DATE_DEBUT=:date_debut,DATE_FIN=:date_fin,TYPE=:type,ROLE=:role, WHERE ID=:id");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":tel_agent", tel_agent);
query.bindValue(":role", role);
query.bindValue(":id_conge", id_conge);
query.bindValue(":type_conge", type_conge);

return    query.exec();
}

QSqlQueryModel * conge::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CONGES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("motif "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_debut"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

    return model;
}

QSqlQueryModel * conge::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("motif "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_debut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

    return model;
}

bool conge::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CONGES where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
