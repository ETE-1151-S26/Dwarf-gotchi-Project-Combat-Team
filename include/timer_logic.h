#ifndef VIEW_TIMER_H
#define VIEW_TIMER_H

#include <Arduino.h>

class Timer{
    private:
        unsigned long startTime;
        unsigned long duration;
        bool active;
public:
    //constructor
    Timer(unsigned long ms);

    void setDuration(unsigned long ms);
    void start();
    void stop();
    void reset();
    bool isReady();

    bool isActive() const; //getter function

};

#endif