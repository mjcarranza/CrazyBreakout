#include "Tripleblk.h"
#include <QBrush>

TripleBlk::TripleBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/tripe.png"));
    setBrush(brush);
}
