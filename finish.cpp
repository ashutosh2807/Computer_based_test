#include "finish.h"
#include "ui_finish.h"
#include<mainwindow.h>
finish::finish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
}

finish::~finish()
{
    delete ui;
}


void finish::on_pushButton_2_clicked()
{
    hide();
    MainWindow *mn = new MainWindow(this);
    mn->showFullScreen();
}

