#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>
#include <QFrame>

class paddle : public QWidget
{
    Q_OBJECT
public:
    explicit paddle(QWidget *parent = 0);
    void movePadLeft();
    void movePadRight();
    int getX();
private:
    QFrame *fondo;
    int posX = 420;
    int PosY = 510;
};

#endif // PADDLE_H
