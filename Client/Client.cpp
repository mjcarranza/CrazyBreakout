#include "Client.h"

string nickname;

Client::Client(){}
void Client::Connect() {
    cout<<"valor de nick en connect> "<<nickname<<endl;

    // create a descriptor
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (descriptor < 0){
        cout<<"Error while creating the socket"<<endl;
    }
    info.sin_family = AF_INET; // Connection type ipv4
    info.sin_addr.s_addr = inet_addr("192.168.1.108"); // Accept any
    info.sin_port = ntohs(4050); // Define port
    memset(&info.sin_zero, 0, sizeof(info.sin_zero)); // Clean structure

    if ((connect(descriptor,(sockaddr *)&info, (socklen_t) sizeof(info)))<0){
        cout<<"Error while connecting to the server"<<endl;
    }
    cout<<"Connected successfully!"<<endl;
    pthread_t hilo;
    pthread_create(&hilo,0,Client::Manager,(void*) this);
}
/**
 * @brief Client::Manager
 * @param obj
 * @return
 */
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
        cout<<message<<endl; // en mensaje viene lo que se envio desde el servidor. ver hacia donde mando esto.
    }
    close(c->descriptor);
    pthread_exit(NULL);
}
/**
 * @brief Client::setMessage
 * @param msj
 */
void Client::setMessage(const char *msj) {
    send(descriptor,msj, strlen(msj),0);
}

/**
 * @brief Client::setNickname
 * @param nick
 */
void Client::setNickname(string nick)
{
    nickname = nick; // save nickname in a global variable
}


