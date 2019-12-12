#ifndef COMPTE_H
#define COMPTE_H
#include <QDialog>
#include "ajouter_compte.h"
#include "arduino.h"
#include <QDialog>

namespace Ui {
class compte;
}

class compte : public QDialog
{
    Q_OBJECT

public:
    explicit compte(QWidget *parent = nullptr);
    ~compte();

private slots:
    void on_ajouter_clicked();

    void on_login_2_clicked();

    void on_login_clicked();

    void on_afficher_clicked();

    void on_login_12_clicked();

    void on_login_9_clicked();

    void on_supprimer_clicked();

    void on_supp_clicked();

    void on_login_13_clicked();

    void on_modifier_clicked();

    void on_modifier_2_clicked();

    void on_rechercher_clicked();

    void on_supp_2_clicked();

    void on_login_10_clicked();
     void notif(QString t,QString m);
     QString controletel(QString p );
     void on_lineEdit_ID_textChanged(const QString &arg1);

private:
    Ui::compte *ui;
    ajouter_compte tmpcompte;
};

#endif // COMPTE_H
