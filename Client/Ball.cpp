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
#include "surprise.h"

using json = nlohmann::json;
Client* client;
gameover* gameOver;
extern Game* game;
Paddle* padd;
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
    this->connecting(); ///////////////////////////////////////////////////////////////////////////
}
/**
 * @brief clientRun independent method tries connecting to the server
 * @return
 */
void *clientRun(void *){
    const char *Ip = "192.168.1.110";
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
    checkBlckCollision();// method to check a paddle collision
    checkBallLeft();// method to check if the ball left the playing area
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
        if (ball){
            if (bally > 650){
                ballCounter--;
                json message;
                string strball = ptrToStr(ball);
                message["type"] = "ballfell";
                message["ball"] = to_string(i);

                string msg = message.dump();
                client->setMessage(msg.c_str());
                gameOver = new gameover();
                gameOver->show();
                ballCounter --;
            }
        }
    }
    if (ballCounter <= 0){
        // Show GameOver window
        gameOver = new gameover();
        gameOver->show();
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
    QList<QGraphicsItem*> surpItems = collidingItems();
    QList<QGraphicsItem*> deepItems = collidingItems();

    // Check for collisions
    for (size_t i = 0, n = cItems.size(); i < n; ++i){

        //Ball* ball = dynamic_cast<Ball*>(bItems[i]);
        CommonBlk *cblock = dynamic_cast<CommonBlk*>(cItems[i]);
        DoubleBlk *dblock = dynamic_cast<DoubleBlk*>(dItems[i]);
        TripleBlk *tblock = dynamic_cast<TripleBlk*>(tItems[i]);
        InternBlk *iblock = dynamic_cast<InternBlk*>(iItems[i]);
        surprise *sblock = dynamic_cast<surprise*>(surpItems[i]);
        DeepBlk *deepblock = dynamic_cast<DeepBlk*>(deepItems[i]);

        double yPad = 9;
        double xPad = 59;
        double ballx = pos().x();
        double bally = pos().y();

        // if the ball collides with a surprise
        if (sblock){
            double blockx = sblock->pos().x();
            double blocky = sblock->pos().y();
            randomNum = game->randomNumber();

            if (bally > blocky + yPad && velY < 0){
                if (randomNum == 1){
                    // increase ball speed
                    velX = velX+0.2;
                    velY = velY+0.2;
                }
            }
            if (blocky > bally + yPad && velY > 0 ){
                if (randomNum == 2){
                    // reduce ball speed
                    velX = velX-0.2;
                    velY = velY-0.2;
                }
            }
            if (ballx > blockx + xPad && velX < 0){
                if (randomNum == 3){
                    // increase paddle size
                    game->increasePadd();
                }
            }
            if (blockx > ballx + xPad && velX > 0){
                if (randomNum == 4){
                    // reduce paddle size
                    game->reducePadd();
                }
            }

            game->scene->removeItem(sblock);
            delete sblock;
        }

        // If the ball collides with a cblock type
        if (cblock){
            double blockx = cblock->pos().x();
            double blocky = cblock->pos().y();

            if (depthLvl <= 0){
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
                // random surprise
                if (game->randomNumber() == 5){
                    game->addSurprise();
                }
                // TELL SERVER ABOUT THE COLLISION //
                json message;
                string blkindx = to_string(i);
                string ballindx = to_string(i);
                message["type"] = "collision";
                message["blkType"] = "common";
                message["block"] = blkindx;
                message["ball"] = ballindx;

                string msg = message.dump();
                client->setMessage(msg.c_str());
                scre = scre+10;
                QString s = QString::number(scre);
                game->setScore(s);
                game->scene->removeItem(cblock);
                delete cblock;
            }
            else{
                depthLvl --;
            }

        }

        // If the ball collides with a dblock type
        if (dblock){
            double blockx = dblock->pos().x();
            double blocky = dblock->pos().y();

            if (depthLvl <= 0){
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
                // random surprise
                if (game->randomNumber() == 5){
                    game->addSurprise();
                }
                // TELL SERVER ABOUT THE COLLISION //
                json message;
                string blkindx = to_string(i);
                string ballindx = to_string(i);
                message["type"] = "collision";
                message["blkType"] = "double";
                message["block"] = blkindx;
                message["ball"] = ballindx;

                string msg = message.dump();
                client->setMessage(msg.c_str());
                scre = scre+15;
                QString s = QString::number(scre);
                game->setScore(s);
                game->scene->removeItem(dblock);
                delete dblock;

            }
            else{
                depthLvl --;
            }
        }

        // If the ball collides with a tblock type
        if (tblock){
            double blockx = tblock->pos().x();
            double blocky = tblock->pos().y();

            if (depthLvl <= 0){
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
                // random surprise
                if (game->randomNumber() == 5){
                    game->addSurprise();
                }
                // TELL SERVER ABOUT THE COLLISION //
                json message;
                string blkindx = to_string(i);
                string ballindx = to_string(i);
                message["type"] = "collision";
                message["blkType"] = "triple";
                message["block"] = blkindx;
                message["ball"] = ballindx;

                string msg = message.dump();
                client->setMessage(msg.c_str());
                scre = scre+20;
                QString s = QString::number(scre);
                game->setScore(s);
                game->scene->removeItem(tblock);
                delete tblock;
            }
            else{
                depthLvl --;
            }
        }

        // If the ball collides with an iblock type
        if (iblock){

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
            // TELL SERVER ABOUT THE COLLISION //
            if (depthLvl >= 1){
                json message;
                string blkindx = to_string(i);
                string ballindx = to_string(i);
                message["type"] = "collision";
                message["blkType"] = "intern";
                message["block"] = blkindx;
                message["ball"] = ballindx;

                string msg = message.dump();
                client->setMessage(msg.c_str());
                scre = scre+30;
                QString s = QString::number(scre);
                game->setScore(s);
                game->scene->removeItem(iblock);
                delete iblock;
                depthLvl = 0;
                QString dep = QString::number(depthLvl);
                game->updatedepth(dep);

            }
        }

        // If the ball collides with a deepblock type
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
            json message;
            string blkindx = to_string(i);
            string ballindx = to_string(i);
            message["type"] = "collision";
            message["blkType"] = "deep";
            message["block"] = blkindx;
            message["ball"] = ballindx;

            string msg = message.dump();
            client->setMessage(msg.c_str());
            depthLvl ++;
            QString s = QString::number(depthLvl);
            game->updatedepth(s);
        }
    }
}
/**
 * @brief Ball::addBall add a new ball to the playing area.
 */
