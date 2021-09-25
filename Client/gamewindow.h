#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>

namespace Ui {
class gamewindow;
}

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = nullptr);
    ~gamewindow();
    void keyPressEvent(QKeyEvent *evt);
    int randomNumber();

signals:

public slots:

private:
    Ui::gamewindow *ui;

    int py;
    int advY = 0;
    int advX = 0;

    int totalCol;
    int totalFil = 15;
    int totalCommon = 50;
    int totaldouble = 50;
    int totalTriple = 50;
    int totalIntern = 50;
    int totalDeep = 50;

    int random; // between 1-5
};

#endif // GAMEWINDOW_H
