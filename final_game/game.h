#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QScrollBar>
#include <QTimer>
#include "player.h"


class Game : public QGraphicsView
{
public:
    Game();
    void show();
private:
    QGraphicsScene *scene;
    Player *player;
    QGraphicsView *view;
};

#endif // GAME_H
