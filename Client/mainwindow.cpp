#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.h"
#include "QMessageBox"
#include "Game.h"

Game* game;
/**
 * @brief MainWindow::MainWindow constructor
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/**
 * @brief MainWindow::~MainWindow destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_playBtn_clicked checks when the button is clicked to start the game
 */
void MainWindow::on_playBtn_clicked()
{
    QMessageBox* msg;
    game = new Game();

    nick = ui->nicknameLineEdit->text(); // gets the text in the portLineEdit QString format
    string textNick = nick.toUtf8().constData(); // convert nick to string


    // creating a QMessageBox for warning
    msg = new QMessageBox();
    msg->setWindowTitle("WARNING");
    msg->setIcon(QMessageBox::Warning);
    msg->setStyleSheet("background-color: rgb(0, 0, 0); color: red");

    if(textNick==""){ // if ip is not valid
        msg->setText("Nickname Required!");
        msg->show();
    }
    else{
        game->show();
        game->setNickName(nick);
        close(); // close main window
        // call boolean variable isPlaying
    }

}

