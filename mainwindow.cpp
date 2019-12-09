#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    Client *c;
    c->ajouter_client(ui->lineEdit->text(),ui->lineEdit_3->text(),ui->lineEdit_6->text(),ui->dateEdit->date().toString("dd/MM/yyyy"),ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_8->text(),ui->lineEdit_2->text(),ui->lineEdit_7->text());

    /*QString nom,prenom,age,num_pass,nbrvol,adresse,tel;
                nom=ui->lineEdit_2->text();
                prenom=ui->lineEdit_3->text();
                age=ui->lineEdit_23->text();
                tel=ui->lineEdit_4->text();
                adresse=ui->lineEdit_5->text();
                num_pass=ui->lineEdit_6->text();
                nbrvol=ui->lineEdit_2->text();

                if( ui->lineEdit->text().isEmpty() ||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()||ui->lineEdit_5->text().isEmpty()||ui->lineEdit_6->text().isEmpty()||ui->lineEdit_23->text().isEmpty()   )
                {
                   // w.show();
                        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                    QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
                }
                else {




                          QSqlQuery qry;
                          qry.prepare("insert into CLIENT (NOM_CLIENT,NUM_PASSPORT,PRÉNOM_CLIENT,AGE_CLIENT,TEL_CLIENT,ADRESSE,NOMBRE_VOLS) values('"+nom+"','"+num_pass+"','"+prenom+"','"+age+"','"+tel+"','"+adresse+"','"+nbrvol+"')");

                             if (qry.exec())
                         {

                               QMessageBox::information(this,tr("AJOUT CLIENT"),tr("Client est Ajouté avec success"));

                               // reinitialiser tt les champs a vide
                               ui->lineEdit->setText("");
                               ui->lineEdit_3->setText("");
                               ui->lineEdit_23->setText("");
                               ui->lineEdit_4->setText("");
                               ui->lineEdit_5->setText("");
                               ui->lineEdit_6->setText("");
                               ui->lineEdit_2->setText("");


                            }
                             else
                         {
                           QMessageBox::critical(this,tr("AJOUT"),qry.lastError().text());
                          }
                 }*/

}

void MainWindow::on_pushButton_3_clicked()
{
    /*QString numpass;
                numpass=ui->lineEdit_14->text();

                if( ui->lineEdit_14->text().isEmpty()   )
                {
                   // w.show();
                        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                    QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
                }
                else {




                          QSqlQuery qry;
                          qry.prepare("DELETE FROM CLIENT WHERE NUM_PASSPORT=('"+numpass+"')");

                             if (qry.exec())
                         {

                               QMessageBox::information(this,tr("SUPPRESSION client"),tr("client est Supprimé avec success"));

                               // reinitialiser tt les champs a vide
                               ui->lineEdit_14->setText("");

                            }
                             else
                         {
                           QMessageBox::critical(this,tr("DELETE"),qry.lastError().text());
                          }
                 }*/
}

void MainWindow::on_pushButton_5_clicked()
{
    Client c;
        ui->tableView->setModel(c.afficherclient());
}

void MainWindow::on_pushButton_6_clicked()
{
    Client *c ;
    c->supprimer_client(ui->lineEdit_12->text());
}

void MainWindow::on_pushButton_clicked()
{
    Client *c;
    c->modifier_client(ui->lineEdit_15->text(),ui->lineEdit_16->text(), ui->lineEdit_12->text(),ui->lineEdit_17->text(),ui->lineEdit_18->text(),  ui->lineEdit_19->text(),  ui->lineEdit_25->text(), ui->lineEdit_21->text(), ui->lineEdit_24->text());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    Client c;
    c.client1(ui->lineEdit_12->text());

    ui->lineEdit_15->setText(c.getNOM());
    ui->lineEdit_16->setText(c.getPRENOM());
    ui->lineEdit_17->setText(c.getDN());
    ui->lineEdit_18->setText(c.getTEL());
    ui->lineEdit_19->setText(c.getADDRESSE());
    ui->lineEdit_21->setText(c.getNBRVOLS());
    ui->lineEdit_24->setText(c.getSEXE());
    ui->lineEdit_25->setText(c.getEMAIL());


}

void MainWindow::on_pushButton_4_clicked()
{
    /*Client *c;
    int sop;
    sop = c->nbclients();
    c->client2();*/
}

void MainWindow::on_pushButton_8_clicked()
{
    Client *c;
    c->Trieclien(ui->tableView);
}

void MainWindow::on_lineEdit_12_textChanged(const QString &arg1)
{
   Client *c ;
   c->chercher_client(ui->lineEdit_12->text(),ui->tableView);
}
