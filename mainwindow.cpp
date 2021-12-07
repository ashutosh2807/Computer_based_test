#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>
#include<QMessageBox>
#include<QPixmap>
#include<QDebug>
#include<QtWidgets>
#include <QDateTime>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix1(":/img/images/download.jpg");
    int w = pix1.width();
    int h = pix1.height();
    ui->label_login->setPixmap(pix1.scaled(w,h,Qt::IgnoreAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this,"help","kindly contact ashurathore2807@gmail.com for support and assistance");

}


void MainWindow::on_pushButton_login_clicked()
{
        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();


        connOpen();
        QSqlQuery qry1;
        QSqlQuery qry;
        QSqlQuery qry2;
        QSqlQuery qry3;

        QSqlQuery  qry4;

        QDateTime dateTime;
        QString date_time = dateTime.currentDateTime().toString();


        qry1.prepare("select * from users where username = '"+username+"' and password='"+password+"';");


        qry.prepare("select * from admin where username = '"+username+"' and password='"+password+"';");
        qry2.prepare("insert into login(username,dateTime) values('"+username+"','"+date_time+"');");
        qry3.prepare("insert into admin_login values('"+date_time+"');");
        qry1.exec();
        qry.exec();
        qDebug()<<(username);

        qry4.prepare("CREATE TABLE '"+username+"' AS SELECT * FROM questions;");

        if(qry1.next())
        {
            if(!qry4.exec())
            {
                QMessageBox::critical(this,"error login","you have already taken the test");
            }
            else
            {
                     qry2.exec();
                     QSqlQuery qry5;
                     qry5.prepare("alter table '"+username+"' add marked_option varchar(20) null;");
                     qry5.exec();

                     QSqlQuery qry6;
                     qry6.prepare("alter table '"+username+"' add review varchar(20) null;");
                     qry6.exec();

                     QSqlQuery qry7;
                     qry7.prepare("alter table '"+username+"' add marks_obtained varchar(20) null;");
                     qry7.exec();



                     hide();
                     cBt = new cbt(this);
                     cBt->showFullScreen();

            }
            connClose();
        }
        else if(qry.next())
        {
            admin = new adminConsole(this);
            admin->showMaximized();
            qry3.exec();
            qry3.next();
            qry3.finish();
            connClose();
        }
        else
        {
           QMessageBox::warning(this,"warning","incorrect username of password;");
                 connClose();
        }

        qry1.finish();
        qry.finish();

       connClose();



}


void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}


