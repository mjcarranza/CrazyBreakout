#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include "Client.h"
#include "QMessageBox"
Client* client;


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

void *clientRun(void *){

    try {
        client->Connect();
    } catch (string ex) {
        cout<< ex <<endl;
    }
    pthread_exit(nullptr);
}

void MainWindow::connecting(){
    gamewindow *game = new gamewindow();

    // Connecting to the server.
    client = new Client();
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,nullptr);
    pthread_detach(hiloClient);
    game->show(); // show game`s window

    string json="hola desde el cliente 2!";

    while (true){ // /////////////////////////////// arreglar este bucle para que se ejecute constantemente

        //cin>>json;
        if (json == "salir"){
            break;
        }
        client->setMessage(json.c_str());
        break;
    }
    delete client;
    //luego de conectarse al server que se abra la ventana del juego
}

void MainWindow::on_playBtn_clicked()
{
    QMessageBox* msg;

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
        gamewindow *game = new gamewindow();
        client->setNickname(textNick);
        game->show(); // show game`s window
        close(); // close main window
        // llamar var bool que diga is playingt

        //this->connecting(); // connecting to server.
    }

}

