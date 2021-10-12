//
// Created by abner on 23/9/21.
//

#ifndef SERVERPROJECT_BALL_H
#define SERVERPROJECT_BALL_H


class Ball {
public:
    Ball();
    void set_addr(int newAddr);
    string get_addr();
    int get_depthlevel();
    int get_speed();
    int increase_speed(int incr);
private:
    int speed{};
    int depth_level{};
    string addr{};


};


#endif //SERVERPROJECT_BALL_H
