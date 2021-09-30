#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/**
 * @brief The Ball class creates objects of type Ball
 */
class Ball: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructor
    Ball(QGraphicsItem* parent=NULL);

    // public methods
    double getCenterX();
    void connecting();

public slots:
    // public slots
    void moveBall();

private:
    // private attributes
    double velX;
    double velY;
    int depthLvl = 0;
    int addBallCounter = 0;
    int ballCounter = 1;

    // private methods
    void reverseVelocity();
    void checkPadCollision();
    void checkBallLeft();
    void checkBlckCollision();
    void addBall();
};

#endif // BALL_H
