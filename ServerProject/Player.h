#ifndef SERVERPROJECT_PLAYER_H
#define SERVERPROJECT_PLAYER_H
#include "Ball.h"
#include <vector>

using namespace std;

class Player {
private:

    int score;
    int paddle_size;
    vector<Ball> balls;
public:
    Player();
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

    /**
     * @brief getter for player,s ball vector
     * @return
     */
    vector<Ball> get_balls();
};


#endif //SERVERPROJECT_PLAYER_H
