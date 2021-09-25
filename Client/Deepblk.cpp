#include "Deepblk.h"
#include <QBrush>
/**
 * @brief DeepBlk::DeepBlk constructor creates a new DeepBlk with its required attributes
 * @param parent
 */
DeepBlk::DeepBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    /**
     * @brief draw a rectangle for the block
     */
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/deep.png"));
    setBrush(brush);
}
