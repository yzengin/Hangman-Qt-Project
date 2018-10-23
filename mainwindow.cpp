#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/yakup/AdamAsmacaProjects/adamasmaca");
    if (!db.open()) {
        QMessageBox::critical(this,"Veritabanı Bağlantı Hatası",db.lastError().text());
    } else {
        sorgu = new QSqlQuery(db);
        model = new QSqlQueryModel();
        sorgu2 = new QSqlQuery(db);
        model2 = new QSqlQueryModel();
    }
    sorgu->exec("select * from words");
    model->setQuery(*sorgu);
    satirsayisi = model->rowCount();

    QImage arkaplan(":/resim/arkaplan.png");
    QImage resim0(":/resim/0.png");
    QImage resim1(":/resim/1.png");
    QImage resim2(":/resim/2.png");
    QImage resim3(":/resim/3.png");
    QImage resim4(":/resim/4.png");
    QImage resim5(":/resim/5.png");
    QImage resim6(":/resim/yatayCizgi.png");

    ui->label->setPixmap(QPixmap::fromImage(arkaplan));
    ui->label->setScaledContents(true);
    ui->label->show();

    ui->label_2->setPixmap(QPixmap::fromImage(resim0));
    ui->label_2->setScaledContents(true);
    ui->label_2->hide();

    ui->label_3->setPixmap(QPixmap::fromImage(resim1));
    ui->label_3->setScaledContents(false);
    ui->label_3->hide();

    ui->label_4->setPixmap(QPixmap::fromImage(resim2));
    ui->label_4->setScaledContents(true);
    ui->label_4->hide();

    ui->label_5->setPixmap(QPixmap::fromImage(resim3));
    ui->label_5->setScaledContents(true);
    ui->label_5->hide();

    ui->label_6->setPixmap(QPixmap::fromImage(resim4));
    ui->label_6->setScaledContents(true);
    ui->label_6->hide();

    ui->label_7->setPixmap(QPixmap::fromImage(resim5));
    ui->label_7->setScaledContents(true);
    ui->label_7->hide();

    ui->label_8->setPixmap(QPixmap::fromImage(resim6));
    ui->label_8->setScaledContents(false);
    ui->label_8->hide();

    ui->label_9->setPixmap(QPixmap::fromImage(resim1));
    ui->label_9->setScaledContents(false);
    ui->label_9->hide();

    ui->label_10->setPixmap(QPixmap::fromImage(resim1));
    ui->label_10->setScaledContents(false);
    ui->label_10->hide();

    ui->label_11->setPixmap(QPixmap::fromImage(resim1));
    ui->label_11->setScaledContents(false);
    ui->label_11->hide();

    ui->label_12->setPixmap(QPixmap::fromImage(resim1));
    ui->label_12->setScaledContents(false);
    ui->label_12->hide();

    ui->label_13->setPixmap(QPixmap::fromImage(resim6));
    ui->label_13->setScaledContents(false);
    ui->label_13->hide();

    ui->label_14->setPixmap(QPixmap::fromImage(resim6));
    ui->label_14->setScaledContents(false);
    ui->label_14->hide();

    ui->label_15->setPixmap(QPixmap::fromImage(resim6));
    ui->label_15->setScaledContents(false);
    ui->label_15->hide();

    ui->label_16->setPixmap(QPixmap::fromImage(resim1));
    ui->label_16->setScaledContents(false);
    ui->label_16->hide();

    ui->label_17->setText("HAKKINIZI HELAL EDİN.");
    ui->label_17->hide();

    ui->label_18->setText("ABİ BİR DAKİKA");
    ui->label_18->hide();

    ui->label_19->setText("BUTONA BASMADAN ÖNCE");
    ui->label_19->hide();

    ui->label_20->setText("SON SOZUMU SOYLEYEYİM");
    ui->label_20->hide();

    ui->label_21->setText("HAYATIMI KURTARDIĞIN İÇİN TEŞEKKÜR EDERİM DOSTUM");
    ui->label_21->hide();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int X = 65;
    int Y = 120;
    int W = 40;
    int H = 40;

    karakteral = new QLineEdit(this);
    karakteral->setGeometry(50,220,60,30);
    karakteral->show();

    int randyeni = (rand()%satirsayisi)+2;
    sorgu2->prepare("select * from words where no = ?");
    sorgu2->addBindValue(randyeni);
    sorgu2->exec();
    model2->setQuery(*sorgu2);
    english = model2->index(0,2).data().toString();
    ingilizce_kirp = english.split("");

    qDebug()<<ingilizce_kirp.value(2);

    for(int i=0; i<= ingilizce_kirp.count()-3; i++){
        harf = new QLabel(this);
        harf->setGeometry(X,Y,W,H);
        harf->setText("___");
        harf->show();
        array.append(harf);
        X=X+60;
    }

    turkish = model2->index(0,1).data().toString();

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_16->hide();
    ui->label_17->hide();
    ui->label_18->hide();
    ui->label_19->hide();
    ui->label_20->hide();
    ui->label_21->hide();
}

