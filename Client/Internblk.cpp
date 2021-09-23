#include "Internblk.h"
#include <QBrush>

InternBlk::InternBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/internos.png"));
    setBrush(brush);
}
