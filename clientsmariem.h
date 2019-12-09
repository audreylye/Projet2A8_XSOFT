#ifndef CLIENTSMARIEM_H
#define CLIENTSMARIEM_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class clientsmariemData;

class clientsmariem
{
public:
    clientsmariem();
    clientsmariem(const clientsmariem &);
    clientsmariem &operator=(const clientsmariem &);
    ~clientsmariem();

private:
    QSharedDataPointer<clientsmariemData> data;
};

#endif // CLIENTSMARIEM_H
