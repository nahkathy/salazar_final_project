#include "lives.h"
#include <QFont>

Lives::Lives(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    lives = 3;
    setPlainText(QString(" Lives: ") + QString::number(lives));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Arial", 16));
}

void Lives::decrease()
{
    lives--;
    setPlainText(QString(" Lives: ") + QString::number(lives));
}

int Lives::get_lives()
{
    return lives;
}
