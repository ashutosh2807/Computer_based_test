#include "editquestion.h"
#include "ui_editquestion.h"
#include<mainwindow.h>
#include<QMessageBox>



editQuestion::editQuestion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editQuestion)
{
    ui->setupUi(this);
}

editQuestion::~editQuestion()
{
    delete ui;
}

void editQuestion::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery  qry;

    qry.prepare("select * from questions;");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    conn.connClose();
}


void editQuestion::on_pushButton_2_clicked()
{
    QString q_no = ui->lineEdit->text();
    QString question = ui->plainTextEdit->toPlainText();
    QString answer;
    QString marks = "1";

    if(ui->radioButton->isChecked())
    {
        answer = "A";
     }
    else if(ui->radioButton_1->isChecked())
    {
        answer = "B";
    }
    else if(ui->radioButton_2->isChecked())
    {
        answer = "C";
    }
    else if(ui->radioButton_3->isChecked())
    {
        answer = "D";
    }

    MainWindow conn;
    conn.connOpen();

    QSqlQuery  qry ;

    qry.prepare("update questions set question = '"+question+"' , correct_option = '"+answer+"' where q_no = '"+q_no+"';");

    if(qry.exec())
    {
        QMessageBox::information(this,"data saved!","question: '"+q_no+"' has been changed!");
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    conn.connClose();
    on_pushButton_clicked();
}


void editQuestion::on_pushButton_3_clicked()
{
      QString q_no = ui->lineEdit_2->text();

      MainWindow conn;
      conn.connOpen();

      QSqlQuery  qry ;

      qry.prepare("DELETE FROM questions WHERE q_no = '"+q_no+"';");

      if(qry.exec())
      {
          QMessageBox::information(this,"deleted!","question: '"+q_no+"' has been deleted!");
          conn.connClose();
      }
      else
      {
          QMessageBox::critical(this,tr("error::"),qry.lastError().text());
      }
      conn.connClose();
      on_pushButton_clicked();
}

