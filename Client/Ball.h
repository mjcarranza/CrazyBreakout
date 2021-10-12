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
    void addBall();
    void deleteBlk(string type, string index);
    void deleteBall(string index);
    void addDepthLevel(QString lvl);
    void blkCreated(string blkType);
    void notify(QString str);

public slots:
    // public slots
    void moveBall();

private:
    // private attributes
    double velX;
    double velY;
    int depthLvl = 0;
    int Counter = 0;
    int randomNum = 0;
    int ballCounter = 1;
    int scre = 0;

    // private methods
    void reverseVelocity();
    void checkPadCollision();
    void checkBallLeft();
    void checkBlckCollision();

};

#endif // BALL_H
