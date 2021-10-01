#ifndef SERVERPROJECT_PLAYER_H
#define SERVERPROJECT_PLAYER_H
#include "Ball.h"
#include <vector>

using namespace std;

class Player {
private:
    Player();
    int score;
    int paddle_size;
    vector<Ball> balls;
public:
    int increase_score(int incr);
    int increase_paddle_size(int incr);
    int get_score();

};


#endif //SERVERPROJECT_PLAYER_H
