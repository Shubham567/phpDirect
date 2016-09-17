#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QIcon icn(":/icon/php.ico");
    this->setWindowIcon(icn);
    pref=new QSettings("SS7 Workstation","phpDirect");
    this->setWindowTitle("phpDirect");
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::WindowTitleHint);
    this->setFixedSize(600,180);
    browserL=pref->value("directLoc/browser").toString();
    editorL=pref->value("directLoc/editor").toString();
    serverL=pref->value("directLoc/server").toString();
    ui->lineEdit->setText(browserL);
    ui->lineEdit_2->setText(editorL);
    ui->lineEdit_3->setText(serverL);
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
    ui->lineEdit_3->setDisabled(true);
    change=0;
    ui->pushButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    browserL=QFileDialog::getOpenFileName(this,"Select Browser","c://","Executable file (*.exe)");
    if(!browserL.isEmpty())
    {
    ui->lineEdit->setText(browserL);
    change=1;
    ui->pushButton->setDisabled(false);
    }
}

void MainWindow::on_toolButton_2_clicked()
{
    editorL=QFileDialog::getOpenFileName(this,"Select Editor","c://","Executable file (*.exe)");
    if(!editorL.isEmpty())
    {
    ui->lineEdit_2->setText(editorL);
    change=1;
    ui->pushButton->setDisabled(false);
    }
}

void MainWindow::on_toolButton_3_clicked()
{
    serverL=QFileDialog::getExistingDirectory(this,"Select Your Server Location","c://");
    if(!serverL.isEmpty())
    {
    ui->lineEdit_3->setText(serverL);
    change=1;
    ui->pushButton->setDisabled(false);
    }
}

void MainWindow::on_pushButton_clicked()
{
    pref->beginGroup("directLoc");
    if(!browserL.isEmpty())
        pref->setValue("browser",browserL);
    if(!editorL.isEmpty())
        pref->setValue("editor",editorL);
    if(!serverL.isEmpty())
        pref->setValue("server",serverL);
    if(change)
        QMessageBox::information(this,"phpDirect", "Changes saved to preferences!");

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"About","This app can help resolve the hassle of selecting browser and editor for same php code.\n Develped By: Shekhar");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"phpDirect", "Application is quiting!");
    this->close();
}
