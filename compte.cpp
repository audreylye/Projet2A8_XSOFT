#include "compte.h"
#include "ui_compte.h"
#include "ajouter_compte.h"
#include <QMessageBox>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include <QSystemTrayIcon>
#include <QIcon>

compte::compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compte)
{
    ui->setupUi(this);
    ui->stackedWidget->hide();
    ui->tabcompte->setModel(tmpcompte.afficher());
}

compte::~compte()
{
    delete ui;
}

void compte::on_ajouter_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(0);
}

void compte::on_login_2_clicked()
{
    ui->stackedWidget->hide();

}

void compte::on_login_clicked()
{
    compte::notif("Compte","Compte ajouté");

    int password = ui->lineEdit_password->text().toInt();
        QString username= ui->lineEdit_username->text();
        int id= ui->lineEdit_ID->text().toInt();
      ajouter_compte c(username,password,id);
      bool test=c.ajouter(username,password,id);
      if(test)
    {ui->tabcompte->setModel(tmpcompte.afficher());//refresh
    QMessageBox::information(this,"information","Compte ajouté.");
}
}
void compte::notif(QString t,QString m)
{

    QPixmap p(32,32);
    p.load("C:/Users/ASUS/Desktop/libertad/colored.png");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}
void compte::on_afficher_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(1);
    ui->tabcompte->setModel(tmpcompte.afficher());
}


void compte::on_login_12_clicked()
{
    ui->stackedWidget->hide();
}

void compte::on_login_9_clicked()
{
    ui->stackedWidget->hide();

}

void compte::on_supprimer_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(2);
}

void compte::on_supp_clicked()
{
    compte::notif("Compte","Compte supprimé");

    int id= ui->lineEdit_supp->text().toInt();
    bool test=tmpcompte.supprimer(id);
    if(test)
    {ui->tabcompte->setModel(tmpcompte.afficher());//refresh
        QMessageBox::information(this,"information","compte supprimé");

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une agence"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}

void compte::on_login_13_clicked()
{
    ui->stackedWidget->hide();
}


void compte::on_modifier_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void compte::on_modifier_2_clicked()
{
    compte::notif("Compte","Compte modifié");

    int id = ui->lineEdit_id_2->text().toInt();
    int  password= ui->lineEdit_password_2->text().toInt();
    QString username = ui->lineEdit_username2->text();
    ajouter_compte c(username,password,id);
  bool test=c.modifier(username,password,id);
  if(test)
{
      ui->tabcompte->setModel(tmpcompte.afficher());//refresh
QMessageBox::information(this,"information","Compte modifié");

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une agence"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void compte::on_rechercher_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    ui->tabcompte_2->setModel(tmpcompte.recherche(id));
}

void compte::on_supp_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabcompte->model()->rowCount();
            const int columnCount = ui->tabcompte->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES comptes ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabcompte->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabcompte->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabcompte->isColumnHidden(column)) {
                        QString data =ui->tabcompte->model()->data(ui->tabcompte->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void compte::on_login_10_clicked()
{
    ui->stackedWidget->hide();

}
QString compte::controletel(QString p )
{
    QString carac = "azertyuiopmlkjhgfdsqwxcvbn";




    for (int i = 0; i < carac.length(); ++i) {


            p.replace(carac.at(i),"");


}
    return  p ;
}

void compte::on_lineEdit_ID_textChanged(const QString &arg1)
{
    ui->lineEdit_ID->setText(controletel(ui->lineEdit_ID->text()));

}
