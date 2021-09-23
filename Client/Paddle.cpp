#include "Paddle.h"
#include <QBrush>

Paddle::Paddle(QGraphicsItem *parent){
    // draw rect
    setRect(0,0,60,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    brush.setTextureImage(QImage ("/home/user/Escritorio/Repos GitHub/CrazyBreakout/images/5.png"));
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
