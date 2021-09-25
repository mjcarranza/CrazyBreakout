#ifndef DEEPBLK_H
#define DEEPBLK_H

#include <QGraphicsRectItem>
/**
 * @brief The DeepBlk class creates objects of type DeepBlk
 */
class DeepBlk: public QGraphicsRectItem{
public:
    // Attributes
    int posx = 0;
    int posy = 0;

    // constructors
    DeepBlk(QGraphicsItem* parent=NULL);
    void setPosition(int x, int y);

};

#endif // DEEPBLK_H
