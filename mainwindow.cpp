#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_login_clicked()
{

    QString username=ui->Username->text();
    QString password=ui->Password->text();
    if (username =="selim" && password =="esprit")
    {
        QMessageBox:: information(this,"login","username and password is correct");
        hide();
        Acceuil = new acceuil(this);
        Acceuil->show();

    }
    else
    {
        QMessageBox:: warning(this,"login","username and password is not correct");
    }
}
