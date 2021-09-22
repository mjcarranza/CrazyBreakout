#include "blocks.h"

blocks::blocks(QWidget *parent) : QWidget(parent)
{
    setGeometry(posX,PosY,60,10);

    fondo = new QFrame(this);
    fondo->setGeometry(this->rect());
}
