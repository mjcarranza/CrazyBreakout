#include "Commonblk.h"
#include <QBrush>
/**
 * @brief CommonBlk::CommonBlk constructor creates a new CommonBlk with its required attributes
 * @param parent
 */
CommonBlk::CommonBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    /**
     * @brief draw a rectangle for the block
     */
    setRect(posx,posy,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/common.png"));
    setBrush(brush);
}
/**
 * @brief CommonBlk::setPosition sets the position of the block
 * @param x position
 * @param y position
 */
void CommonBlk::setPosition(int x, int y)
{
    posx = x;
    posy = y;
}
