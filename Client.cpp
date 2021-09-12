#include "Client.h"

Client::Client(){}
void Client::Connect(const char* ip, int port) {

    // create a descriptor
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (descriptor < 0){
        cout<<"Error while creating the socket"<<endl;
    }
    info.sin_family = AF_INET; // Connection type ipv4
    info.sin_addr.s_addr = inet_addr(ip); // Accept any
    info.sin_port = ntohs(port); // Define port
    memset(&info.sin_zero, 0, sizeof(info.sin_zero)); // Clean structure

    if ((connect(descriptor,(sockaddr *)&info, (socklen_t) sizeof(info)))<0){
        cout<<"Error while connecting to the server"<<endl;
    }
    cout<<"Connected successfully!"<<endl;
    pthread_t hilo;
    pthread_create(&hilo,0,Client::Manager,(void*) this);
}

void *Client::Manager(void *obj) {
    Client* c = (Client*)obj;
    while (true){
        string message;
        char buffer[1024] = {0};
        // condition: if the player closes the game ---> break;
        while (true){
            memset(buffer,0,1024);
            int bytes = recv(c->descriptor, buffer, 1024, 0);
            message.append(buffer, bytes);
            if (bytes<=0){
                close(c->descriptor);
                pthread_exit(NULL);
            }
            if (bytes<1024){
                break;
            }
        }
        cout<<message<<endl; // en mesnaje viene lo que se envio desde el servidor. ver hacia donde mando esto.
    }
    close(c->descriptor);
    pthread_exit(NULL);
}

void Client::setMessage(const char *msj) {
    send(descriptor,msj, strlen(msj),0);
}
