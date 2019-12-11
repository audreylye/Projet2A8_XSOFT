#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "remboursement.h"
#include <QMessageBox>
#include "connexion.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabremboursement->setModel(tmpremboursement.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString cin= ui->lineEdit_cin->text();
    int indice = ui->lineEdit_indice->text().toInt();
  remboursement r(nom,prenom,cin,indice);
  bool test=r.ajouter();
  if(test)
{ui->tabremboursement->setModel(tmpremboursement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un remboursement"),
                  QObject::tr("remboursement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un remboursement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    int indice = ui->lineEdit_indice_2->text().toInt();
    bool test=tmpremboursement.supprimer(indice);
    if(test)
    {ui->tabremboursement->setModel(tmpremboursement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un remboursement"),
                    QObject::tr("remboursement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un remboursement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_2_clicked()
{
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString cin= ui->lineEdit_cin_2->text();
    int indice = ui->lineEdit_indice_3->text().toInt();
  remboursement r(nom,prenom,cin,indice);
  bool test=r.modifier();
  if(test)
{ui->tabremboursement->setModel(tmpremboursement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un remboursement"),
                  QObject::tr("remboursement modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un remboursement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_lineEdit_rech_textChanged(const QString &arg1)
{
    remboursement * r ;
        ui->tableView_rech->setModel(r->chercher_remboursement(ui->lineEdit_rech->text()));
}

void MainWindow::on_pushButton_8_clicked()
{
    remboursement *r ;

        ui->tableView_rech->setModel(r->Trieremboursement());
}
