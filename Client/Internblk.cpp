#include "Internblk.h"
#include <QBrush>
/**
 * @brief InternBlk::InternBlk constructor creates a new InternBlk with its required attributes
 * @param parent
 */
InternBlk::InternBlk(QGraphicsItem *parent): QGraphicsRectItem(parent){
    /**
     * @brief draw a rectangle for the block
     */
    setRect(0,0,60,10);
    QBrush brush;
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/internos.png"));
    setBrush(brush);
}
