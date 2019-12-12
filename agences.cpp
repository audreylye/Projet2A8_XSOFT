#include "agences.h"
#include "ui_agences.h"
#include "ajouter_ag.h"
#include "acceuil.h"
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include <QIntValidator>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QIcon>
agences::agences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agences)
{
    ui->setupUi(this);
    ui->stackedWidget->hide();
    ui->tabagence->setModel(tmpagence.afficher());

}

agences::~agences()
{
    delete ui;
}

void agences::on_ajouter_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(0);
}

void agences::on_login_2_clicked()
{
    ui->stackedWidget->hide();
}

void agences::on_login_clicked()
{
    agences::notif("Agence","Agence ajoutee ");
    int nb_employee = ui->lineEdit_nb->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString lieu= ui->lineEdit_lieu->text();
        ui->lineEdit_nb->setValidator( new QIntValidator(0, 9999, this) );
      ajouter_ag a(nom,lieu,nb_employee);
      bool test=a.ajouter(nom,lieu,nb_employee);
      if(test)
    {ui->tabagence->setModel(tmpagence.afficher());//refresh
    QMessageBox::information(this,"information","Ajouter une agence");

}
}

void agences::on_afficher_clicked()
{
 ui->stackedWidget->show();
 ui->stackedWidget->setCurrentIndex(1);
 ui->tabagence->setModel(tmpagence.afficher());
}

void agences::on_login_4_clicked()
{
    ui->stackedWidget->hide();
}

void agences::on_supprimer_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(2);

}


void agences::on_supprimer_3_clicked()
{    agences::notif("Agence","Agence supprimé ");

    int nb_employee = ui->lineEdit_supprimer->text().toInt();
    bool test=tmpagence.supprimer(nb_employee);
    if(test)
    {ui->tabagence->setModel(tmpagence.afficher());
       QMessageBox::information(this,"information","agence supprimé");

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une agence"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}


}

void agences::on_login_8_clicked()
{
    ui->stackedWidget->hide();
}

void agences::on_modifier_clicked()
{
    ui->stackedWidget->show();
    ui->stackedWidget->setCurrentIndex(3);
}

void agences::on_login_9_clicked()
{
    ui->stackedWidget->hide();
}

void agences::on_modifier_2_clicked()
{
    agences::notif("Agence","Agence modifié ");

    int nb_employee = ui->lineEdit_id_2->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString lieu = ui->lineEdit_lieu_2->text();
   ajouter_ag a(nom,lieu,nb_employee);
  bool test=a.modifier(nom,lieu,nb_employee);
  if(test)
{
      ui->tabagence->setModel(tmpagence.afficher());//refresh
QMessageBox::information(this,"information","agence modifié");

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une agence"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
void agences::on_rechercher_clicked()
{
    int nb_employee = ui->lineEdit_id_2->text().toInt();
    ui->tabagence_2->setModel(tmpagence.recherche(nb_employee));
}
void agences::notif(QString t,QString m)
{

    QPixmap p(32,32);
    p.load("C:/Users/ASUS/Desktop/libertad/colored.png");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}
void agences::on_Imprimer_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabagence->model()->rowCount();
            const int columnCount = ui->tabagence->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES agences ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabagence->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabagence->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabagence->isColumnHidden(column)) {
                        QString data =ui->tabagence->model()->data(ui->tabagence->model()->index(row, column)).toString().simplified();
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
void agences::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
{
          agences::notif("DANGER","Detection de fumée ");
}
        //ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    //else if (data=="0")

        //ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void agences::on_lineEdit_nb_textChanged(const QString &arg1)
{
    ui->lineEdit_nb->setText(controletel(ui->lineEdit_nb->text()));

}
QString agences::controletel(QString p )
{
    QString carac = "azertyuiopmlkjhgfdsqwxcvbn";




    for (int i = 0; i < carac.length(); ++i) {


            p.replace(carac.at(i),"");


}
    return  p ;
}
