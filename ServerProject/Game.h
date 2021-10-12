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
    Game(SocketServer *pServer);
    Game();

    /***
     * @brief it sends the updated score to the client
     * @return
     */
    bool update_parameters();

    /**
     * @brief it notifies the player that it needs to delete a ball
     * @param balladdr
     * @return
     */
    bool del_ball(string balladdr);

    /**
     * @brief it decreases the amount of hits in a block and notifies the client if it needs to be deleted
     * @param balladdr
     * @param blkaddr
     */
    void notify_hit(string balladdr, string blkaddr);

    /**
     * @brief it creates a block and adds it to the game block list
     * @param type
     * @param index
     */
    void create_block(string type, string index);
    Player player;
private:
    SocketServer *socketptr;
    vector<Block> blocks;

    vector<string> blocktypes = {"Comun", "Doble", "Triple", "Profundo", "Interno"};

    bool update_parameters();
};


#endif //SERVERPROJECT_GAME_H
