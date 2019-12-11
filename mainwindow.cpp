#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QPixmap>
#include "carte.h"
#include <QSqlQuery>
#include <QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include <QSqlQueryModel>

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


void MainWindow::on_pushButton_clicked()
{
    carte *c ;
    c->ajouter_carte(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_9->text());

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    carte *c ;
    c->ajouter_carte(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_9->text());

}



void MainWindow::on_pushButton_5_clicked()
{
    carte *c ;
    c->supprimer_carte(ui->lineEdit_5->text());
}









void MainWindow::on_pushButton_6_clicked()
{
    carte *c ;

    ui->tableView->setModel(c->affichercarte());


}

void MainWindow::on_pushButton_8_clicked()
{
    carte *c ;
    c->modifier_carte(ui->lineEdit_6->text(),ui->lineEdit_10->text(),ui->lineEdit_11->text(),ui->lineEdit_12->text(),ui->lineEdit_13->text());
}

void MainWindow::on_pushButton_12_clicked()
{
    carte *c ;

    ui->tableView->setModel(c->TriecarteC());

}

void MainWindow::on_lineEdit_14_textChanged(const QString &arg1)
{
    carte *c ;
    ui->tableView->setModel(c->cherchercarte(ui->lineEdit_14->text()));
}
