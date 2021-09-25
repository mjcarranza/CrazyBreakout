#include "Tripleblk.h"
#include <QBrush>
/**
 * @brief TripleBlk::TripleBlk constructor creates a new TripleBlk with its required attributes
 * @param parent
 */
TripleBlk::TripleBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    /**
     * @brief draw a rectangle for the block
     */
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/triple.png"));
    setBrush(brush);
}
