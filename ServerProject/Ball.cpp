//
// Created by abner on 23/9/21.
//

#include "Ball.h"
#include <string>
using namespace std;
Ball::Ball() {};

/**
 *
 * @param newAddr
 */
void Ball::set_addr(int newAddr) {
    addr = newAddr;
}

/**
 * @brief getter for the Balls address
 * @return
 */
string Ball::get_addr() {
    return addr;
}


int Ball::get_depthlevel() {
    return depth_level;
}

int Ball::get_speed() {
    return speed;
}

int Ball::increase_speed(int incr) {
    return speed+=incr;
}