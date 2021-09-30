#include "gameover.h"
#include "Game.h"
#include "ui_gameover.h"

Game* game;

gameover::gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_pushButton_clicked()
{
    // Close the app
    game = new Game();
    game->close();
    this->close();
}
