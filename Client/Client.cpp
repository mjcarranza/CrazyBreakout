#include "Client.h"
#include "Ball.h"
#include "json.hpp"
#include "Game.h"

using json = nlohmann::json;
Ball* ball2;
Game* game2;

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
    while (true){
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
        // se parsea el mensaje enviado desde el cliente
        auto json = json::parse(message);

        // action for increasing the score
        if (json["type"] == "addScore"){
            string msj = json["score"];
            QString str = QString::fromUtf8(msj.c_str());
            game2->setScore(str);
        }
        // action to reduce paddle`s size
        if (json["type"] == "reduce"){
            game2->reducePadd();
        }
        // action to add a new ball
        if (json["type"] == "newBall"){
            game2->addNewBall();
            ball2->addBall();
        }
        // action to delete a ball
        if (json["type"] == "deleteBall"){
            string msj = json["index"];
            ball2->deleteBall(msj);
        }
        // action to delete a block
        if (json["type"] == "deleteBlk"){
            string blkType = json["block"];
            string blkIndex = json["index"];
            ball2->deleteBlk(blkType, blkIndex);
        }
        // action to add depth level
        if (json["type"] == "depthLevel"){
            string msj = json["level"];
            QString str = QString::fromUtf8(msj.c_str());
            ball2->addDepthLevel(str);
        }

        cout<<message<<endl; // message sent from server.
    }
    close(c->descriptor);
    pthread_exit(nullptr);
}
/**
 * @brief Client::setMessage sends a message to the server
 * @param msj
 */
void Client::setMessage(const char *msj) {
    send(descriptor,msj, strlen(msj),0);
}

