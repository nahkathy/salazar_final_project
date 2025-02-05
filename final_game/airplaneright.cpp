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
    int rand_y = 100 + rand() % (275-100+1);
    setPos(800, rand_y);
    setPixmap(QPixmap(":/pictures/marysbird.png"));
    //Connect
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void airplaneright::move()
{
    setPos(x() - 5, y());

    //delete enemy when it goes out of scene
    if (x() < 0) {
        qDebug() << "condition met";
        scene()->removeItem(this);
        delete this;
    }

    //if airplanes collide with each other
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if (game->lives->get_lives() == 0) game->view->close();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(airplaneleft)) {
            if (game->lives->get_lives() > 0)
                game->lives->decrease();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            delete this;
            return;
        }
        if (game->lives->get_lives() == 0) game->view->close();
    }
}