void MainWindow::iceriyormu(QString data)
{
  if(!ingilizce_kirp.contains(data))
  {
    yanlisSayac++;
    ui->listWidget->addItem(data);

    if(yanlisSayac==1)
        ui->label_8->show();
    else if(yanlisSayac==2){
        ui->label_9->show();
        ui->label_10->show();
        ui->label_11->show();
        ui->label_12->show();
    }
    else if(yanlisSayac==3){
        ui->label_13->show();
        ui->label_14->show();
        ui->label_15->show();
    }

    else if(yanlisSayac==4)
        ui->label_16->show();
    else if(yanlisSayac==5)
        ui->label_2->show();
    else if(yanlisSayac==6)
        ui->label_3->show();
    else if(yanlisSayac==7)
        ui->label_4->show();
    else if(yanlisSayac==8)
        ui->label_5->show();
    else if(yanlisSayac==9){
        ui->label_6->show();
        ui->label_18->show();
        ui->label_19->show();
        ui->label_20->show();
    }
    else if(yanlisSayac>=10){
        ui->label_7->show();
        ui->label_17->show();
        ui->label_18->hide();
        ui->label_19->hide();
        ui->label_20->hide();

        ingsonuc2 = new QLabel(this);
        ingsonuc2->setGeometry(170,210,80,20);
        ingsonuc2->setText("İngilizce");
        ingsonuc2->show();

        ingsonuc = new QLabel(this);
        ingsonuc->setGeometry(170,235,80,20);
        ingsonuc->show();

        trsonuc2 = new QLabel(this);
        trsonuc2->setGeometry(270,210,80,20);
        trsonuc2->setText("Türkçe");
        trsonuc2->show();

        trsonuc = new QLabel(this);
        trsonuc->setGeometry(270,235,80,20);
        trsonuc->show();

        ingsonuc->setText(english);
        trsonuc->setText(turkish);
        QMessageBox::critical(this,"Oyun Bitti!","Kaybettin. Yeniden Oynamak için Başla butonuna tıklayın.");

    }
   }

  else{
      dogruSayac++;
      qDebug()<<ingilizce_kirp.indexOf(data);
      QLabel *harfset = array.value(ingilizce_kirp.indexOf(data)-1);
      harfset->setText(data);
      if(dogruSayac==ingilizce_kirp.length()-2)
      {
          ui->label_2->show();
          ui->label_3->show();
          ui->label_4->show();
          ui->label_5->show();
          ui->label_6->show();
          ui->label_7->show();
          ui->label_21->show();

          ingsonuc2 = new QLabel(this);
          ingsonuc2->setGeometry(170,210,80,20);
          ingsonuc2->setText("İngilizce");
          ingsonuc2->show();

          ingsonuc = new QLabel(this);
          ingsonuc->setGeometry(170,235,80,20);
          ingsonuc->show();

          trsonuc2 = new QLabel(this);
          trsonuc2->setGeometry(270,210,80,20);
          trsonuc2->setText("Türkçe");
          trsonuc2->show();

          trsonuc = new QLabel(this);
          trsonuc->setGeometry(270,235,80,20);
          trsonuc->show();

          ingsonuc->setText(english);
          trsonuc->setText(turkish);
          QMessageBox::information(this,"Kazandınız!","Tebrikler!!!!");
      }
  }
}

void MainWindow::on_pushButton_clicked()
{
    iceriyormu(karakteral->text());
}

