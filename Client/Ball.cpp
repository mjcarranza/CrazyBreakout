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
#include "Client.h"
#include "json.hpp"
#include "gameover.h"

using json = nlohmann::json;
Client* client;
gameover* gameOver;
extern Game* game;
/**
 * @brief Ball::Ball constructor for Ball class creates a new ball with its required attributes
 * @param parent
 */
Ball::Ball(QGraphicsItem *parent): QGraphicsRectItem(parent), QObject(){
    /**
     * @brief draw a rectangle for the ball
     */
    setRect(0,0,20,20);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/ball.png"));
    setBrush(brush);

    // Move ball to the top when the game begins
    velX = 0;
    velY = -3;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBall()));
    timer->start(15);
    this->connecting();
}
/**
 * @brief clientRun independent method tries connecting to the server
 * @return
 */
void *clientRun(void *){
    const char *Ip = "192.168.1.109";
    int port = 4050;
    try {
        client->Connect(Ip,port);
    } catch (string ex) {
        cout<< ex <<endl;
    }
    pthread_exit(nullptr);
}
/**
 * This function coverts a pointer data into a string
 */
template <typename T> string ptrToStr(T ptr){
    stringstream s;
    s << ptr;
    return s.str();
}

/**
 * @brief MainWindow::connecting method creates a new thread for constant communication with server
 */
void Ball::connecting(){

    // Connecting to the server.
    client = new Client();
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,nullptr);
    pthread_detach(hiloClient);

    while (true){
        cout<<"leyendo mensajes"<<endl;
        string json;
        //cin>>json;
        if (json == "salir"){
            break;
        }
        client->setMessage(json.c_str());
        break;
    }
    //delete client;
}
/**
 * @brief Ball::getCenterX gets the center of the ball
 * @return Double value
 */
double Ball::getCenterX(){
    return x() + rect().width()/2;
}
/**
 * @brief Ball::moveBall moves the ball arond the playing area
 */
void Ball::moveBall(){

    reverseVelocity();
    checkPadCollision();
    checkBlckCollision();
    // method to check if the ball left the playing area
    //checkBallLeft();
    // call method from game to add a new ball
    //addBall();
    moveBy(velX,velY);
}
/**
 * @brief Ball::reverseVelocity If ball is out of bounds reverse the velocity.
 */
void Ball::reverseVelocity(){
    // Check if out of bound, if so, reverse the proper velocity
    double screenW = game->width();

    // If the ball collides left edge
    if (mapToScene(rect().topLeft()).x() <= 0){
        velX = -1 * velX;
    }

    // If the ball collides right edge
    if (mapToScene(rect().topRight()).x() >= screenW){
        velX = -1 * velX;
    }

    // If the ball collides top edge
    if (mapToScene(rect().topLeft()).y() <= 0){
        velY = -1 * velY;
    }
}
/**
 * @brief Ball::checkPadCollision If collides with paddle, reverse yVelocity, and add xVelocity
 * depending on where (in the x axis) the ball hits the paddle.
 */
void Ball::checkPadCollision(){
    QList<QGraphicsItem*> Items = collidingItems();
    for (size_t i = 0, n = Items.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(Items[i]);
        if (paddle){
            // Reverse the y velocity
            velY = -1 * velY;

            // Add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            velX = (velX + dvx)/15;

            return;
        }
    }
}
/**
 * @brief Ball::checkBallLeft checks if the ball left the playing area
 */
void Ball::checkBallLeft(){
    double bally = pos().y();
    QList<QGraphicsItem*> Items = collidingItems();
    for (size_t i = 0, n = Items.size(); i < n; ++i){
        Ball* ball = dynamic_cast<Ball*>(Items[i]);
        if (bally > 650){
            json message;
            string strball = ptrToStr(ball);
            message["type"] = "ballfell";
            message["ball"] = strball;

            string msg = message.dump();
            client->setMessage(msg.c_str());
            // listen for serve`s response (should be reduce paddle size by 5px )
//            if(reduce paddle size){
//                delete ball;
//                // reduce ballCounter
//                // reduce paddle size
//            }
        }
        if (ballCounter <= 0){
            // Show GameOver window
            gameOver = new gameover();
            gameOver->show();
        }
//        else if (paddle.size <= 0){
//            // Show GameOver window
//            gameOver = new gameover();
//            gameOver->show();
//        }
    }
}
/**
 * @brief Ball::checkBlckCollision Checks if the ball collides with a block
 * (destroy blocks and reverse ball velocity)
 */
