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
    MainWindow w;

    QString servIp;
    QString servPort;

    // crear una instancia de esta clase

    servIp = w.getIP(); // se obtiene el ip ingresado por el usuario // en formato QString
    string str1 = servIp.toStdString();
    const char* ip= "192.168.1.108";

    //servPort = w.getPORT(); // se obtiene el puerto ingresado por el usuario // en formato QString
    //string str2 = servPort.toStdString();
    int prt= 4050;

    try {
        client->Connect(ip,prt);
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
    //7game->show(); // show game`s window

    cout<<"va a entrar al while"<<endl;
    while (true){
        string json="hola desde el cliente 2!";
        //cout<<"el mensaje a enviar es: "<<endl;
        //cin>>json;
        //cout<<"se leyo el mensaje: "<<json<<endl;
        if (json == "salir"){
            break;
        }
        cout<<"el mensaje a enviar es: "<<json<<endl;
        client->setMessage(json.c_str());
        break;
    }
    cout<<"se salio del bucle"<<endl;
    delete client;
    //luego de conectarse al server que se abra la ventana del juego
}

void MainWindow::on_playBtn_clicked()
{

    QMessageBox* msg;

    IP = ui->ipLineEdit->text(); // gets the text in the ipLineEdit Qstring format
    Port = ui->portLineEdit->text(); // gets the text in the portLineEdit QString format
    string textIP = IP.toUtf8().constData(); // convert ip to string
    string textPort = Port.toUtf8().constData(); // convert port to string
    // creating a QMessageBox for warning
    msg = new QMessageBox();
    msg->setWindowTitle("WARNING");
    msg->setIcon(QMessageBox::Warning);
    msg->setStyleSheet("background-color: rgb(0, 0, 0); color: red");

    if(textIP==""){ // if ip is not valid
        msg->setText("IP Address Required!");
        msg->show();
    }
    else if(textPort==""){ // if port is not valid
        msg->setText("Server`s Port Required!");
        msg->show();
    }
    else{
        cout<<"IP address: "<<textIP<<endl; // print ip address
        cout<<"Server`s port: "<<textPort<<endl; // print port
        //close(); // close main window

        this->connecting(); // connecting to server.
    }

}

QString MainWindow::getIP(){
    return IP;
}

QString MainWindow::getPORT(){
    return Port;
}