void Ball::addBall()
{
    ballCounter++;
}
/**
 * @brief Ball::deleteBlk deletes a block according to the server.
 */
void Ball::deleteBlk(string type, string index)
{
    size_t x = stoi(index);
    QList<QGraphicsItem*> cItems = collidingItems();
    QList<QGraphicsItem*> dItems = collidingItems();
    QList<QGraphicsItem*> tItems = collidingItems();
    QList<QGraphicsItem*> iItems = collidingItems();

    // delete common block
    if (type == "common"){
        for (size_t i = 0, n = cItems.size(); i < n; ++i){
            if (i == x){
            CommonBlk *cblock = dynamic_cast<CommonBlk*>(cItems[i]);
            game->scene->removeItem(cblock);
            delete cblock;
            }
        }
    }
    // delete double block
    if (type == "double"){
        for (size_t i = 0, n = dItems.size(); i < n; ++i){
            if (i == x){
            DoubleBlk *dblock = dynamic_cast<DoubleBlk*>(dItems[i]);
            game->scene->removeItem(dblock);
            delete dblock;
            }
        }
    }
    // delete triple block
    if (type == "triple"){
        for (size_t i = 0, n = tItems.size(); i < n; ++i){
            if (i == x){
            TripleBlk *tblock = dynamic_cast<TripleBlk*>(tItems[i]);
            game->scene->removeItem(tblock);
            delete tblock;
            }
        }
    }
    // delete intern block
    if (type == "intern"){
        for (size_t i = 0, n = iItems.size(); i < n; ++i){
            if (i == x){
            InternBlk *iblock = dynamic_cast<InternBlk*>(iItems[i]);
            game->scene->removeItem(iblock);
            delete iblock;
            }
        }
    }
}
/**
 * @brief Ball::deleteBall deletes a block from the scene
 * @param index
 */
void Ball::deleteBall(string index)
{
    size_t x = stoi(index);
    QList<QGraphicsItem*> bItems = collidingItems();
    for (size_t i = 0, n = bItems.size(); i < n; ++i){
        if (i == x){
        Ball* ball = dynamic_cast<Ball*>(bItems[i]);
        game->scene->removeItem(ball);
        delete ball;
        }
    }
}
/**
 * @brief Ball::addDepthLevel adds a depth level to a specific ball
 * @param lvl
 */
void Ball::addDepthLevel(QString lvl)
{
    depthLvl ++;
    game->updatedepth(lvl);
}
/**
 * @brief Ball::blkCreated notyfies the server every time a block is created.
 */
void Ball::blkCreated(string blkType)
{
    json message;
    message["type"] = "blkCreated";
    message["block"] = blkType;

    string msg = message.dump();
    client->setMessage(msg.c_str());
}
/**
 * @brief Ball::notify notify server about nickname
 * @param nick
 */
void Ball::notify(QString nick)
{
    string textNick = nick.toUtf8().constData(); // convert nick to string
    json message;
    message["type"] = "nickname";
    message["nickname"] = textNick;

    string msg = message.dump();
    client->setMessage(msg.c_str());
}

