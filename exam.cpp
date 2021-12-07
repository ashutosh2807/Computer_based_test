#include "exam.h"
#include "ui_exam.h"
#include<QMessageBox>
#include<QPixmap>
#include<mainwindow.h>
#include<QTimer>
#include<QDateTime>
#include<QDebug>
#include<QSqlDatabase>
#include<QMessageBox>

exam::exam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::exam)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();


    QPixmap pix(":/img/images/pic.jpg");
    int w = pix.width();
    int h = pix.height();
    ui->label_image->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));


    QPixmap pix1(":/img/images/sign.png");
    int w1 = pix.width();
    int h1 = pix.height();
    ui->label_sign->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

         MainWindow conn;
    conn.connOpen();

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from questions;");
        qry.exec();

         modal->setQuery(qry);
         ui->comboBox->setModel(modal);

    conn.close();

}

void exam::showTime()
{
        QTime time = QTime::currentTime();
        QString time_text =  time.toString("hh : mm : ss");
        ui->label_time->setText(time_text);

}

exam::~exam()
{
    delete ui;
}

void exam::on_pushButton_5_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery qry ;

    qry.prepare("select * from users;");
    qry.exec();
    modal->setQuery(qry);
     ui->comboBox->setModel(modal);
    conn.connClose();
    qDebug()<<("connection closed!");
    qDebug()<<(modal->rowCount());

     int row = modal->rowCount();
    ui->label_16->setText(QString::number(row));
    QString name = ui->comboBox->currentText();
    ui->label_11->setText(name);
}




void exam::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->label_14->setText(arg1);
   QString name = ui->comboBox->currentText();
   MainWindow conn;
   conn.connOpen();
   QSqlQuery qry;
   qry.prepare("select * from users where username='"+name+"';");

   if(qry.exec())
   {
       while(qry.next())
       {
          ui->label_2->setText(qry.value(0).toString());
          ui->label_time_4->setText(qry.value(1).toString());
          ui->label_16->setText(qry.value(2).toString());
                  qDebug()<<("database connected");
       }
   }
           conn.connClose();

}

