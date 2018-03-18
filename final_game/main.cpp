#include <QApplication>
#include "game.h"

Game *game; //make global so you can use in any class

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();

    return a.exec();
}
