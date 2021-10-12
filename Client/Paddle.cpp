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
/**
 * @brief Paddle::reduceSize reduces the size of the paddle.
 */
void Paddle::reduceSize()
{
    int padWidth = rect().width();
    rect().setWidth(padWidth-reduction);
}
/**
 * @brief Paddle::increaseSize add 5 pixels to total paddle size
 */
void Paddle::increaseSize()
{
    padWidth = rect().width();
    rect().setWidth(padWidth+reduction);
}
/**
 * @brief Paddle::mouseMoveEvent sets the paddle position to the current mouse position.
 * @param event
 */
void Paddle::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    // follow mouse's x pos
    double mouseX = mapToScene(event->pos()).x();
    setPos(mouseX-30,y());
}
