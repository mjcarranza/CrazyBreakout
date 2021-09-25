#include "Doubleblk.h"
#include <QBrush>
/**
 * @brief DoubleBlk::DoubleBlk constructor creates a new DoubleBlk with its required attributes
 * @param parent
 */
DoubleBlk::DoubleBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    /**
     * @brief draw a rectangle for the block
     */
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/double.png"));
    setBrush(brush);
}
