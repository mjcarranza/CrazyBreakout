#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QFrame>

class ball : public QWidget
{
    Q_OBJECT
public:
    explicit ball(QWidget *parent = 0);

private:
    QFrame *fondo;
    int posX = 440;
    int PosY = 490;
};

#endif // BALL_H
