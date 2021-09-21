#include "ball.h"

ball::ball(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/ball.png);");
    setGeometry(posX,PosY,20,20);

    fondo = new QFrame(this);
    fondo->setGeometry(this->rect());
}
