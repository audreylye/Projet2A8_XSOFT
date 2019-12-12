#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "acceuil.h"
#include <QMediaPlayer>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QString controletel(QString p );
private slots:
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    acceuil *Acceuil;
    QMediaPlayer *click;

};
#endif // MAINWINDOW_H
