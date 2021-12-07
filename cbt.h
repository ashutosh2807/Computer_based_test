#ifndef CBT_H
#define CBT_H

#include <QDialog>

#include<test1.h>
namespace Ui {
class cbt;
}

class cbt : public QDialog
{
    Q_OBJECT

public:
    explicit cbt(QWidget *parent = nullptr);
    ~cbt();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cbt *ui;

    test1 * Test;
};

#endif // CBT_H
