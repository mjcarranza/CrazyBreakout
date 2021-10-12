//
// Created by abner on 22/9/21.
//

#include "Player.h"
Player::Player(){};

int Player::get_score() {
    return score;
}

int Player::increase_paddle_size(int incr) {
    return paddle_size+=incr;
}

int Player::increase_score(int incr) {
    return score+=incr;
}

vector<Ball> Player::get_balls() {
    return balls;
}