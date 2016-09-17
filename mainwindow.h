#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_pushButton_clicked();

    void on_actionAbout_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString browserL;
    QString serverL;
    QString editorL;
    QSettings *pref;
    bool change;
};

#endif // MAINWINDOW_H
