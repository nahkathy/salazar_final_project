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
#include "score.h"
#include "lives.h"

class Game : public QGraphicsView
{
public:
    Game();
    void show();
    Score *score;
    Lives *lives;
    QGraphicsView *view;
private:
    QGraphicsScene *scene;
    Player *player;
};

#endif // GAME_H
