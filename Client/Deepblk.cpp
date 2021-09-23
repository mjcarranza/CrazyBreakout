#include "Deepblk.h"
#include <QBrush>

DeepBlk::DeepBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/deep.png"));
    setBrush(brush);
}
