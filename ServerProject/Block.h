//
// Created by abner on 30/9/21.
//

#ifndef SERVERPROJECT_BLOCK_H
#define SERVERPROJECT_BLOCK_H
#include <string>
using namespace std;
class Block {
public:
    Block(string intype);
    void set_addr(string newaddr);
    string get_addr();
    int hit();
    string get_type();
private:
    string type;
    int hits_left;
    string addr;
};


#endif //SERVERPROJECT_BLOCK_H
