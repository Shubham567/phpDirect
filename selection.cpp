#include "selection.h"
#include "ui_selection.h"


selection::selection(   int *option,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selection)
{
    ptr=option;
    ui->setupUi(this);
    this->setWindowTitle("phpDirect");
}

selection::~selection()
{
    delete ui;
}

void selection::on_pushButton_clicked()
{
    *ptr=1;
    this->close();
}

void selection::on_pushButton_2_clicked()
{
    *ptr=2;
    this->close();
}

void selection::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.at(0)=='1'||arg1.at(0)=='b'||arg1.at(0)=='B')
    {
        *ptr=1;
        this->close();
    }
    else if(arg1.at(0)=='2'||arg1.at(0)=='e'||arg1.at(0)=='E')
    {
        *ptr=2;
        this->close();
    }
    else
    {
        ui->lineEdit->setText(NULL);
    }

}
