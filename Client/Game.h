#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QWidget>

class Game: public QGraphicsView{
public:

    // Attributes
    QGraphicsScene* scene;

    QLabel *score;
    QLabel *scoreNum;
    QLabel *Player;
    QLabel *nickName;

    int py;
    int advY = 0;
    int advX = 0;
    int random; // between 1-5

    int totalCol;
    int totalFil = 15;
    int totalCommon = 50;
    int totaldouble = 50;
    int totalTriple = 50;
    int totalIntern = 50;
    int totalDeep = 50;

    // constructors
    Game(QWidget* parent=NULL);

    // public methods
    int randomNumber();
};

#endif // GAME_H
