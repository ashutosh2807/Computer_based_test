#include "passadmin.h"
#include "ui_passadmin.h"
#include<mainwindow.h>
#include<QMessageBox>

passadmin::passadmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::passadmin)
{
    ui->setupUi(this);
}

passadmin::~passadmin()
{
    delete ui;
}

void passadmin::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery  qry;

    qry.prepare("select * from admin;");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    conn.connClose();
}


void passadmin::on_pushButton_2_clicked()
{
      MainWindow conn;
      conn.connOpen();
      QString user = ui->lineEdit->text();
      QString password = ui->lineEdit_2->text();
        QSqlQuery qry;
        qry.prepare("insert into admin values('"+user+"','"+password+"');");
          qry.exec();
          if(qry.exec())
          {
               QMessageBox::information(this,"add a admin"," admin '"+user+"' is added successfully.");
          }
         else
          {
             QMessageBox::critical(this,tr("error::"),qry.lastError().text());
          }
      conn.connClose();
      on_pushButton_clicked();
}


void passadmin::on_pushButton_3_clicked()
{
    MainWindow conn;
    conn.connOpen();
    QString user = ui->lineEdit_3->text();
      QSqlQuery qry;
      qry.prepare("DELETE FROM admin WHERE username = '"+user+"';");
        qry.exec();
        if(qry.exec())
        {
             QMessageBox::information(this,"remove a admin"," admin '"+user+"' is removed successfully.");
        }
       else
        {
           QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    conn.connClose();
    on_pushButton_clicked();
}

