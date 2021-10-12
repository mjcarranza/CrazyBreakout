#include "surprise.h"
#include <QBrush>

surprise::surprise(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    /**
     * @brief draw a rectangle for the block
     */
    setRect(0,0,50,52);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/surprise.png"));
    setBrush(brush);
}
