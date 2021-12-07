#include "cbt.h"
#include "ui_cbt.h"
#include<QMessageBox>
#include<QPixmap>
#include<mainwindow.h>

cbt::cbt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cbt)
{
    ui->setupUi(this);
     MainWindow conn;
    QPixmap pix1(":/img/images/jiwaji.jpg");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w,h,Qt::IgnoreAspectRatio));

           conn.connOpen();


           QSqlQueryModel model;
              model.setQuery("SELECT * FROM exam_instruction;");


           ui->plainTextEdit->setReadOnly(true);
            ui->plainTextEdit->setPlaceholderText(model.record(0).value("exam").toString());

           conn.connClose();
}

cbt::~cbt()
{
    delete ui;
}

void cbt::on_pushButton_clicked()
{
    hide();
    Test = new test1(this);
    Test->showFullScreen();

}

