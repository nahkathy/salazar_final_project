#include "player.h"
#include "bullet.h"
#include "airplaneleft.h"
#include "airplaneright.h"
#include <cstdlib>
#include <QGraphicsScene>
#include <QKeyEvent>

void Player::keyPressEvent(QKeyEvent *event)
{
    if (pos().x() > 0) {
        if (event->key() == Qt::Key_Left)
            setPos(x() - 20, y());
    }
    if (pos().x() < 800 - rect().width()) {
        if (event->key() == Qt::Key_Right)
            setPos(x() + 20, y());
    }
    if (event->key() == Qt::Key_Space)
    {
        bullet *my_bullet = new bullet;
        my_bullet->setPos(x(), y());
        //Add bullet to scene
        scene()->addItem(my_bullet);
    }

}

void Player::spawn()
{
    int x = rand() % (2);
    if (x == 0) {
        airplaneleft *airplane = new airplaneleft();
        scene()->addItem(airplane);
    }
    else {
        airplaneright *airplane2 = new airplaneright();
        scene()->addItem(airplane2);
    }
}



