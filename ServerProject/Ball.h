//
// Created by abner on 23/9/21.
//

#ifndef SERVERPROJECT_BALL_H
#define SERVERPROJECT_BALL_H


class Ball {
public:
    Ball();
    void set_addr(int newAddr);
    int get_addr();
    int get_depthlevel();
    int get_speed();
    int increase_speed(int incr);
private:
    int speed{};
    int depth_level{};
    int addr{};


};


#endif //SERVERPROJECT_BALL_H
