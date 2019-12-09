#ifndef CLIENT_H
#define CLIENT_H

//#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
//#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQueryModel>
#include <qtableview.h>
class ClientData;

class Client
{
public:
    Client();
    Client(const Client &);
    Client &operator=(const Client &);
    ~Client();

    QString getNOM (){return NOM;}
    QString getPRENOM()  {return PRENOM  ;}
    QString getNUMPASSPORT()  {return NUMPASSPORT  ;}
    QString getDN () {return DN  ;}
    QString getTEL () {return TEL;}
    QString getADDRESSE () {return ADDRESSE ;}

    QString getEMAIL () {return EMAIL ;}
    QString getNBRVOLS () {return NBRVOLS ;}
    QString getSEXE () {return SEXE ;}
    QSqlQuery client2();
    int nbclients();
    void Trieclien(QTableView *tab);

    bool ajouter_client(QString NOM,QString PRENOM,QString NUMPASSPORT,QString DN,QString TEL,QString ADDRESSE,QString EMAIL,QString NBRVOLS,QString SEXE);
QSqlQueryModel * afficherclient();
bool supprimer_client(QString ch);
bool modifier_client(QString NOM,QString PRENOM,QString NUMPASSPORT,QString DN,QString TEL,QString ADDRESSE,QString EMAIL,QString NBRVOLS,QString SEXE);
void  client1(QString txt);
void chercher_client(QString codeabarre,QTableView * tab);
private:
    QSharedDataPointer<ClientData> data;
QString NOM , PRENOM ,NUMPASSPORT,DN,TEL,ADDRESSE ,EMAIL ,NBRVOLS, SEXE ;



};

#endif // CLIENT_H
