
#include "Server.h"

Server::Server() {}

bool Server::createSock() {
    // create a descriptor
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (descriptor < 0){
        return false;
    }
    info.sin_family = AF_INET; // Connection type ipv4
    info.sin_addr.s_addr = INADDR_ANY; // Accept any
    info.sin_port = htons(4050); // Define port
    memset(&info.sin_zero, 0, sizeof(info.sin_zero)); // Clean structure
    return true;
}

bool Server::bindKernel() {
    if (bind(descriptor,(sockaddr *)&info, (socklen_t) sizeof(info))<0){
        return false;
    }
    // Listen to clients
    listen(descriptor, 4);
    return true;
}

void Server::run() {
    if (!createSock()){
        throw string("There was an error when creating the socket");
    }
    if (!bindKernel()){
        throw string("There was an error when binding kernel");
    }

    // infinite loop to accept clients
    while (true){
        dataSocket data;
        socklen_t size = sizeof(data.info);
        cout<<"Waiting for clients!"<<endl;
        data.descriptor = accept(descriptor,(sockaddr *)&data.info, &size);
        if (data.descriptor <0){
            cout<<"Error when accepting client"<<endl;
            break;
        }
        else{
            clients.push_back(data.descriptor);
            cout<<"Client connected!"<< endl;
            pthread_t hilo;
            pthread_create(&hilo,0,Server::clientManager,(void*)&data);
            pthread_detach(hilo);
        }
    }
    close(descriptor);

}

void *Server::clientManager(void *obj) {
    dataSocket* data = (dataSocket*)obj;
    while (true){
        string message;
        char buffer[1024] = {0};
        while (true){
            memset(buffer,0,1024);
            int bytes = recv(data->descriptor, buffer, 1024, 0);
            message.append(buffer, bytes);
            if (bytes<=0){
                cout<<"Client disconnected!"<<endl;
                close(data->descriptor);
                pthread_exit(NULL);
            }
            if (bytes<1024){
                break;
            }
        }
        cout<<message<<endl; // en mesnaje viene lo que se envio desde el cliente. ver hacias donde mando esto cuando la logica del juego se haya implementado.
    }
    close(data->descriptor);
    pthread_exit(NULL);
}

void Server::setMessage(const char *msj) {
    for (int i = 0; i < clients.size(); ++i) {
        send(clients[i], msj, strlen(msj),0); // clients[i] implica a todos los clientes, si se quiere enviar a un cliente en específico, utilizar clientes[1 o 2 o 3 etc] lo cual es el descriptor del cliente
    }
}




