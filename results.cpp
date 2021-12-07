#include "results.h"
#include "ui_results.h"
#include<mainwindow.h>
results::results(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::results)
{
    ui->setupUi(this);
}

results::~results()
{
    delete ui;
}

void results::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery qry ;

    qry.prepare("SELECT * FROM results;");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    conn.connClose();

}


