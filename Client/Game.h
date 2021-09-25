#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QWidget>
/**
 * @brief The Game class runs the game interface and manages all the game process
 */
class Game: public QGraphicsView{
private:
    // Private Attributes
    int totalCol;
    int totalFil = 10;
    int totalCommon = 60;
    int totaldouble = 60;
    int totalTriple = 60;
    int totalIntern = 60;
    int totalDeep = 20;

    int py;
    int advY = 0;
    int advX = 0;
    int random;

public:
    // Public Attributes
    QGraphicsScene* scene;
    QLabel *score;
    QLabel *scoreNum;
    QLabel *Player;
    QLabel *nickName;

    // Constructor
    Game(QWidget* parent=NULL);

    // Methods
    int randomNumber();
};

#endif // GAME_H
