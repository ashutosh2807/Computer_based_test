#include "adminconsole.h"
#include "ui_adminconsole.h"
#include<mainwindow.h>

adminConsole::adminConsole(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminConsole)
{
    ui->setupUi(this);
    MainWindow conn;

}

adminConsole::~adminConsole()
{
    delete ui;
}

void adminConsole::on_pushButton_Usrmanagement_clicked()
{
    usr = new usermanagement(this);
    usr->showMaximized();
}


void adminConsole::on_pushButton_Qtmanagement_clicked()
{
    qst = new question(this);
    qst->showMaximized();
}


void adminConsole::on_pushButton_Result_management_clicked()
{
    resu = new results(this);
    resu->showMaximized();
}


void adminConsole::on_pushButton_4_clicked()
{
    instr = new instruction(this);
    instr->showNormal();
}


void adminConsole::on_pushButton_3_clicked()
{
    edtusr = new editUser(this);
    edtusr->showMaximized();
}


void adminConsole::on_pushButton_2_clicked()
{
    admin = new passadmin(this);
    admin->showMaximized();
}


void adminConsole::on_pushButton_clicked()
{
    edtqtn = new editQuestion(this);
    edtqtn->showMaximized();
}

