#ifndef TIMER_H
#define TIMER_H
#include <QTimer>

class timer : public QTimer
{
public:
    void start(int &msec);
};

#endif // TIMER_H
