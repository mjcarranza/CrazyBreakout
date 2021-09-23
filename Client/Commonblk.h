#ifndef COMMONBLK_H
#define COMMONBLK_H

#include <QGraphicsRectItem>

class CommonBlk: public QGraphicsRectItem{
public:
    // Attributes
    int posx = 0;
    int posy = 0;

    // constructors
    CommonBlk(QGraphicsItem* parent=NULL);
    void setPosition(int x, int y);

};


#endif // COMMONBLK_H
