#include "agents.h"
#include "conge.h"
#include "ui_agents.h"
#include <iostream>
#include <ctime>
#include <QString>
#include "string"// Biblioteck pr les chaines de caracteres
#include "cmath"// Biblioteck pr les instruments mathematiks
#include "vector"// Biblioteck pr les tableaux
#include "fstream"// Biblioteck pr les fichiers
#include <QSqlQuery>
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <string.h>
#include <QCompleter>

Agents::Agents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agents)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/hp/Desktop/login.jpg");
    ui->label->setPixmap(pix);

    QPixmap pix1("C:/Users/hp/Desktop/agent.jpg");
    ui->label->setPixmap(pix1);

    QPixmap pix2("C:/Users/hp/Desktop/conge.jpeg");
    ui->label->setPixmap(pix2);

    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query;
    query.prepare("select * from Agent ")  ;
    query.exec() ;
    model->setQuery(query);
    ui->tableView-> setModel(model);
}

Agents::~Agents()
{
    delete ui;
}


void Agents::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Agents::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Agents::on_pushButton_4_clicked()
{

    //modifier
    Agents a;
    QSqlQuery query;

    a.setId(ui->lineEdit_3->text().toULong());
    a.setNom(ui->lineEdit_4->text());
    a.setPrenom(ui->lineEdit_5->text());
    a.setAge(ui->lineEdit_6->text().toULong());
    a.setSalaire(ui->lineEdit_7->text().toULong());
    a.setTel_agent(ui->lineEdit_8->text().toULong());
    a.setRole(ui->lineEdit_9->text());

    query.prepare("UPDATE AGENT SET NOM=?, PRENOM=?, AGE=?, SALAIRE=?, TEL_AGENT=?, ROLE=?  WHERE ID_AGENT = ? ") ;

    query.addBindValue(a.getNom());
    query.addBindValue(a.getPrenom());
    query.addBindValue(a.getAge());
    query.addBindValue(a.getSalaire());
    query.addBindValue(a.getTel_agent());
    query.addBindValue(a.getRole());
    query.addBindValue(a.getId());

    if(query.exec())
    {
        std::cout << "L'agent a bien été modifier! :)" <<std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query2;
        query2.prepare("SELECT * FROM AGENT ")  ;
        query2.exec() ;
        model->setQuery(query2);
        ui->tableView-> setModel(model);
    }
    else
    {
        std::cout << "Modif:( Desolé une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }

}

void Agents::on_pushButton_3_clicked()
{
    // ajouter
    Agents a;
    qDebug()<<"Le bouton envoyer a ete appuie..."<<endl;

    a.setId(ui->lineEdit_3->text().toULong());
    a.setNom(ui->lineEdit_4->text());
    a.setPrenom(ui->lineEdit_5->text());
    a.setAge(ui->lineEdit_6->text().toULong());
    a.setSalaire(ui->lineEdit_7->text().toULong());
    a.setTel_agent(ui->lineEdit_8->text().toULong());
    a.setRole(ui->lineEdit_9->text());

     QSqlQuery query;

    query.prepare("INSERT INTO AGENT (NOM, PRENOM, AGE, SALAIRE, TEL_AGENT, ROLE, ID_AGENT)"
                  "VALUES(:NOM, :PRENOM, :AGE, :SALAIRE, :TEL_AGENT, :ROLE,:ID_AGENT)");

    query.addBindValue(a.getNom());
    query.addBindValue(a.getPrenom());
    query.addBindValue(a.getAge());
    query.addBindValue(a.getSalaire());
    query.addBindValue(a.getTel_agent());
    query.addBindValue(a.getRole());
    query.addBindValue(a.getId());
    if(query.exec())
    {
        std::cout << "L'agent a bien été modifier! :)" <<std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query2;
        query2.prepare("SELECT * FROM AGENT ")  ;
        query2.exec() ;
        model->setQuery(query2);
        ui->tableView-> setModel(model);
    }
    else
    {
        std::cout << "Modif:( Desolé une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }

}

void Agents::on_pushButton_6_clicked()
{

    //supprimer
    Agents a;
    QSqlQuery query;
    a.setId(ui->lineEdit_10->text().toULong());
    query.prepare("delete from AGENT WHERE ID_AGENT=:ID_AGENT");
    query.addBindValue(a.getId());
    if(query.exec())
        {
            std::cout << "L'agent a bien été supprimer! :)" << std::endl;
            //afficher
            QSqlQueryModel * model=new QSqlQueryModel() ;
            QSqlQuery query2;
            query2.prepare("SELECT * FROM AGENT ")  ;
            query2.exec() ;
            model->setQuery(query2);
            ui->tableView-> setModel(model);
        }
        else
        {
            std::cout << "Suppri:( Une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
        }
    }

void Agents::on_pushButton_5_clicked()
{

    //afficher
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query;
    query.prepare("select * from Agent ")  ;
    query.exec() ;
    model->setQuery(query);
    ui->tableView-> setModel(model);
}



void Agents::on_pushButton_10_clicked()
{

   //afficher
   QSqlQueryModel * model=new QSqlQueryModel() ;
   QSqlQuery query;
   query.prepare("select * from conge ")  ;
   query.exec() ;
   model->setQuery(query);
   ui->tableView_2-> setModel(model);
}

void Agents::on_pushButton_11_clicked()
{
    //supprimer

    conge c;
    QSqlQuery query;
    c.setId(ui->lineEdit_18->text().toULong());
    query.prepare("delete from CONGE WHERE ID_CONGE=:ID_CONGE");
    query.addBindValue(c.getId());
    if(query.exec())
        {
            std::cout << "L'agent a bien été supprimer! :)" << std::endl;
            //afficher
            QSqlQueryModel * model=new QSqlQueryModel() ;
            QSqlQuery query2;
            query2.prepare("SELECT * FROM CONGE ")  ;
            query2.exec() ;
            model->setQuery(query2);
           ui->tableView_2-> setModel(model);
        }
        else
        {
            std::cout << "Suppri:( Une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
        }
}

void Agents::on_pushButton_9_clicked()
{
    //modifier

    conge c;
    QSqlQuery query;

    c.setMotif(ui->lineEdit_15->text());
    c.setId(ui->lineEdit_11->text().toULong());
    c.setDate_debut(ui->dateEdit->text());
    c.setDate_fin(ui->dateEdit_2->text());
    c.setType(ui->lineEdit_16->text());


    query.prepare("UPDATE CONGE SET MOTIF=?, DATE_DEBUT=?, DATE_FIN=?, TYPE=? WHERE ID_CONGE=? ") ;

    query.addBindValue(c.getMotif());
    query.addBindValue(c.getId());
    query.addBindValue(c.getDate_debut());
    query.addBindValue(c.getDate_fin());
    query.addBindValue(c.getType());

    if(query.exec())
    {
        std::cout << "Le conge a bien été modifier! :)" <<std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query2;
        query2.prepare("SELECT * FROM CONGE ")  ;
        query2.exec() ;
        model->setQuery(query2);
        ui->tableView_2-> setModel(model);
    }
    else
    {
        std::cout << "Modif:( Desolé une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }

}

void Agents::on_pushButton_8_clicked()
{
    // ajouter

    conge c;

    qDebug()<<"Le bouton envoyer a ete appuie..."<<endl;

    c.setMotif(ui->lineEdit_15->text());
    c.setId(ui->lineEdit_11->text().toULong());
    c.setDate_debut(ui->dateEdit->text());
    c.setDate_fin(ui->dateEdit_2->text());
    c.setType(ui->lineEdit_16->text());

     QSqlQuery query;

    query.prepare("INSERT INTO CONGE (MOTIF, ID_CONGE, DATE_DEBUT, DATE_FIN, TYPE)"
                  "VALUES(:MOTIF, :ID_CONGE, :DATE_DEBUT, :DATE_FIN, :TYPE)");


    query.addBindValue(c.getMotif());
    query.addBindValue(c.getId());
    query.addBindValue(c.getDate_debut());
    query.addBindValue(c.getDate_fin());
    query.addBindValue(c.getType());
    if(query.exec())
    {
        std::cout << "Le conge a bien été modifier! :)" <<std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query2;
        query2.prepare("SELECT * FROM CONGE ")  ;
        query2.exec() ;
        model->setQuery(query2);
        ui->tableView_2-> setModel(model);
    }
    else
    {
        std::cout << "Modif:( Desolé une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }

}

void Agents::on_pushButton_13_clicked()
{
    //trier
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query;
    query.prepare("select * from Agent order by nom ")  ;
    query.exec() ;
    model->setQuery(query);
    ui->tableView-> setModel(model);
}

void Agents::on_pushButton_20_clicked()
{
    //trier
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM CONGE order by type ")  ;
    query2.exec();
    model->setQuery(query2);
    ui->tableView_2-> setModel(model);
}

void Agents::on_pushButton_21_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT role, COUNT(*) FROM AGENT GROUP BY role")  ;
    query2.exec();
    query2.exec();
    model->setQuery(query2);
    ui->tableView-> setModel(model);
}

void Agents::on_recherche_textChanged(const QString &arg1)
{

    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM agent where nom like :test")  ;
    query2.bindValue(":test",arg1+"%");
    query2.exec();
    model->setQuery(query2);
    ui->tableView-> setModel(model);
}

void Agents::on_pushButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void Agents::on_pushButton_14_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}
