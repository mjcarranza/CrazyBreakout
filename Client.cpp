#include "Client.h"

int puerto;
string nickname;
const char* servip;

Client::Client(){}
void Client::Connect() {
    cout<<"valor de puerto en connect> "<<puerto<<endl;
    cout<<"valor de ip en connect> "<<servip<<endl;
    cout<<"valor de nick en connect> "<<nickname<<endl;

    // create a descriptor
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (descriptor < 0){
        cout<<"Error while creating the socket"<<endl;
    }
    info.sin_family = AF_INET; // Connection type ipv4
    info.sin_addr.s_addr = inet_addr(servip); // Accept any
    info.sin_port = ntohs(puerto); // Define port
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
 * @brief Client::setPort
 * @param prt
 */
void Client::setPort(int prt)
{
    puerto = prt; // save port in a global variable
}
/**
 * @brief Client::setIp
 * @param ip
 */
void Client::setIp(string ip)
{
    servip = ip.c_str(); // save the ip in a global variable
}
/**
 * @brief Client::setNickname
 * @param nick
 */
void Client::setNickname(string nick)
{
    nickname = nick; // save nickname in a global variable
}


