#include "Client.h"

string nickname;
/**
 * @brief Client::Client constructor creates a new client
 */
Client::Client(){}
void Client::Connect(const char* ip, int port) {

    // create a descriptor
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (descriptor < 0){
        cout<<"Error while creating the socket"<<endl;
    }
    info.sin_family = AF_INET; // Connection type ipv4
    info.sin_addr.s_addr = inet_addr(ip); // Accept any // esta IP es la del servidor
    info.sin_port = ntohs(port); // Define port
    memset(&info.sin_zero, 0, sizeof(info.sin_zero)); // Clean structure

    if ((connect(descriptor,(sockaddr *)&info, (socklen_t) sizeof(info)))<0){
        cout<<"Error while connecting to the server"<<endl;
    }else{
        cout<<"Connected successfully!"<<endl;
        pthread_t hilo;
        pthread_create(&hilo,0,Client::Manager,(void*) this);
    }
}
/**
 * @brief Client::Manager manages the connection between the client and the server
 * @param obj any type
 * @return
 */
void *Client::Manager(void *obj) {
    Client* c = (Client*)obj;
    while (true){ // this loop is not necessary ////////////////////////////////////////////////
        string message;
        char buffer[1024] = {0};
        while (true){
            memset(buffer,0,1024);
            int bytes = recv(c->descriptor, buffer, 1024, 0);
            message.append(buffer, bytes);
            if (bytes<=0){
                close(c->descriptor);
                pthread_exit(nullptr);
            }
            if (bytes<1024){
                break;
            }
        }
        cout<<message<<endl; // message sent from server.
    }
    close(c->descriptor); // see if it is necessary!!!
    pthread_exit(nullptr);
}
/**
 * @brief Client::setMessage sends a message to the server
 * @param msj
 */
void Client::setMessage(const char *msj) {
    send(descriptor,msj, strlen(msj),0);
}

