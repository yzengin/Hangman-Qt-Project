#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void iceriyormu(QString data);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQuery *sorgu,*sorgu2;
    QSqlQueryModel *model,*model2;
    QSqlDatabase db;
    QString turkish;
    QLineEdit *karakteral;
    QString english;
    int satirsayisi;
    QStringList ingilizce_kirp;
    QLabel *harf,*ingsonuc,*ingsonuc2,*trsonuc,*trsonuc2;
    QList<QLabel*> array;
    QPushButton *karaktergonder;
    int yanlisSayac=0,dogruSayac=0;
};

#endif // MAINWINDOW_H
