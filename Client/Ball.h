#ifndef BALL_H
#define BALL_H


#include <QGraphicsRectItem>

class Ball: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
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
