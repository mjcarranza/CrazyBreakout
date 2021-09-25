#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.h"
#include "QMessageBox"
#include "Game.h"

Game* game;
Client* client;
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
 * @brief clientRun independent method tries connecting to the server
 * @return
 */
void *clientRun(void *){

    try {
        client->Connect();
    } catch (string ex) {
        cout<< ex <<endl;
    }
    pthread_exit(nullptr);
}
/**
 * @brief MainWindow::connecting method creates a new thread for constant communication with server
 */
void MainWindow::connecting(){

    // Connecting to the server.
    client = new Client();
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,nullptr);
    pthread_detach(hiloClient);

    string json="hola desde el cliente 2!";

    while (true){ // excecutes constatly to send messages to the server

        cin>>json;
        if (json == "salir"){
            break;
        }
        client->setMessage(json.c_str());
        break;
    }
    delete client;
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
        close(); // close main window
        // call boolean variable isPlaying

        //this->connecting(); // connecting to server.
    }

}

