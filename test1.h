#ifndef TEST1_H
#define TEST1_H
#include<QTimer>
#include <QMainWindow>
#include<QTime>
#include<finish.h>
namespace Ui {
class test1;
}

class test1 : public QMainWindow
{
    Q_OBJECT

public:
    void radio1();
    void remaining();
    void exp();
    void start();
    void check(QString arg1);
    void radio();
    QTime *displayTime = new QTime;

    void showTime();
 QTimer * timer1 = new QTimer;

    explicit test1(QWidget *parent = nullptr);

    ~test1();

private slots:
   void on_comboBox_currentTextChanged(const QString &arg1);
    void myfunction();
     void updateTime();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_13_clicked();

private:
    Ui::test1 *ui;
    QTimer * timer;
    finish *fns;
};

#endif // TEST1_H
