#include "instruction.h"
#include "ui_instruction.h"
#include<mainwindow.h>
#include<QMessageBox>

instruction::instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instruction)
{
    ui->setupUi(this);

MainWindow conn;
conn.connOpen();
    QSqlQuery qry1;
    qry1.prepare("select exam from exam_instruction;");
      qry1.exec();
    ui->plainTextEdit->setPlaceholderText(qry1.value(0).toString());
conn.connClose();
}

instruction::~instruction()
{
    delete ui;
}

void instruction::on_pushButton_clicked()
{

    MainWindow conn;
    conn.connOpen();


    QSqlQuery qry ;
   QString data;
   data = ui->plainTextEdit->toPlainText();
    qry.prepare("UPDATE exam_instruction SET exam = '"+data+"';");
    qry.exec();
    QMessageBox::information(this,"exam_instruction","instruction has been saved!!");
    conn.connClose();
}

