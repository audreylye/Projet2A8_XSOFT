#include "client.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include <QSqlQueryModel>

#include <QFileDialog>
#include <QApplication>
#include <QTextStream>
#include <QInputDialog>
#include <QIODevice>
#include <QTextDocument>
#include <QFile>



class ClientData : public QSharedData
{
public:

};

Client::Client() : data(new ClientData)
{

}

Client::Client(const Client &rhs) : data(rhs.data)
{

}

Client &Client::operator=(const Client &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Client::~Client()
{

}



bool Client::modifier_client(QString NOM,QString PRENOM,QString NUMPASSPORT,QString DN,QString TEL,QString ADDRESSE,QString EMAIL,QString NBRVOLS,QString SEXE)
{
    QSqlQuery query;
        query.prepare("update CLIENT SET  NOM=?,PRENOM=?,NUMPASSPORT=?,DN=?,TEL=?,ADDRESSE=?,EMAIL=?,NBRVOLS=?,SEXE=? where NUMPASSPORT=?");
        query.addBindValue(NOM);
          query.addBindValue(PRENOM);
           query.addBindValue(NUMPASSPORT);
           query.addBindValue(DN);
           query.addBindValue(TEL);
           query.addBindValue(ADDRESSE);
           query.addBindValue(EMAIL);
             query.addBindValue(NBRVOLS);
              query.addBindValue(SEXE);
              query.addBindValue(NUMPASSPORT);




        query.exec();

       if(query.exec())
          {QMessageBox::information(NULL,"modification","modification terminee");}
            else
           QMessageBox::information(NULL,"modification","ERREUR");
}
void  Client::client1(QString txt)
{
    QSqlQuery q;
    q.prepare("select * from CLIENT where NUMPASSPORT='"+txt+"'  ")  ;

    if(q.exec()){
    while (q.next()) {
       NOM = q.value(0).toString();
       PRENOM = q.value(1).toString();
         NUMPASSPORT = q.value(2).toString();
         DN= q.value(3).toString();
     TEL= q.value(4).toString();
     ADDRESSE= q.value(5).toString();
     EMAIL = q.value(6).toString();
     NBRVOLS = q.value(7).toString();
       SEXE = q.value(8).toString();




}}
}

int Client::nbclients()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
model->rowCount();
    int somme;
    somme=model->rowCount();
    // qDebug()<<somme;
    return somme ;

}

QSqlQuery Client::client2()
{
    QSqlQuery q;
    QString txt="vsqdv";
    q.prepare("select * from CLIENT where NUMPASSPORT='"+txt+"'  ")  ;

    if(q.exec()){
    while (q.next()) {
       NOM = q.value(0).toString();
       PRENOM = q.value(1).toString();
         NUMPASSPORT = q.value(2).toString();
         DN= q.value(3).toString();
     TEL= q.value(4).toString();
     ADDRESSE= q.value(5).toString();
     EMAIL = q.value(6).toString();
     NBRVOLS = q.value(7).toString();
       SEXE = q.value(8).toString();




}}
    qDebug()<<SEXE;

    return  q;

}



bool Client::ajouter_client(QString NOM,QString PRENOM,QString NUMPASSPORT,QString DN,QString TEL,QString ADDRESSE,QString EMAIL,QString NBRVOLS,QString SEXE)
{

    QSqlQuery qry ;

    qry.prepare("INSERT into CLIENT (NOM,PRENOM,NUMPASSPORT,DN,TEL,ADDRESSE,EMAIL,NBRVOLS,SEXE) VALUES (:NOM,:PRENOM,:NUMPASSPORT,:DN,:TEL,:ADDRESSE,:EMAIL,:NBRVOLS,:SEXE) ");
    qry.addBindValue( NOM);
    qry.addBindValue( PRENOM);
    qry.addBindValue( NUMPASSPORT);
    qry.addBindValue( DN);
    qry.addBindValue( TEL);
    qry.addBindValue( ADDRESSE);
    qry.addBindValue( EMAIL);
    qry.addBindValue( NBRVOLS);
    qry.addBindValue( SEXE);


 if(qry.exec())
    {

    qDebug()<<"ajouter ok \n";
    return true;
 }
 else return false ;
}



QSqlQueryModel * Client::afficherclient()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUMPASSPORT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEDENAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADDRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOMBREDEVOL"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("SEXE"));
    return model;
}





bool Client::supprimer_client(QString ch)
{
    QSqlQuery qry ;
    qry.prepare("DELETE from CLIENT where NUMPASSPORT= '"+ch+"' " );
 if(qry.exec())
    {

    qDebug()<<" supprimer ok  \n";
    return true ;
}
 else return false;
}



void Client::Trieclien(QTableView *tab)
      {
          QSqlQuery *qry=new QSqlQuery(QSqlDatabase::defaultConnection);
          QSqlQueryModel *model=new QSqlQueryModel;
          qry->prepare("select * from CLIENT ORDER BY NOM");
          if (qry->exec())
          {
              qDebug()<<"trie ok ";
             model->setQuery(*qry);
              tab->setModel(model);


          }

      }

void Client::chercher_client(QString codeabarre,QTableView * tab)
{  QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query ;

          QString cherche="%";
          cherche+=codeabarre+"%";
          model->setQuery("SELECT * FROM CLIENT where NOM like '"+cherche+"' or PRENOM like '"+cherche+"' or NUMPASSPORT like '"+cherche+"' or DN like '"+cherche+"'or TEL like '"+cherche+"'or ADDRESSE like '"+cherche+"'or EMAIL like '"+cherche+"' or NBRVOLS like '"+cherche+"' or SEXE like '"+cherche+"'    "  );
           tab->setModel(model);
}