void Ball::checkBlckCollision(){
    QList<QGraphicsItem*> bItems = collidingItems();
    QList<QGraphicsItem*> cItems = collidingItems();
    QList<QGraphicsItem*> dItems = collidingItems();
    QList<QGraphicsItem*> tItems = collidingItems();
    QList<QGraphicsItem*> iItems = collidingItems();
    QList<QGraphicsItem*> deepItems = collidingItems();

    // Check for collisions
    for (size_t i = 0, n = cItems.size(); i < n; ++i){

        Ball* ball = dynamic_cast<Ball*>(bItems[i]);
        CommonBlk *cblock = dynamic_cast<CommonBlk*>(cItems[i]);
        DoubleBlk *dblock = dynamic_cast<DoubleBlk*>(dItems[i]);
        TripleBlk *tblock = dynamic_cast<TripleBlk*>(tItems[i]);
        InternBlk *iblock = dynamic_cast<InternBlk*>(iItems[i]);
        DeepBlk *deepblock = dynamic_cast<DeepBlk*>(deepItems[i]);

        double yPad = 9;
        double xPad = 59;
        double ballx = pos().x();
        double bally = pos().y();

        // If the ballcollides with a cblock type
        if (cblock){
            double blockx = cblock->pos().x();
            double blocky = cblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * (velY + 0.2);
                velX = velX + 0.2;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * (velY + 0.2);
                velX = velX + 0.2;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * (velX + 0.2);
                velY = velY + 0.5;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * (velX + 0.2);
                velY = velY + 0.2;
            }

            // delete block(s)
            game->scene->removeItem(cblock);
            delete cblock;
            // TELL SERVER ABOUT THE COLLISION //
            // TELL SERVER TO ADD 10 POINTS TO SCORE //
            json message;
            string strblk = ptrToStr(cblock);
            string strball = ptrToStr(ball);
            message["type"] = "collision";
            message["block"] = strblk;
            message["ball"] = strball;

            string msg = message.dump();
            client->setMessage(msg.c_str());

            // LISTEN TO THE SERVER TO UPDATE TOTAL POINTS TO THE SCORE //

            addBallCounter ++;
        }
        // If the ballcollides with a dblock type
        if (dblock){
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
            // TELL SERVER ABOUT THE COLLISION //
            // TELL SERVER TO ADD 15 POINTS TO SCORE //
            json message;
            string strblk = ptrToStr(dblock);
            string strball = ptrToStr(ball);
            message["type"] = "collision";
            message["block"] = strblk;
            message["ball"] = strball;

            string msg = message.dump();
            client->setMessage(msg.c_str());

            // LISTEN TO THE SERVER TO UPDATE TOTAL POINTS TO THE SCORE //
            addBallCounter ++;
        }
        // If the ballcollides with a tblock type
        if (tblock){
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
            // TELL SERVER ABOUT THE COLLISION //
            // TELL SERVER TO ADD 20 POINTS TO SCORE //
            json message;
            string strblk = ptrToStr(tblock);
            string strball = ptrToStr(ball);
            message["type"] = "collision";
            message["block"] = strblk;
            message["ball"] = strball;

            string msg = message.dump();
            client->setMessage(msg.c_str());

            // LISTEN TO THE SERVER TO UPDATE TOTAL POINTS TO THE SCORE //
            addBallCounter ++;
        }
        // If the ballcollides with an iblock type
        if (iblock){

            // CHECH FOR DEPH LEVEL WITH AN IF CONDITION //////////////////////////////////////////

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
            // TELL SERVER ABOUT THE COLLISION //
            // TELL SERVER TO ADD 30 POINTS TO SCORE //
            if (depthLvl >= 1){
                json message;
                string strblk = ptrToStr(iblock);
                string strball = ptrToStr(ball);
                message["type"] = "collision";
                message["block"] = strblk;
                message["ball"] = strball;

                string msg = message.dump();
                client->setMessage(msg.c_str());
                depthLvl = 0;
                // LISTEN TO THE SERVER TO UPDATE TOTAL POINTS TO THE SCORE //
                // condition to ckeck if server says to destroy the block
//                if (client->readMessage == "delete"){
//                    delete iblock;
//                }
            }
            addBallCounter ++;
        }
        // If the ballcollides with a deepblock type
        if (deepblock){
            double blockx = deepblock->pos().x();
            double blocky = deepblock->pos().y();

            // If ball collides from bottom
            if (bally > blocky + yPad && velY < 0){
                velY = -1 * (velY + 0.2);
                velX = velX + 0.2;
            }

            // If ball collides from top
            if (blocky > bally + yPad && velY > 0 ){
                velY = -1 * (velY + 0.2);
                velX = velX + 0.2;
            }

            // If ball collides from right
            if (ballx > blockx + xPad && velX < 0){
                velX = -1 * (velX + 0.2);
                velY = velY + 0.2;
            }

            // If ball collides from left
            if (blockx > ballx + xPad && velX > 0){
                velX = -1 * (velX + 0.2);
                velY = velY + 0.2;
            }

            // TELL SERVER ABOUT THE COLLISION //
            // TELL SERVER TO ADD DEPTH LEVEL TO THE BALL //
            json message;
            string strblk = ptrToStr(deepblock);
            string strball = ptrToStr(ball);
            message["type"] = "collision";
            message["block"] = strblk;
            message["ball"] = strball;

            string msg = message.dump();
            client->setMessage(msg.c_str());

            // LISTEN TO THE SERVER TO UPDATE DEPTH LEVEL //

            addBallCounter ++;
        }
    }
}
/**
 * @brief Ball::addBall add a new ball to the playing area
 */
void Ball::addBall()
{
    if (addBallCounter >= 10){
        game->addNewBall();
        ballCounter ++;
        addBallCounter = 0;
    }
}

