#include "surprise.h"
#include <QBrush>
/**
 * @brief surprise::surprise constructor creates a new surprise with its required attributes
 * @param parent
 */
surprise::surprise(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    /**
     * @brief draw a rectangle for the surprise block
     */
    setRect(0,0,50,52);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/surprise.png"));
    setBrush(brush);
}
