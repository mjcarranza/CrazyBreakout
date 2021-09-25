#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @brief The MainWindow class shows the first window of the game
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Attributes
    QString IP;
    QString Port;
    QString nick;

    // Public Methods
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connecting();

public slots:
    void on_playBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
