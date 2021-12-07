#include "test1.h"
#include "ui_test1.h"
#include<QMessageBox>
#include<QPixmap>
#include<mainwindow.h>
#include<QTimer>
#include<QDateTime>
#include<QDebug>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QString>
#include<finish.h>

QString argument;

void test1::radio1()
{
    MainWindow conn;
    conn.connOpen();
     QString user = ui->label_9->text();
        QSqlQueryModel model;
           model.setQuery("SELECT count(q_no) from '"+user+"' WHERE marked_option ='' ;");
               QString number = model.record(0).value("count(q_no)").toString();
            ui->label_14->setText(number);

            QSqlQueryModel model1;
               model1.setQuery("SELECT * from '"+user+"';");
                   int number1 = model1.rowCount();
                ui->label_16->setText(QString::number(number1));

                QSqlQuery qry;
                qry.prepare("update '"+user+"' set marked_option = 'null' ;");
                qry.exec();

        conn.connClose();

}

void test1::remaining()
{
MainWindow conn;
conn.connOpen();
 QString user = ui->label_9->text();
    QSqlQueryModel model;
       model.setQuery("SELECT count(q_no) from '"+user+"' WHERE marked_option ='null';");
           QString number = model.record(0).value("count(q_no)").toString();
        ui->label_16->setText(number);



        QSqlQueryModel model1;
           model1.setQuery("SELECT count(q_no) from '"+user+"' WHERE marked_option !='null';");
               QString number1 = model1.record(0).value("count(q_no)").toString();
            ui->label_14->setText(number1);
    conn.connClose();


}

void test1::exp()
{
    MainWindow conn;
    conn.connOpen();
    QString user = ui->label_9->text();

    QSqlQueryModel model2;
       model2.setQuery("SELECT * FROM users WHERE username is '"+user+"';");

      QString centre = model2.record(0).value("centre").toString();

      ui->label_10->setText(centre);

       conn.connClose();

}

void test1::start()
{
    QString a ="1";
  on_comboBox_currentTextChanged(a);
  radio1();
}

void test1::check(QString arg1)
{
    MainWindow conn;
    conn.connOpen();
     QString user = ui->label_9->text();
    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM '"+user+"' WHERE q_no = '"+arg1+"';");
    qry1.exec();
    qry1.next();
    if(qry1.value(5).toString()== "A")
   {
       ui->radioButton->setChecked(true);
   }
   else if(qry1.value(5).toString() == "B")
   {
       ui->radioButton_2->setChecked(true);
   }
   else if (qry1.value(5).toString()== "C")
   {
       ui->radioButton_3->setChecked(true);
   }
   else if(qry1.value(5).toString() == "D")
   {
       ui->radioButton_4->setChecked(true);
   }
    conn.connClose();

}

void test1::radio()
{
    QString user = ui->label_9->text();
    MainWindow conn;
    conn.connOpen();

     int i= ui->comboBox->currentIndex();
    int j = i+1;
     QString str = QString("update '"+user+"' set marked_option = 'null' where s_no is %1;").arg(j);
     QSqlQuery qry;
     qry.prepare(str);
     qry.exec();
    conn.connClose();
          remaining();
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);

    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);

    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_3->setAutoExclusive(true);

    ui->radioButton_4->setAutoExclusive(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_4->setAutoExclusive(true);

}

