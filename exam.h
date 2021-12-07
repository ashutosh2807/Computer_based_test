#ifndef EXAM_H
#define EXAM_H

#include <QMainWindow>

namespace Ui {
class exam;
}

class exam : public QMainWindow
{
    Q_OBJECT

public:

    explicit exam(QWidget *parent = nullptr);
    ~exam();

private slots:
    void on_pushButton_5_clicked();
    void showTime();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_selector_currentTextChanged(const QString &arg1);

private:
    Ui::exam *ui;
};

#endif // EXAM_H
