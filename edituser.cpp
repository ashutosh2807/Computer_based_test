#include "edituser.h"
#include "ui_edituser.h"
#include<mainwindow.h>
#include<QMessageBox>



editUser::editUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editUser)
{
    ui->setupUi(this);
}

editUser::~editUser()
{
    delete ui;
}

void editUser::on_pushButton_3_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery  qry;

    qry.prepare("select * from users;");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    conn.connClose();

}


void editUser::on_pushButton_clicked()
{
    MainWindow conn;
    conn.connOpen();
QString user = ui->lineEdit->text();
QString password = ui->lineEdit_2->text();
  QSqlQuery qry;
  qry.prepare("UPDATE users SET password = '"+password+"' WHERE username = '"+user+"';");
    qry.exec();
    if(qry.exec())
    {
         QMessageBox::information(this,"password change","password changed of '"+user+"' is succeeded");
    }
   else
    {
       QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
conn.connClose();
on_pushButton_3_clicked();
}


void editUser::on_pushButton_2_clicked()
{
    MainWindow conn;
    conn.connOpen();
QString user = ui->lineEdit_3->text();
  QSqlQuery qry,qry1;
  qry.prepare("DELETE FROM users WHERE username = '"+user+"';");
    qry.exec();
    if(qry.exec())
    {
        QMessageBox::information(this,"delete user","'"+user+"' has been deleted.");
    }
    else
     {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
     }

    qry.prepare("DELETE FROM images WHERE username = '"+user+"';");
      qry.exec();
      if(qry.exec())
      {
          QMessageBox::information(this,"delete user","'"+user+"' has been deleted.");
      }
      else
       {
          QMessageBox::critical(this,tr("error::"),qry.lastError().text());
       }


    conn.connClose();
on_pushButton_3_clicked();
}

