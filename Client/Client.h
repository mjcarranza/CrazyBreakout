#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>
#include <QString>
using namespace std;
/**
 * @brief The Client class connects the game`s interface with the server
 */
class Client{
private:
    int descriptor; // identifies by a number the connected devices
    sockaddr_in info; // socket server information

    static void *Manager(void* obj);

public:
    Client();
        void Connect(const char* ip, int port); // run server
        void setMessage(const char* msj);

};

#endif // CLIENT_H
