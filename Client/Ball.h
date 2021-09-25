#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
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

public slots:
    // public slots
    void moveBall();

private:
    // private attributes
    double velX;
    double velY;

    // private methods
    void reverseVelocity();
    void checkPadCollision();
    void checkBlckCollision();
};

#endif // BALL_H
