#include "game.h"

Game::Game()
{
    //Create scene and player
    scene = new QGraphicsScene;
    player = new Player;
    player->setRect(0, 0, 100, 100);

    //Add item to scene
    scene->addItem(player);

    //Make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Add airplanes flying
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(5000);

    //Create view to see scene
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    player->setPos(((view->width()/2) - (player->rect().width()/2)), view->height() - player->rect().height());
}

void Game::show()
{
    view->show();
}
