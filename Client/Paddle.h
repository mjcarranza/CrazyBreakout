#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
/**
 * @brief The Paddle class creates objects of type Paddle
 */
class Paddle: public QGraphicsRectItem{
public:
    // Attributes
    QBrush brush;

    // constructors
    Paddle(QGraphicsItem* parent=NULL);

    // public methods
    double getCenterX();

    // events
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
};

#endif // PADDLE_H
