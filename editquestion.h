#ifndef EDITQUESTION_H
#define EDITQUESTION_H

#include <QMainWindow>

namespace Ui {
class editQuestion;
}

class editQuestion : public QMainWindow
{
    Q_OBJECT

public:
    explicit editQuestion(QWidget *parent = nullptr);
    ~editQuestion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::editQuestion *ui;
};

#endif // EDITQUESTION_H
