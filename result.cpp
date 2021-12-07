#include "result.h"
#include "ui_result.h"
#include<mainwindow.h>
#include<QSqlDatabase>
#include<QDate>
#include<QDebug>
#include<QMessageBox>

result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);

}

result::~result()
{
    delete ui;
}



void result::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery qry ;

    qry.prepare("select username from users;");
    qry.exec();
    modal->setQuery(qry);
    ui->listView->setModel(modal);

    conn.connClose();
    qDebug()<<("connection closed!");
    qDebug()<<(modal->rowCount());
}

