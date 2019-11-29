#include "acceuil.h"
#include "ui_acceuil.h"

acceuil::acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceuil)
{
    ui->setupUi(this);

}

acceuil::~acceuil()
{
    delete ui;
}

void acceuil::on_agences_clicked()
{
    hide();
    Agences = new agences(this);
    Agences->show();
}

void acceuil::on_comptes_clicked()
{
    hide();
    Compte = new compte(this);
    Compte->show();
}
