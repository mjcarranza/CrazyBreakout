#ifndef COMMONBLK_H
#define COMMONBLK_H

#include <QGraphicsRectItem>
/**
 * @brief The CommonBlk class creates objects of type CommonBlk
 */
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
