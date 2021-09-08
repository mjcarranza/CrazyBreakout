#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playBtn_clicked()
{
    gamewindow *game = new gamewindow();
    game->show();
    close();
}

