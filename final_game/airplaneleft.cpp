#include "airplaneleft.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <cstdlib>
#include "game.h"

extern Game* game;

airplaneleft::airplaneleft()
{
    int rand_y = rand() % (326);
    setPos(0, rand_y);
    setRect(0, 0, 100, 100);
    //Connect
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void airplaneleft::move()
{
    //moves enemy right
    setPos(x() + 3, y());
    //delete enemy when it goes above window and out of scene
    if (pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }
}
