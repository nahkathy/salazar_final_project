#include "bullet.h"
#include "airplaneleft.h"
#include "airplaneright.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QList>
#include "game.h"

extern Game* game; //external global object called game

bullet::bullet() : QObject(), QGraphicsRectItem()
{
    setRect(x()+45, y()-30, 10, 30);
    //Connect
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void bullet::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(airplaneleft) || typeid(*(colliding_items[i])) == typeid(airplaneright)) {
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //moves bullet up
     setPos(x(), y() - 50);
    //delete bullet when it goes above window and out of scene
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
