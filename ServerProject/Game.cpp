#include "Game.h"
#include "Player.h"

Game::Game(SocketServer* socketptrin) {
    socketptr = socketptrin;
    player = Player();
}

bool Game::update_parameters() {
    json jmsg;
    jmsg["updatedScore"] = player.get_score();
    for (int i =0; player.get_balls().size(); i++){
        string key = player.get_balls()[i].get_addr();
        jmsg[key + "size"] = player.get_balls()[i].get_speed();
    }
    string msg = jmsg.dump();
    socketptr->setMessage(msg.c_str());
}


