#include "carte.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include <QSqlQueryModel>
//#include "C:/Users/Salwa.Abbes/Avg/Desktop/clients/client.h"

#include <QFileDialog>
#include <QApplication>
#include <QTextStream>
#include <QInputDialog>
#include <QIODevice>
#include <QTextDocument>
#include <QFile>
class carteData : public QSharedData
{
public:

};

carte::carte() : data(new carteData)
{

}

carte::carte(const carte &rhs) : data(rhs.data)
{

}

carte &carte::operator=(const carte &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

carte::~carte()
{

}
bool carte::ajouter_carte(QString ID_FID ,QString POINTS,QString VALIDITE,QString OFFRES,QString NUMPASSEPORT)
{

    QSqlQuery qry ;

    qry.prepare("INSERT into carte (ID_FID,POINTS,VALIDITE,OFFRES,NUMPASSEPORT) VALUES (:ID_FID,:POINTS,:VALIDITE,:OFFRES,:NUMPASSEPORT) ");
    qry.addBindValue( ID_FID);
    qry.addBindValue( POINTS);
    qry.addBindValue( VALIDITE);
    qry.addBindValue( OFFRES);
    qry.addBindValue(NUMPASSEPORT);



 if(qry.exec())
    {

    qDebug()<<"ajouter ok \n";
    return true;
 }
 else return false ;
}



bool carte::supprimer_carte(QString ch)
{
    QSqlQuery qry ;
    qry.prepare("DELETE from CARTE where ID_FID= '"+ch+"' " );
 if(qry.exec())
    {

    qDebug()<<" supprimer ok  \n";
    return true ;
}
 else return false;
}




QSqlQueryModel * carte::affichercarte()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CARTE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_fid"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("points"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("validiter"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numpasseport"));

    return model;
}



bool carte::modifier_carte(QString ID_FID,QString POINTS,QString VALIDITE,QString OFFRES,QString NUMPASSEPORT)
{
    QSqlQuery query;
        query.prepare("update CARTE SET  ID_FID=?,POINTS=?,VALIDITE=?,OFFRES=?,NUMPASSEPORT=? where NUMPASSEPORT=?");
        query.addBindValue(ID_FID);
          query.addBindValue(POINTS);
           query.addBindValue(VALIDITE);
           query.addBindValue(OFFRES);
           query.addBindValue(NUMPASSEPORT);

              query.addBindValue(NUMPASSEPORT);




        query.exec();

       if(query.exec())
          {QMessageBox::information(NULL,"modification","modification terminee");}
            else
           QMessageBox::information(NULL,"modification","ERREUR");
}

QSqlQueryModel *  carte::TriecarteC()
      {
          QSqlQuery *qry=new QSqlQuery(QSqlDatabase::defaultConnection);
          QSqlQueryModel *model=new QSqlQueryModel;
          qry->prepare("select * from CARTE ORDER BY ID_FID");
          if (qry->exec())
          {
              qDebug()<<"trie ok ";
             model->setQuery(*qry);
              return model;


          }

      }





QSqlQueryModel * carte::cherchercarte(QString ID_FID)
{  QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query ;

          QString cherche="%";
          cherche+=ID_FID+"%";
          model->setQuery("SELECT * FROM CARTE where ID_FID like '"+cherche+"' or POINTS like '"+cherche+"' or VALIDITE like '"+cherche+"' or OFFRES like '"+cherche+"'or NUMPASSEPORT like '"+cherche+"'   "  );
            return model;
}

