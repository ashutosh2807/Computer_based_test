#ifndef TEST_H
#define TEST_H
#include<QTimer>
#include <QMainWindow>
#include<QTime>
#include<finish.h>
namespace Ui {
class test;
}

class test : public QMainWindow
{
    Q_OBJECT

public:
    void remaining();
    void exp();
    void start();
    void check(QString arg1);
    void radio();
    QTime *displayTime = new QTime;

    void showTime();
 QTimer * timer1 = new QTimer;

    explicit test(QWidget *parent = nullptr);

    ~test();

private slots:
   void on_comboBox_currentTextChanged(const QString &arg1);
    void myfunction();
     void updateTime();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_13_clicked();

private:
    Ui::test *ui;
    QTimer * timer;
    finish *fns;
};

#endif // TEST_H
