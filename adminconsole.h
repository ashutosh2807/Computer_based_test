#ifndef ADMINCONSOLE_H
#define ADMINCONSOLE_H

#include <QMainWindow>
#include<usermanagement.h>
#include<question.h>
#include<results.h>
#include<instruction.h>
#include<edituser.h>
#include<passadmin.h>
#include<editquestion.h>


namespace Ui {
class adminConsole;
}

class adminConsole : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminConsole(QWidget *parent = nullptr);
    ~adminConsole();


private slots:
    void on_pushButton_Usrmanagement_clicked();

    void on_pushButton_Qtmanagement_clicked();

    void on_pushButton_Result_management_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::adminConsole *ui;
    usermanagement * usr;
    question *qst;
    results *resu;
    instruction *instr;
     editUser * edtusr;
       passadmin * admin;
       editQuestion * edtqtn;
};

#endif // ADMINCONSOLE_H
