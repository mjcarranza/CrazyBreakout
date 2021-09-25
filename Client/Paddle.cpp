#include "Paddle.h"
/**
 * @brief Paddle::Paddle constructor creates a new Paddle with its required attributes
 * @param parent
 */
Paddle::Paddle(QGraphicsItem *parent){
    /**
     * @brief draw a rectangle for the block
     */
    setRect(0,0,60,10);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}

double Paddle::getCenterX(){
    return x()+rect().width()/2;
}

void Paddle::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    // follow mouse's x pos
    double mouseX = mapToScene(event->pos()).x();
    setPos(mouseX-30,y());
}
