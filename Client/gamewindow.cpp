#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "paddle.h"
#include "ball.h"
#include "blocks.h"
#include <iostream>
#include <ctime>
using namespace std;

paddle *padd;
ball *whiteball;
blocks *blks;

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);

    padd = new paddle(this);
    padd->show();
    whiteball = new ball(this);
    whiteball->show();

    for (int i=0; i < totalFil; i++) {
        py = 50 + advY;
        totalCol = 13;
        for (int j=0; j<totalCol; j++) {
            random = randomNumber();
            if(random == 1){
                if(totalCommon != 0){
                    blks = new blocks(this);
                    blks->setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/common.png);");
                    blks->setGeometry(10+advX,py,60,10);
                    totalCommon--;
                    advX += 65;
                }
            }else if(random == 2){
                if(totaldouble != 0){
                    blks = new blocks(this);
                    blks->setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/double.png);");
                    blks->setGeometry(10+advX,py,60,10);
                    totaldouble--;
                    advX += 65;
                }
            }else if(random == 3){
                if(totalTriple != 0){
                    blks = new blocks(this);
                    blks->setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/triple.png);");
                    blks->setGeometry(10+advX,py,60,10);
                    totalTriple--;
                    advX += 65;
                }
            }else if(random == 4){
                if(totalIntern != 0){
                    blks = new blocks(this);
                    blks->setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/internos.png);");
                    blks->setGeometry(10+advX,py,60,10);
                    totalIntern--;
                    advX += 65;
                }
            }else if(random == 5){
                if(totalDeep != 0){
                    blks = new blocks(this);
                    blks->setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/deep.png);");
                    blks->setGeometry(10+advX,py,60,10);
                    totalDeep--;
                    advX += 65;
                }
            }
        }
        advX = 0;
        advY += 20;
    }

//    bool down = true;
//    bool up = false;
//    bool left = false;
//    bool right = false;
//    int bx = 440;
//    int by = 490;

//    // infinite loop for moving the ball during play time
//    while (true){
//        if (down == true){
//            if (by <= 530){
//                ball->move(QPoint(bx,by+20));
//                cout<<"va para abajo"<<endl;
//            }
//            else {
//                cout<<"primer else"<<endl;
//                down=false;
//                up=true;
//            }
//        }
//        if (up == true){
//            if (by >= 0){
//                ball->move(QPoint(bx,by-5));
//                cout<<"va para arriba"<<endl;
//            }
//            else {
//                down=true;
//                up=false;
//            }
//        }
//    }
}

gamewindow::~gamewindow()
{
    delete ui;
}
/**
 * @brief gamewindow::keyPressEvent Detect a key event for the movement of the paddle
 * @param evt Keyboard event
 */
void gamewindow::keyPressEvent(QKeyEvent *evt)
{
    if (evt->key() == Qt::Key_Left){
        if (padd->getX()>=5){
            padd->movePadLeft();
        }
    }
    if (evt->key() == Qt::Key_Right){
        if (padd->getX()<=800){
            padd->movePadRight();
        }
    }
}

int gamewindow::randomNumber() //range : [1, 5]
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return 1 + rand() % (( 5 + 1 ) - 1);
}
