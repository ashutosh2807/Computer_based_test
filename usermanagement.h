#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QMainWindow>


namespace Ui {
class usermanagement;
}

class usermanagement : public QMainWindow
{
    Q_OBJECT

public:

    explicit usermanagement(QWidget *parent = nullptr);
    ~usermanagement();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::usermanagement *ui;
};

#endif // USERMANAGEMENT_H
