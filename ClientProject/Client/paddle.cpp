#include "paddle.h"

paddle::paddle(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-image: url(/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/paddle.png);");
    setGeometry(posX,PosY,60,10);

    fondo = new QFrame(this);
    fondo->setGeometry(this->rect());
}

void paddle::movePadLeft()
{
    this->move(QPoint(this->x()-15,PosY));

    // enviar al server que se movio a la izquierda
}

void paddle::movePadRight()
{
    this->move(QPoint(this->x()+15,PosY));

    // enviar al server que se movio a la derecha
}

int paddle::getX()
{
    return this->x();
}
