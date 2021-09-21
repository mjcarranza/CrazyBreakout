#ifndef BLOCKS_H
#define BLOCKS_H

#include <QWidget>
#include <QFrame>

class blocks : public QWidget
{
    Q_OBJECT
public:
    explicit blocks(QWidget *parent = 0);

private:
    QFrame *fondo;
    int posX = 440;
    int PosY = 490;
};

#endif // BLOCKS_H
