#include "usermanagement.h"
#include "ui_usermanagement.h"
#include<mainwindow.h>
#include<QDate>
#include<QDebug>
#include<QMessageBox>
#include <QtWidgets>
#include<QSqlDatabase>
#include <QtSql>

usermanagement::usermanagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::usermanagement)
{
    ui->setupUi(this);

}

usermanagement::~usermanagement()
{
    delete ui;
}

void usermanagement::on_pushButton_submit_clicked()
{
    QString centre = ui->lineEdit->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString phone = ui->lineEdit_phone->text();
    QString address = ui->textEdit_address->toPlainText();
    QString dob = ui->lineEdit_dob->text();
    QString sex;
    if(ui->radioButton_m->isChecked())
    {
        sex = "m";
    }
    else
    {
        sex = "f";
    }
    MainWindow conn;
    conn.connOpen();

    QSqlQuery  qry ;

    qry.prepare("insert into users values('"+username+"','"+password+"','"+dob+"','"+phone+"','"+address+"','"+sex+"','"+centre+"');");

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
    on_pushButton_clicked();

}


void usermanagement::on_pushButton_reset_clicked()
{
   ui->lineEdit_username->clear();
   ui->lineEdit_password->clear();
   ui->lineEdit_phone->clear();
   ui->textEdit_address->clear();
   ui->lineEdit_dob->clear();
   ui->radioButton_m->clearFocus();
   ui->radioButton_f->clearMask();
   ui->pushButton_2->setText("Select Photo");
   ui->pushButton_3->setText("Select Signature");
}


void usermanagement::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery qry ;

    qry.prepare("select * from users;");
    qry.exec();
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

    conn.connClose();

}


void usermanagement::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("open file"),
                "C://",
                "All Files(*.*);; img (*.jpg);; jpeg (*.jpeg)");

     MainWindow conn;
    conn.connOpen();
    QPixmap inPixmap(filename) ; //we will use here QFileDialog , path to the file.
    QByteArray inByteArray;
    QBuffer inBuffer( &inByteArray );
    inBuffer.open( QIODevice::WriteOnly );
    inPixmap.save( &inBuffer, "JPG" ); // write inPixmap into inByteArray in PNG format
    QSqlQuery  query,query1 ;
    QString username = ui->lineEdit_username->text();

    query.prepare( "INSERT INTO images (username,photo) VALUES ('"+username+"',:imageData);" );
    query.bindValue( ":imageData", inByteArray );

    query1.prepare( "UPDATE images SET photo = :imageData WHERE username = '"+username+"';" );
    query1.bindValue( ":imageData", inByteArray );


    if( !query.exec() )
    {
        if( !query1.exec() )
             QMessageBox::critical(this,"error",query.lastError().text());
    }

    ui->pushButton_2->setText(filename);
    conn.connClose();
}


void usermanagement::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("open file"),
                "C://",
                "All Files(*.*);; img (*.jpg);; jpeg (*.jpeg)");

     MainWindow conn;
    conn.connOpen();
    QPixmap inPixmap(filename) ; //we will use here QFileDialog , path to the file.
    QByteArray inByteArray;
    QBuffer inBuffer( &inByteArray );
    inBuffer.open( QIODevice::WriteOnly );
    inPixmap.save( &inBuffer, "JPG" ); // write inPixmap into inByteArray in PNG format
    QSqlQuery  query ;
    QString username = ui->lineEdit_username->text();

    if(username == "")
    {
        QMessageBox::critical(this,"invalid user","please enter a valid username");
    }
    else
    {

        query.prepare( "UPDATE images SET sign = :imageData WHERE username = '"+username+"';" );
        query.bindValue( ":imageData", inByteArray );
    }

    if( !query.exec() )
        QMessageBox::critical(this,"error",query.lastError().text());

    ui->pushButton_3->setText(filename);
    conn.connClose();
}

