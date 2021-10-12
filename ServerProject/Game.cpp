#include "Game.h"
#include "Player.h"

Game::Game(SocketServer* socketptrin) {
    socketptr = socketptrin;
    player = Player();
}

bool Game::update_parameters() {
    json jmsg;
    jmsg["type"] = "addScore";
    jmsg["score"]=player.get_score();
    /**
    for (int i =0; player.get_balls().size(); i++){
        string key = player.get_balls()[i].get_addr();
        jmsg[key + "size"] = player.get_balls()[i].get_speed();
    }
     */
    string msg = jmsg.dump();
    socketptr->setMessage(msg.c_str());
}


bool Game::del_ball(string balladdr) {
    json jmgs;
    jmgs["type"]="deleteBall";
    jmgs["index"] = balladdr;
    string msg=jmgs.dump();
    socketptr->setMessage(msg.c_str());
    return player.del_ball(stoi(balladdr));
}

void Game::notify_hit(string balladdr, string blkaddr) {
    if(blocks[stoi(blkaddr)].hit()<=0){
        json jmsg;
        jmsg["type"]="deleteBlk";
        jmsg["block"]=blocks[stoi(blkaddr)].get_type();
        jmsg["index"]=blkaddr;
        string msg = jmsg.dump();
        socketptr->setMessage(msg.c_str());
        player.increase_score(blocks[stoi(blkaddr)].get_points2give());
        blocks.erase(blocks.begin()+(stoi(blkaddr)-1));
        update_parameters();
    }

}

void Game::create_block(string type, string index) {
    Block newblock=Block(type, index);
    blocks.push_back(newblock);
}