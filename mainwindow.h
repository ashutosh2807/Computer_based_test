#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<cbt.h>
#include<QDebug>
#include<QtSql>
#include<QFileInfo>
#include<adminconsole.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

      QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {

        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/sqlite3/database.db");

       if( mydb.open())
       {
            qDebug()<<("database opened");
               return true;
       }
       else
       {
            qDebug()<<("database is not connected");
        return false;
       }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionHelp_triggered();

    void on_pushButton_login_clicked();

    void on_pushButton_reset_clicked();


private:
    Ui::MainWindow *ui;
    cbt *cBt;
    adminConsole *admin;
};
#endif // MAINWINDOW_H
