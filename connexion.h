#ifndef CONNEXION_H
#define CONNEXION_H

//#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
//#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class connexionData;

class connexion
{
public:
    connexion();
    connexion(const connexion &);
    connexion &operator=(const connexion &);
    ~connexion();

private:
    QSharedDataPointer<connexionData> data;
};

#endif // CONNEXION_H
