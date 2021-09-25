#include "mainwindow.h"
#include <QApplication>
/**
 * @brief main method helps create and initialize the game
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show(); // se muestra ventana de inicio

    return a.exec();
}
