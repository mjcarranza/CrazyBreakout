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

    /**
     * @brief gets the value for the identifier
     * @return
     */
    string get_addr();

    /**
     * @brief it get a block hit. NOtifies the client to delete it if it has no hits left
     * @return amount of hits left
     */
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
