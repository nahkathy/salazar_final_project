#ifndef AIRPLANERIGHT_H
#define AIRPLANERIGHT_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

class airplaneright : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    airplaneright();
public slots:
    void move();
};

#endif // AIRPLANERIGHT_H
