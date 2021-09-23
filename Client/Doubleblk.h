#ifndef DOUBLEBLK_H
#define DOUBLEBLK_H

#include <QGraphicsRectItem>

class DoubleBlk: public QGraphicsRectItem{
public:
    // Attributes
    int posx = 0;
    int posy = 0;

    // constructors
    DoubleBlk(QGraphicsItem* parent=NULL);
    void setPosition(int x, int y);

};

#endif // DOUBLEBLK_H
