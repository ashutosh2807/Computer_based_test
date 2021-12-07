#ifndef PASSADMIN_H
#define PASSADMIN_H

#include <QMainWindow>

namespace Ui {
class passadmin;
}

class passadmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit passadmin(QWidget *parent = nullptr);
    ~passadmin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::passadmin *ui;
};

#endif // PASSADMIN_H
