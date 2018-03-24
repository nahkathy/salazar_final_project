#include "airplaneright.h"
#include "airplaneleft.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <cstdlib>
#include <QList>
#include "game.h"
#include <QDebug>

extern Game* game;

airplaneright::airplaneright()
{
    int rand_y = rand() % (350-100+1); //random number between 100 and 350
    setPos(800, rand_y);
    setPixmap(QPixmap(":/pictures/birdleft.png"));
    //Connect
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void airplaneright::move()
{
    //moves enemy left
    setPos(x() - 5, y());
    //delete enemy when it goes out of scene
    if (x() < 0) {
        qDebug() << "condition met";
        scene()->removeItem(this);
        delete this;
    }

    //if airplanes collide with each other
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(airplaneleft)) {
            if (game->lives->get_lives() > 0)
                game->lives->decrease();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}

