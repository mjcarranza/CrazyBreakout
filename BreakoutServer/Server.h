
#ifndef BREAKOUTSERVER_SERVER_H
#define BREAKOUTSERVER_SERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
using namespace std;

//Structure for representing clients // gets the clients descriptor and info
struct dataSocket{
    int descriptor;
    sockaddr_in info;
};

class Server{
public:
    Server();
    void run(); // run server
    void setMessage(const char* msj);

private:
    int descriptor; // identifies by a number the connected devices
    sockaddr_in info; // socket server information
    vector<int> clients; // gets all the connected devices/clients

    bool createSock(); // verify if there is a problem
    bool bindKernel();
    static void *clientManager(void* obj);

};

#endif //BREAKOUTSERVER_SERVER_H
