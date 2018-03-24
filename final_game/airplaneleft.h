#ifndef AIRPLANELEFT_H
#define AIRPLANELEFT_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

class airplaneleft : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    airplaneleft();
public slots:
    void move();
};

#endif // AIRPLANELEFT_H
