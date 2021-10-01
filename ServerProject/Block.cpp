//
// Created by abner on 30/9/21.
//

#include "Block.h"

#include <utility>
Block::Block(string intype) {
    if (intype=="Comun")
        hits_left = 1;
    else if(intype=="Doble")
        hits_left = 2;
    else if(intype=="Triple")
        hits_left = 3;
    else if(intype=="Profundo")
        hits_left = -1;
    else if(intype=="Interno")
        hits_left = 1;
    type = intype;
}

void Block::set_addr(string newaddr) {
    addr = newaddr;
}

string Block::get_addr() {
    return addr;
}

int Block::hit() {
    return hits_left--;
}

string Block::get_type() {

}
