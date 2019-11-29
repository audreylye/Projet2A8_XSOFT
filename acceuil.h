#ifndef ACCEUIL_H
#define ACCEUIL_H
#include "agences.h"
#include "compte.h"

#include <QDialog>

namespace Ui {
class acceuil;
}

class acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit acceuil(QWidget *parent = nullptr);
    ~acceuil();

private slots:
    void on_agences_clicked();

    void on_comptes_clicked();

private:
    Ui::acceuil *ui;
    agences *Agences;
    compte *Compte;
};

#endif // ACCEUIL_H
