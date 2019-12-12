#include "ajouter_ag.h"
#include <QDebug>

ajouter_ag::ajouter_ag()
{
nb_employee=0;
nom="";
lieu="";
}
ajouter_ag::ajouter_ag(QString nom,QString lieu,int nb_employee)
{
    this->nom = nom;
    this->lieu = lieu;
    this->nb_employee= nb_employee;
}
QString ajouter_ag::get_nom(){return  nom;}
QString ajouter_ag::get_lieu(){return lieu;}
int ajouter_ag::get_nb(){return  nb_employee;}
bool ajouter_ag::ajouter(QString nom,QString lieu,int nb_employee)
{
QSqlQuery query;
QString res= QString::number(nb_employee);
query.prepare("INSERT INTO agence (NOM,LIEU,NB_EMPLOYEE) "
                    "VALUES (:nom, :lieu, :nb_employee)");
query.bindValue(":nom", nom);
query.bindValue("lieu",lieu);
query.bindValue(":nb_employee", res);
return    query.exec();
}
QSqlQueryModel * ajouter_ag::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from agence order by nom desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("lieu"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    return model;
}

bool ajouter_ag::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from agence where NB_EMPLOYEE = :nb_employee ");
query.bindValue(":nb_employee", res);
return    query.exec();
}
bool ajouter_ag::modifier(QString nom,QString lieu,int nb_employee)
{

    QSqlQuery Q;
    Q.prepare("UPDATE agence SET nom=:nom_nouv ,lieu=:lieu_nouv WHERE nb_employee=:nb_employee");
    Q.bindValue(":lieu_nouv", lieu);
    Q.bindValue(":nom_nouv", nom);
    Q.bindValue(":nb_employee", nb_employee);


   return  Q.exec();
}

QSqlQueryModel * ajouter_ag::recherche(int valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM agence WHERE nb_employee LIKE :valeur order by NB_EMPLOYEE ");
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    return model;
}

