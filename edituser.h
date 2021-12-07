#ifndef EDITUSER_H
#define EDITUSER_H

#include <QMainWindow>

namespace Ui {
class editUser;
}

class editUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit editUser(QWidget *parent = nullptr);
    ~editUser();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::editUser *ui;
};

#endif // EDITUSER_H
