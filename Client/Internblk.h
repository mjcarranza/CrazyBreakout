#ifndef INTERNBLK_H
#define INTERNBLK_H

#include <QGraphicsRectItem>

class InternBlk: public QGraphicsRectItem{
public:
    // Attributes
    int posx = 0;
    int posy = 0;

    // constructors
    InternBlk(QGraphicsItem* parent=NULL);
    void setPosition(int x, int y);

};
#endif // INTERNBLK_H
