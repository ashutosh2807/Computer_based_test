#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>


namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:

    explicit result(QWidget *parent = nullptr);
    ~result();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_loadlist_clicked();

private:
    Ui::result *ui;
};

#endif // RESULT_H
