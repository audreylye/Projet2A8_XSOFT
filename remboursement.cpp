#include "remboursement.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
remboursement::remboursement()
{
nom="";
prenom="";
cin="";
indice=0;
}

void remboursement::set_nom(){nom="";}
void remboursement::set_prenom(){prenom="";}
void remboursement::set_cin(){cin="";}
void remboursement::set_indice()
{
    indice=0;
}

remboursement::remboursement(QString nom,QString prenom,QString cin, int indice)
{

  this->nom=nom;
  this->prenom=prenom;
     this->cin=cin;
    this->indice=indice;
}
QString remboursement::get_nom(){return  nom;}
QString remboursement::get_prenom(){return prenom;}
QString remboursement::get_cin(){return cin;}
int remboursement::get_indice(){return  indice;}

bool remboursement::ajouter()
{
QSqlQuery query;
QSqlDatabase db ;
QString res= QString::number(indice);
query.prepare("INSERT INTO remboursement ( NOM, PRENOM , CIN , INDICE) "
                    "VALUES (:nom, :prenom, :cin, :indice)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":cin", cin);
query.bindValue(":indice", res);
return    query.exec();
}

QSqlQueryModel * remboursement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from remboursement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("indice"));
    return model;
}

bool remboursement::supprimer(int indice)
{
    QSqlQuery query;
QString res= QString::number(indice);
query.prepare("Delete from remboursement where INDICE = :indice ");
query.bindValue(":indice", res);
return    query.exec();
}

bool remboursement::modifier ()
{
    QSqlQuery Q;
    Q.prepare("UPDATE remboursement SET nom=:nom_nouv , prenom=:prenom_nouv , cin=:cin_nouv WHERE indice=:indice");
    Q.bindValue (":nom_nouv", nom);
    Q.bindValue (":prenom_nouv", prenom);
    Q.bindValue (":cin_nouv", cin);
    Q.bindValue (":indice", indice);

    return Q.exec();
}

QSqlQueryModel* remboursement::chercher_remboursement(QString nom)
{  QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query ;

          QString cherche="%";
          cherche+=nom+"%";
          model->setQuery("SELECT * FROM remboursement where nom  like '"+cherche+"' or prenom like '"+cherche+"' or cin  like '"+cherche+"' or indice  like '"+cherche+"' " );
            return model;
}
QSqlQueryModel *  remboursement::Trieremboursement()
      {
          QSqlQuery *qry=new QSqlQuery(QSqlDatabase::defaultConnection);
          QSqlQueryModel *model=new QSqlQueryModel;
          qry->prepare("select * from REMBOURSEMENT ORDER BY INDICE");
          if (qry->exec())
          {
              qDebug()<<"trie fait ";
             model->setQuery(*qry);
              return model;
             }

      }
