#ifndef AIRPLANERIGHT_H
#define AIRPLANERIGHT_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>

class airplaneright : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    airplaneright();
public slots:
    void move();
};

#endif // AIRPLANERIGHT_H
