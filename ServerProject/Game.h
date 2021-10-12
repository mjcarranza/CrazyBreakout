//
// Created by abner on 1/10/21.
//

#ifndef SERVERPROJECT_GAME_H
#define SERVERPROJECT_GAME_H
#include "SocketServer.h"
#include "Block.h"
#include "json.hpp"
#include "Player.h"
using json = nlohmann::json;

class Game{
public:
    Game(SocketServer* socketptrin);
    bool update_parameters();
    bool del_ball(string balladdr);
    void notify_hit(string balladdr);
    void check_incoming();
private:
    SocketServer* socketptr;
    vector<Block> blocks;
    Player player;
    vector<string> blocktypes = {"Comun", "Doble", "Triple", "Profundo", "Interno"};
};


#endif //SERVERPROJECT_GAME_H
