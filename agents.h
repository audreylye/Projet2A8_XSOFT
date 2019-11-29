#ifndef AGENTS_H
#define AGENTS_H

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
#include <QCompleter>
#define q2c(string) string.toStdString()

namespace Ui {
class Agents;
}

class Agents : public QDialog
{
    Q_OBJECT

public:
    int getId(){return id ;}
    void setId (int id){this->id = id ;}

    QString getNom(){return nom;}
    void setNom(QString nom){this->nom = nom;}

    QString getPrenom(){return prenom;}
    void setPrenom(QString prenom){this->prenom = prenom;}

    int getAge(){return age;}
    void setAge(int age){this->age = age;}

    int getSalaire(){return salaire ;}
    void setSalaire(int salaire){this->salaire = salaire ;}

    int getTel_agent(){return tel_agent;}
    void setTel_agent(int tel_agent){this->tel_agent = tel_agent;}

    QString getRole(){return role;}
    void setRole(QString role){this->role = role;}

    int getId_conge(){return id_conge;}
    void setId_conge(int id_conge){this->id_conge = id_conge;}

    QString getType_conge(){return type_conge;}
    void setType_conge(QString type_conge){this->type_conge = type_conge;}

    explicit Agents(QWidget *parent = 0);
    ~Agents();

private slots:

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_14_clicked();

private:
    int id ;
    QString nom;
    QString prenom;
    int age;
    int salaire;
    int tel_agent;
    QString role;
    int id_conge;
    QString type_conge;
    QCompleter *Modelcompleter;
    Ui::Agents *ui;
};

#endif // AGENTS_H