test1::test1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test1)
{
    ui->setupUi(this);



    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
     timer->start(1000);

     connect(timer1,SIGNAL(timeout()), this, SLOT(updateTime()));
      timer1->start(1000);





    QPixmap pix(":/img/images/pic.jpg");
    int w = pix.width();
    int h = pix.height();
    ui->label_image->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));


    QPixmap pix1(":/img/images/sign.png");
    int w1 = pix.width();
    int h1 = pix.height();
    ui->label_sign->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));


      MainWindow conn;
    conn.connOpen();

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from questions;");
        qry.exec();
         modal->setQuery(qry);
         ui->comboBox->setModel(modal);
            conn.close();

          conn.connOpen();


               QSqlQueryModel model2;
                  model2.setQuery("SELECT * FROM login;");

                  for (int i = 0; i < model2.rowCount(); ++i) {
                   QString name = model2.record(i).value("username").toString();
                      ui->label_9->setText(name);
                  }

                  QDateTime date;

                  std::string val_string = "2021:09:27 03:00:00";
                  QString d = QString::fromStdString(val_string.substr(0, 19));
                  date = QDateTime::fromString(d,"yyyy:MM:dd HH:mm:ss");
                      *displayTime = date.time();

                  QString username =  ui->label_9->text();
                  QSqlQuery qry123,qry456 ;
                 qry123.exec("SELECT photo FROM images WHERE username = '"+username+"';" );
                 qry123.first();
                   QByteArray outByteArray = qry123.value( 0 ).toByteArray();
                   QPixmap outPixmap;
                   outPixmap.loadFromData( outByteArray );
                   int we = outPixmap.width();
                   int hi = outPixmap.height();
                   ui->label_image->setPixmap(outPixmap.scaled(we,hi,Qt::IgnoreAspectRatio));


                   qry456.exec("SELECT sign FROM images WHERE username = '"+username+"';" );
                  qry456.first();
                   QByteArray outByteArray1 = qry456.value( 0 ).toByteArray();
                   QPixmap outPixmap1;
                   outPixmap1.loadFromData( outByteArray1 );
                    int we1 = outPixmap1.width();
                    int hi1 = outPixmap1.height();
                   ui->label_sign->setPixmap(outPixmap1.scaled(we1,hi1,Qt::IgnoreAspectRatio));



                  conn.close();
    exp();


  start();

}


test1::~test1()
{
    delete ui;
}

void test1::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);

    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);

    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_3->setAutoExclusive(true);

    ui->radioButton_4->setAutoExclusive(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_4->setAutoExclusive(true);

    ui->label_11->setText(arg1);
    MainWindow conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from questions where q_no='"+arg1+"';");
    qry.exec();
    qry.next();
               ui->plainTextEdit->setReadOnly(true);
               ui->plainTextEdit->setPlaceholderText(qry.value(2).toString());

    argument = arg1;
conn.connClose();
  check(arg1);

}

void test1::myfunction()
{

      QTime time = QTime::currentTime();
      QString time_text = time.toString("hh : mm : ss");
      ui->label_3->setText(time_text);
}

void test1::updateTime()
{

    QTime newTime = displayTime->addSecs(-1);
    displayTime->setHMS(newTime.hour(),newTime.minute(),newTime.second());
    ui->label_time->setText(displayTime->toString("hh:mm:ss"));
    if(displayTime->hour() != 0 ||
            displayTime->minute() != 0 ||
            displayTime->second() != 0)
    {
        timer->start(1000);
    }
    else
    {
        QMessageBox::critical(this,"timeover","exam time is over");
        on_pushButton_13_clicked();
    }

}


