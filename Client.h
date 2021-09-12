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
using namespace std;

class Client{
public:
    Client();
    void Connect(const char* ip, int port); // run server
    void setMessage(const char* msj);

private:
    int descriptor; // identifies by a number the connected devices
    sockaddr_in info; // socket server information

    static void *Manager(void* obj);

};

#endif // CLIENT_H
