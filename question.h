#ifndef QUESTION_H
#define QUESTION_H

#include <QMainWindow>


namespace Ui {
class question;
}

class question : public QMainWindow
{
    Q_OBJECT

public:

    explicit question(QWidget *parent = nullptr);
    ~question();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::question *ui;
};

#endif // QUESTION_H
