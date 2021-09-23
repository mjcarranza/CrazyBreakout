#include "Commonblk.h"
#include <QBrush>

CommonBlk::CommonBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(posx,posy,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/common.png"));
    setBrush(brush);
}

void CommonBlk::setPosition(int x, int y)
{
    posx = x;
    posy = y;
}
