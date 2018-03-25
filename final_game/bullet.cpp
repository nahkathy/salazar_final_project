#include "bullet.h"
#include "airplaneleft.h"
#include "airplaneright.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QList>
#include <QMediaPlayer>
#include "game.h"

extern Game* game; //external global object called game

bullet::bullet() : QObject(), QGraphicsPixmapItem()
{
    QMediaPlayer * bulletsound = new QMediaPlayer;
    bulletsound->setMedia(QUrl("qrc:/sounds/gunshot.mp3"));
    bulletsound->setVolume(10);
    bulletsound->setPlaybackRate(2.5);
    if (bulletsound->state() == QMediaPlayer::PlayingState)
        bulletsound->setPosition(0);
    else if (bulletsound->state() == QMediaPlayer::StoppedState)
        bulletsound->play();

    QPixmap my_bullet(":/pictures/stone.png");
    my_bullet.scaled(10, 30);
    setPixmap(my_bullet);
    //setRect(x()+45, y()-30, 10, 30);
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
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //moves bullet up
     setPos(x(), y() - 50);
    //delete bullet when it goes above window and out of scene
    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
