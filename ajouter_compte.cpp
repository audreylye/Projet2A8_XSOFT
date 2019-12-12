#include "ajouter_compte.h"
#include <QDebug>
ajouter_compte::ajouter_compte()
{
password=0;
username="";
}
ajouter_compte::ajouter_compte(QString username,int password,int id)
{
    this->username = username;
    this->password = password;
    this->id= id;
}
QString ajouter_compte::get_username(){return  username;}
int ajouter_compte::get_password(){return password;}
int ajouter_compte::get_id(){return id;}
bool ajouter_compte::ajouter(QString username,int password,int id)
{
QSqlQuery query;
QString res= QString::number(password);
QString ret= QString::number(id);

query.prepare("INSERT INTO compte (USERNAME,PASSWORD,ID) "
                    "VALUES (:username, :password, :id)");
query.bindValue(":username", username);
query.bindValue(":password", res);
query.bindValue(":id", ret);

return    query.exec();
}
QSqlQueryModel * ajouter_compte::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from compte order by username asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("username"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));

    return model;
}
bool ajouter_compte::supprimer(int idf)
{
QSqlQuery query;
QString ret= QString::number(idf);
query.prepare("Delete from compte where ID = :id ");
query.bindValue(":id", ret);
return    query.exec();
}
bool ajouter_compte::modifier(QString username,int password,int id)
{

    QSqlQuery Q;
    Q.prepare("UPDATE compte SET username=:username_nouv ,password=:password_nouv WHERE id=:id");
    Q.bindValue(":username_nouv", username);
    Q.bindValue(":password_nouv", password);
    Q.bindValue(":id", id);


   return  Q.exec();
}
QSqlQueryModel * ajouter_compte::recherche(int valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM compte WHERE id LIKE :valeur order by ID ");
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("username"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id"));
    return model;
}
