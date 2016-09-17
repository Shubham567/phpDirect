#ifndef SELECTION_H
#define SELECTION_H

#include <QDialog>

namespace Ui {
class selection;
}

class selection : public QDialog
{
    Q_OBJECT

public:
    explicit selection(int *option,QWidget *parent = 0);
    ~selection();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::selection *ui;
    int *ptr;
};

#endif // SELECTION_H
