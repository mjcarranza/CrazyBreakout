#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Commonblk.h"
#include "Doubleblk.h"
#include "Tripleblk.h"
#include "Internblk.h"
#include "Deepblk.h"

Game::Game(QWidget *parent): QGraphicsView(parent){
    // initialize scene
    // QGraphicsScene::addWidget( QWidget * widget, Qt::WindowFlags wFlags = 0 )
    scene = new QGraphicsScene(0,0,795,600);
    scene->setBackgroundBrush (QBrush (QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/fondo.jpg")));
    setScene(scene);

    // Catch mouse motion to set the paddle`s position
    setMouseTracking(true);

    // Add score label
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

    // Add label for nickname
    nickName = new QLabel();
    nickName->setText("Player1"); // default name
    nickName->setStyleSheet("Background-color: darkblue; color: lightgreen");
    nickName->setFont(QFont("Tlwg Typo BoldOblique",16));
    nickName->setGeometry(105,10,200,25);
    scene->addWidget(nickName);

    // create a ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);

    // create a paddle ;)
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
            if(random == 1){
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
                    DeepBlk *tblks = new DeepBlk();
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
                if(totalDeep != 0){
                    DeepBlk *deepblks = new DeepBlk();
                    deepblks->setPos(10+advX,py);
                    scene->addItem(deepblks);
                    totalDeep--;
                    advX += 65;
                }
            }
        }
        advX = 0;
        advY += 20;
    }
}

int Game::randomNumber() //range : [1, 5]
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return 1 + rand() % (( 5 + 1 ) - 1);
}
