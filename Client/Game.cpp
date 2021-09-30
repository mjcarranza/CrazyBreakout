#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Commonblk.h"
#include "Doubleblk.h"
#include "Tripleblk.h"
#include "Internblk.h"
#include "Deepblk.h"
/**
 * @brief Game::Game Cosnstructor for the scene. Show all the game`s components
 * @param parent
 */
Game::Game(QWidget *parent): QGraphicsView(parent){
    // initialize scene
    scene = new QGraphicsScene(0,0,795,600);
    scene->setBackgroundBrush (QBrush (QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/fondo.jpg")));
    setScene(scene);

    // Catch mouse motion to set the paddle`s position
    setMouseTracking(true);

    // Add label for "score"
    score = new QLabel();
    score->setText("SCORE:");
    score->setStyleSheet("Background-color: darkblue; color: lightgreen");
    score->setFont(QFont("Tlwg Typo BoldOblique",16));
    score->setGeometry(615,10,85,25);
    scene->addWidget(score);

    // Add label for score in numbers
    scoreNum = new QLabel();
    scoreNum->setText("000000");
    scoreNum->setStyleSheet("Background-color: darkblue; color: lightgreen");
    scoreNum->setFont(QFont("Tlwg Typo BoldOblique",16));
    scoreNum->setGeometry(700,10,80,25);
    scene->addWidget(scoreNum);

    // Add label for "player"
    Player = new QLabel();
    Player->setText("PLAYER:");
    Player->setStyleSheet("Background-color: darkblue; color: lightgreen");
    Player->setFont(QFont("Tlwg Typo BoldOblique",16));
    Player->setGeometry(5,10,90,25);
    scene->addWidget(Player);

    // create a ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);

    // create a paddle
    Paddle* paddle = new Paddle();
    paddle->setPos(150,575);
    scene->addItem(paddle);
    paddle->grabMouse();

    // create the blocks grid
    for (int i=0; i < totalFil; i++) {
        py = 50 + advY;
        totalCol = 12;
        for (int j=0; j<totalCol; j++) {
            random = randomNumber();
            if(random <= 1){
                if(totalCommon != 0){
                    CommonBlk *cblks = new CommonBlk();
                    cblks->setPos(10+advX,py);
                    scene->addItem(cblks);
                    totalCommon--;
                    advX += 65;
                }
            }else if(random == 2){
                if(totaldouble != 0){
                    DoubleBlk *dblks = new DoubleBlk();
                    dblks->setPos(10+advX,py);
                    scene->addItem(dblks);
                    totaldouble--;
                    advX += 65;
                }
            }else if(random == 3){
                if(totalTriple != 0){
                    TripleBlk *tblks = new TripleBlk();
                    tblks->setPos(10+advX,py);
                    scene->addItem(tblks);
                    totalTriple--;
                    advX += 65;
                }
            }else if(random == 4){
                if(totalIntern != 0){
                    InternBlk *iblks = new InternBlk();
                    iblks->setPos(10+advX,py);
                    scene->addItem(iblks);
                    totalIntern--;
                    advX += 65;
                }
            }else if(random == 5){
                if(totalDeep > 0){
                    DeepBlk *deepblks = new DeepBlk();
                    deepblks->setPos(10+advX,py);
                    scene->addItem(deepblks);
                    totalDeep -= 1;
                    advX += 65;
                }
            }
        }
        advX = 0;
        advY += 20;
    }
}
/**
 * @brief Game::randomNumber gets a random number from 1 to 5
 * @return returns a number
 */
int Game::randomNumber()
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return 1 + rand() % (( 5 + 1 ) - 1);
}
/**
 * @brief Game::setNickName writes the nickname entered by the player in the label for nickname.
 * @param n is the nickname as a QString.
 */
void Game::setNickName(QString n)
{
    // Add label for nickname
    nick = n;
    nickName = new QLabel();
    nickName->setText(nick); // default name
    nickName->setStyleSheet("Background-color: darkblue; color: lightgreen");
    nickName->setFont(QFont("Tlwg Typo BoldOblique",16));
    nickName->setGeometry(105,10,200,25);
    scene->addWidget(nickName);

    // send the nickname to the server by ball.cpp
}
/**
 * @brief Game::setScore sets the score to the label for score as a number
 * @param scr score as a QString
 */
void Game::setScore(QString scr)
{
    // scr is the obtained score
    // Do it depending on what the server says from ball.cpp (call this method from ball.cpp
    // with score as a parameter)
    scoreNum->setText(scr); // the qstring is what the server says
    scoreNum->setStyleSheet("Background-color: darkblue; color: lightgreen");
    scoreNum->setFont(QFont("Tlwg Typo BoldOblique",16));
    scoreNum->setGeometry(700,10,80,25);
}

void Game::addNewBall()
{
    // create a ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);
}
