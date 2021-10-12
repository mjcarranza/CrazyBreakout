//
// Created by abner on 30/9/21.
//

#ifndef SERVERPROJECT_BLOCK_H
#define SERVERPROJECT_BLOCK_H
#include <string>
using namespace std;
class Block {
public:
    Block(string intype, string newindex);
    string get_addr();
    int hit();
    string get_type();
    int get_points2give();
private:
    string type;
    int hits_left;
    string addr;
    int point2give;
};


#endif //SERVERPROJECT_BLOCK_H
