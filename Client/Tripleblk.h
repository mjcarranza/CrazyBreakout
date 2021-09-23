#ifndef TRIPLEBLK_H
#define TRIPLEBLK_H

#include <QGraphicsRectItem>

class TripleBlk: public QGraphicsRectItem{
public:
    // Attributes
    int posx = 0;
    int posy = 0;

    // constructors
    TripleBlk(QGraphicsItem* parent=NULL);
    void setPosition(int x, int y);

};

#endif // TRIPLEBLK_H