void test1::on_pushButton_5_clicked()
{
    MainWindow conn;
    conn.connOpen();
        QString question_no = ui->label_11->text();
        QString user = ui->label_9->text();

        if(ui->radioButton->isChecked())
        {

            QSqlQueryModel model;
               model.setQuery("select * from '"+user+"';");

               for (int i = 0; i < model.rowCount(); ++i) {
                   QString number = model.record(i).value("q_no").toString();

                if(question_no == number)
                {
                    QSqlQuery qry;
                    qry.prepare("UPDATE '"+user+"' SET marked_option='A' WHERE q_no = '"+question_no+"';");
                    qry.exec();
                }
               }
        }
        else if(ui->radioButton_2->isChecked())
        {

            QSqlQueryModel model;
               model.setQuery("select * from '"+user+"';");

               for (int i = 0; i < model.rowCount(); ++i) {
                   QString number = model.record(i).value("q_no").toString();

                if(question_no == number)
                {
                    QSqlQuery qry;
                    qry.prepare("UPDATE '"+user+"' SET marked_option='B' WHERE q_no = '"+question_no+"';");
                    qry.exec();
                }
               }
        }
        else if(ui->radioButton_3->isChecked())
        {

            QSqlQueryModel model;
               model.setQuery("select * from '"+user+"';");

               for (int i = 0; i < model.rowCount(); ++i) {
                   QString number = model.record(i).value("q_no").toString();

                if(question_no == number)
                {
                    QSqlQuery qry;
                    qry.prepare("UPDATE '"+user+"' SET marked_option='C' WHERE q_no = '"+question_no+"';");
                    qry.exec();
                }
               }
        }
        else if(ui->radioButton_4->isChecked())
        {

            QSqlQueryModel model;
               model.setQuery("select * from '"+user+"';");

               for (int i = 0; i < model.rowCount(); ++i) {
                   QString number = model.record(i).value("q_no").toString();
                if(question_no == number)
                {
                    QSqlQuery qry;
                    qry.prepare("UPDATE '"+user+"' SET marked_option='D' WHERE q_no = '"+question_no+"';");
                    qry.exec();
                }
               }
        }
          conn.connClose();
     remaining();

            on_pushButton_2_clicked();

            ui->radioButton->setAutoExclusive(false);
            ui->radioButton->setChecked(false);
            ui->radioButton->setAutoExclusive(true);

            ui->radioButton_2->setAutoExclusive(false);
            ui->radioButton_2->setChecked(false);
            ui->radioButton_2->setAutoExclusive(true);


            ui->radioButton_3->setAutoExclusive(false);
            ui->radioButton_3->setChecked(false);
            ui->radioButton_3->setAutoExclusive(true);

            ui->radioButton_4->setAutoExclusive(false);
            ui->radioButton_4->setChecked(false);
            ui->radioButton_4->setAutoExclusive(true);

            check(argument);

}


void test1::on_pushButton_6_clicked()
{
radio();
  remaining();
}



void test1::on_pushButton_2_clicked()
{

    QString user = ui->label_9->text();
        MainWindow conn;
        conn.connOpen();

        QSqlQueryModel model;
           model.setQuery("select * from '"+user+"';");

    if(  ui->comboBox->currentIndex() < model.rowCount())
    {
        int i= ui->comboBox->currentIndex();
        i++;
        ui->comboBox->setCurrentIndex(i);

    }
    if( ui->comboBox->currentIndex() == -1)
    {
        int i= ui->comboBox->currentIndex();
        i++;
        ui->comboBox->setCurrentIndex(i);
    }
    conn.connClose();
}


void test1::on_pushButton_3_clicked()
{
    QString user = ui->label_9->text();
        MainWindow conn;
        conn.connOpen();

        QSqlQueryModel model;
           model.setQuery("select * from '"+user+"';");

    if(  ui->comboBox->currentIndex() > 0)
    {   int i= ui->comboBox->currentIndex();
        i--;
        ui->comboBox->setCurrentIndex(i);
    }
    else
    {

    }
    conn.connClose();
}


void test1::on_pushButton_13_clicked()
{
     QString user = ui->label_9->text();

    MainWindow conn;
    conn.connOpen();


    QSqlQueryModel model;
       model.setQuery("select * from '"+user+"';");
       int number = 0;

       for (int i = 0; i < model.rowCount(); ++i) {
           QString option = model.record(i).value("correct_option").toString();
           QString obtained = model.record(i).value("marked_option").toString();
          QString q_no = model.record(i).value("q_no").toString();

        if(option == obtained)
        {

            QSqlQuery qry;
            qry.prepare("UPDATE '"+user+"' SET marks_obtained = '1' WHERE q_no is '"+q_no+"';");
            qry.exec();
            number++;
        }
        else
        {
            QSqlQuery qry;
            qry.prepare("UPDATE '"+user+"' SET marks_obtained = 'null' WHERE q_no is '"+q_no+"';");
            qry.exec();

        }
        }

           QString sum;

       QSqlQueryModel model1;
          model1.setQuery("SELECT SUM(marks_obtained) FROM '"+user+"' WHERE marks_obtained = '1';");
        sum = model1.record(0).value("SUM(marks_obtained)").toString();

        QDateTime time1;
        QString time2 = time1.currentDateTime().toString();
        QString str = QString("INSERT INTO results VALUES('"+user+"','%1','"+sum+"','"+time2+"');").arg(number);
        QSqlQuery qry1;
        qry1.prepare(str);
        qry1.exec();

    conn.connClose();
    hide();
    fns = new finish(this);
    fns->showFullScreen();
}
