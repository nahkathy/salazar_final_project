#include "airplaneleft.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <cstdlib>
#include "game.h"

extern Game* game;

airplaneleft::airplaneleft()
{
    if (game->lives->get_lives() == 0) game->view->close();
    int rand_y = 100 + rand() % (275 - 100 + 1);
    setPos(0, rand_y);
    setPixmap(QPixmap(":/pictures/marysbird2.png"));
    //Connect
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void airplaneleft::move()
{
    //moves enemy right
    setPos(x() + 5, y());
    //delete enemy when it goes above window and out of scene
    if (pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }
}
