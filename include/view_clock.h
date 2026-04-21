#ifndef VIEW_CLOCK_H
#define VIEW_CLOCK_H

#include <Arduino.h>

void initClock();

//hour and minute time as string
String getCurrentTime();

//for updating clock every minute
int getCurrentMinute();

#endif