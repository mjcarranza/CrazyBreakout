#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connecting();
    QString IP;
    QString Port;
    QString nick;

public slots:
    void on_playBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
