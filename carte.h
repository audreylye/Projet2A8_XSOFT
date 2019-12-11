#ifndef CARTE_H
#define CARTE_H
//#include "C:/Users/Salwa.Abbes/Avg/Desktop/clients/client.h"

//#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
//#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
//#include <QTabWidget>
#include <QTableView>
#include <QSqlQueryModel>
class carteData;

class carte
{
public:
    carte();
    carte(const carte &);
    carte &operator=(const carte &);
    ~carte();


    QString getID_FID (){return ID_FID;}
        QString getPOINTS()  {return POINTS  ;}
        QString getVALIDITE()  {return VALIDITE  ;}
        QString getOFFRES () {return OFFRES  ;}
         QString getNUMPASSEPORT () {return NUMPASSEPORT  ;}
        QSqlQueryModel * cherchercarte (QString);
QSqlQueryModel * affichercarte();
        bool ajouter_carte(QString ID_FID ,QString POINTS,QString VALIDITE,QString OFFRES,QString NUMPASSEPORT);
        bool supprimer_carte(QString ch);
        bool modifier_carte(QString ID_FID,QString POINTS,QString VALIDITE,QString OFFRES,QString NUMPASSEPORT);
      QSqlQueryModel *  TriecarteC();

private:
    QSharedDataPointer<carteData> data;
    QString ID_FID , POINTS ,VALIDITE,OFFRES,NUMPASSEPORT;

};

#endif // CARTE_H
