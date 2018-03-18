#include "airplaneright.h"
#include "airplaneleft.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <cstdlib>
#include <QList>
#include "game.h"

extern Game* game;

airplaneright::airplaneright()
{
    int rand_y = rand() % (326);
    setPos(800, rand_y);
    setRect(0, 0, 100, 100);
    //Connect
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void airplaneright::move()
{
    //moves enemy left
    setPos(x() - 3, y());
    //delete enemy when it goes above window and out of scene
    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
    }

    //if airplanes collide with each other
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(airplaneleft)) {
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}

