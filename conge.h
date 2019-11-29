#ifndef CONGE_H
#define CONGE_H

#include <QDialog>
#include <iostream>
#include <ostream>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <ostream>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <string.h>
#include <QCoreApplication>
#include <QtSql>
#include <QString>
#include <ctime>
#define q2c(string) string.toStdString()

class conge
{
public:
    int getId(){return id ;}
    void setId (int id){this->id = id ;}

    QString getMotif(){return motif;}
    void setMotif(QString motif){this->motif = motif;}

    QString getDate_debut(){return date_debut;}
   void setDate_debut( QString date_debut){this->date_debut = date_debut;}

   QString getType(){return type;}
  void setType( QString type){this->type = type;}

    QString getDate_fin(){return date_fin;}
    void setDate_fin(QString date_fin){this->date_fin = date_fin;}

    //conge();

private:
    int id;
    QString motif;
    QString date_debut;
    QString date_fin;
    QString type;

};

#endif // CONGE_H
