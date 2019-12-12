#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/new/prefix1/click.mp3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    click->play();
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
QString MainWindow::controletel(QString p )
{
    QString carac = "azertyuiopmlkjhgfdsqwxcvbn";




    for (int i = 0; i < carac.length(); ++i) {


            p.replace(carac.at(i),"");


}
    return  p ;
}
