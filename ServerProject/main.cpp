#include "SocketServer.h"
#include "json.hpp"
#include "Game.h"


using json = nlohmann::json;
SocketServer* server;
Game* game;

void * serverRun(void *){
    try{
        server->run();

    } catch (string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}

int main() {
    server = new SocketServer(game);
    pthread_t serverThread;
    pthread_create(&serverThread, 0, serverRun, NULL);
    pthread_detach(serverThread);
    while (true){
        if (server->getNoClients()>=1)
            game = new Game(server);
            break;
    }
    return 0;
}
