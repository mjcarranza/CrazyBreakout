#include "Ball.h"
#include <QTimer>
#include <QBrush>
#include "Game.h"
#include "Paddle.h"
#include "Commonblk.h"
#include "Doubleblk.h"
#include "Tripleblk.h"
#include "Internblk.h"
#include "Deepblk.h"

extern Game* game;

Ball::Ball(QGraphicsItem *parent): QGraphicsRectItem(parent), QObject(){
    // draw rect
    setRect(0,0,20,20);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/ball.png"));
    setBrush(brush);

    // Move ball to the top when the game begins
    velX = 0;
    velY = -5;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBall()));
    timer->start(15);
}

double Ball::getCenterX(){
    return x() + rect().width()/2;
}

void Ball::moveBall(){

    reverseVelocity();
    checkPadCollision();
    checkBlckCollision();
    moveBy(velX,velY);
}
/**
 * @brief Ball::reverseVelocity If ball is out of bounds reverse the velocity.
 */
void Ball::reverseVelocity(){
    // check if out of bound, if so, reverse the proper velocity
    double screenW = game->width();

    // left edge
    if (mapToScene(rect().topLeft()).x() <= 0){
        velX = -1 * velX;
    }

    // right edge
    if (mapToScene(rect().topRight()).x() >= screenW){
        velX = -1 * velX;
    }

    // top edge
    if (mapToScene(rect().topLeft()).y() <= 0){
        velY = -1 * velY;
    }

    // bottom edge - NONE (can fall through bottom)
}
/**
 * @brief Ball::checkPadCollision If collides with paddle, reverse yVelocity, and add xVelocity
 * depending on where (in the x axis) the ball hits the paddle.
 */
void Ball::checkPadCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            // reverse the y velocity
            velY = -1 * velY;

            // add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            velX = (velX + dvx)/15;

            return;
        }
    }
}
/**
 * @brief Ball::checkBlckCollision Checks if the ball collides with a block
 * (destroy blocks and reverse ball velocity)
 */
void Ball::checkBlckCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    QList<QGraphicsItem*> dItems = collidingItems();
    QList<QGraphicsItem*> tItems = collidingItems();
    QList<QGraphicsItem*> iItems = collidingItems();
    QList<QGraphicsItem*> deepItems = collidingItems();

    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        CommonBlk* cblock = dynamic_cast<CommonBlk*>(cItems[i]);
        DoubleBlk *dblock = dynamic_cast<DoubleBlk*>(dItems[i]);
        TripleBlk *tblock = dynamic_cast<TripleBlk*>(tItems[i]);
        InternBlk *iblock = dynamic_cast<InternBlk*>(iItems[i]);
        DeepBlk *deepblock = dynamic_cast<DeepBlk*>(deepItems[i]);
        // collides with block
        if (cblock){
            double yPad = 5;
            double xPad = 5;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = cblock->pos().x();
            double blocky = cblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * velY;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * velY;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * velX;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * velX;
            }

            // delete block(s)
            game->scene->removeItem(cblock);
            delete cblock;
        }
        // collides with block
        if (dblock){
            double yPad = 5;
            double xPad = 5;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = dblock->pos().x();
            double blocky = dblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * velY;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * velY;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * velX;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * velX;
            }

            // delete block(s)
            game->scene->removeItem(dblock);
            delete dblock;
        }
        if (tblock){
            double yPad = 5;
            double xPad = 5;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = tblock->pos().x();
            double blocky = tblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * velY;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * velY;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * velX;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * velX;
            }

            // delete block(s)
            game->scene->removeItem(tblock);
            delete tblock;
        }
        if (iblock){
            double yPad = 5;
            double xPad = 5;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = iblock->pos().x();
            double blocky = iblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * velY;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * velY;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * velX;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * velX;
            }

            // delete block(s)
            game->scene->removeItem(iblock);
            delete iblock;
        }
        if (deepblock){
            double yPad = 5;
            double xPad = 5;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = deepblock->pos().x();
            double blocky = deepblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * velY;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * velY;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * velX;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * velX;
            }

            // delete block(s)
            game->scene->removeItem(deepblock);
            delete deepblock;
        }
    }
}
