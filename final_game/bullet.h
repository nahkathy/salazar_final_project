#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>

class bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bullet();
public slots:
    void move();
};

#endif // BULLET_H
