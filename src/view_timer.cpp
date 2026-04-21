#include "view_timer.h"

Timer::Timer(unsigned long ms){
    duration = ms;
    startTime = 0;
    active = false;
}

void Timer::setDuration(unsigned long ms){
    duration = ms;
}

void Timer::start(){
    startTime = millis();
    active = true;
}

void Timer::stop(){
    active = false;
}

void Timer::reset(){
    startTime = millis();
}

bool Timer::isActive() const{
    return active;
}

bool Timer::isReady(){
    if (!active) return false;

    unsigned long currentTime = millis();
    if (currentTime - startTime >= duration){
        startTime = currentTime; //This resets the timer after it is completed
        return true;
    }
    return false;
}
