

#include "Block.h"

#include <utility>
Block::Block(string intype, string newindex) {
    if (intype=="Comun"){
        hits_left = 1;
        point2give = 10;}
    else if(intype=="Doble")
    {hits_left = 2;
        point2give= 20;}
    else if(intype=="Triple")
    {hits_left = 3;
        point2give = 30;}
    else if(intype=="Profundo")
    {hits_left = -1;
        point2give=9999999;}
    else if(intype=="Interno")
    {hits_left = 1;
        point2give = 0;}

    type = intype;
    addr = newindex;

}

string Block::get_addr() {
    return addr;
}

int Block::hit() {
    return hits_left--;
}

string Block::get_type() {
    return type;
}

int Block::get_points2give() {
    return point2give;
}


