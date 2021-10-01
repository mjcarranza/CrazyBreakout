//
// Created by abner on 1/10/21.
//

#ifndef SERVERPROJECT_GAME_H
#define SERVERPROJECT_GAME_H
#include "SocketServer.h"
#include "Block.h"

class Game {
public:
    Game();
    bool update_parameters(SocketServer* socket);
    bool del_ball(string balladdr);
    void create_block();
    void notify_hit(string balladdr);
    void check_incoming();
private:
    SocketServer* socketServer;
    vector<Block> blocks;
};


#endif //SERVERPROJECT_GAME_H
