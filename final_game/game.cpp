#include "game.h"

Game::Game()
{
    //Create scene and player
    scene = new QGraphicsScene;
    player = new Player;
    player->setPixmap(QPixmap(":/pictures/launcher.png"));

    //Add item to scene
    scene->addItem(player);

    //Make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Add score
    score = new Score;
    scene->addItem(score);

    //Add lives
    lives = new Lives;
    lives->setPos(x() + 660, y());
    scene->addItem(lives);

    //Add airplanes flying
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    //Create view to see scene
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    player->setPos(((view->width()/2) - (player->pixmap().width()/2)), view->height() - player->pixmap().height());
    view->setBackgroundBrush(QBrush(QImage(":/pictures/sky.jpg")));
}

void Game::show()
{
    view->show();
}
