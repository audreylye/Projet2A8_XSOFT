#ifndef AGENCES_H
#define AGENCES_H
#include "ajouter_ag.h"
#include <QDialog>
#include "arduino.h"

namespace Ui {
class agences;
}

class agences : public QDialog
{
    Q_OBJECT

public:
    explicit agences(QWidget *parent = nullptr);
    ~agences();
    QString controletel(QString p );

private slots:
    void on_ajouter_clicked();

    void on_login_2_clicked();

    void on_login_clicked();

    void on_afficher_clicked();

    void on_login_4_clicked();

    void on_supprimer_clicked();

    void on_supprimer_3_clicked();

    void on_login_8_clicked();

    void on_modifier_clicked();

    void on_login_9_clicked();

    void on_modifier_2_clicked();

    void on_login_10_clicked();

    void on_rechercher_clicked();

    void on_Imprimer_clicked();

    void update_label();
    void notif(QString t,QString m);
    void on_lineEdit_nb_textChanged(const QString &arg1);

private:
    Ui::agences *ui;
    ajouter_ag tmpagence;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // AGENCES_H
