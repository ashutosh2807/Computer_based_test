#include "question.h"
#include "ui_question.h"
#include<mainwindow.h>
#include<QMessageBox>
question::question(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::question)
{
    ui->setupUi(this);
     MainWindow conn;
}

question::~question()
{
    delete ui;
}

void question::on_pushButton_submit_clicked()
{
    QString q_no = ui->spinBox_qno->text();
    QString question = ui->textEdit_question->toPlainText();
    QString answer;
    QString marks = "1";

    if(ui->radioButton_a->isChecked())
    {
        answer = "A";
     }
    else if(ui->radioButton_b->isChecked())
    {
        answer = "B";
    }
    else if(ui->radioButton_c->isChecked())
    {
        answer = "C";
    }
    else if(ui->radioButton_d->isChecked())
    {
        answer = "D";
    }

    MainWindow conn;
    conn.connOpen();

    QSqlQuery  qry ;

    qry.prepare("insert into questions(q_no,question,correct_option,marks) values('"+q_no+"','"+question+"','"+answer+"','"+marks+"');");

    if(qry.exec())
    {
        QMessageBox::information(this,"data saved!","your data has been saved!");
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    conn.connClose();
    on_pushButton_load_clicked();
}


void question::on_pushButton_load_clicked()
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

