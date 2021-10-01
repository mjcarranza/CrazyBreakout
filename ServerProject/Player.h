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
    /**
     *
     * @param incr
     * @return
     * @brief it increases the player score
     */
    int increase_score(int incr);

    /**
     * @brief it changes the paddle size
     * @param incr
     * @return
     */
    int increase_paddle_size(int incr);

    /**
     * @brief getter for playerś score
     * @return the score
     */
    int get_score();

};


#endif //SERVERPROJECT_PLAYER_H
