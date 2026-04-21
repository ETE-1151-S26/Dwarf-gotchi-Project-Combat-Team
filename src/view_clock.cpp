#include "view_clock.h"
#include <time.h>
#include "config.h"

//Configure for time zone
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -25200; //UTC-7 (ultiply 7 * 3600 seconds (1hour))
const int daylightOffset_sec = 0;

void initClock() {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        display.println("Failed to obtain time from NTP");
        return;
    }
}

String getCurrentTime(){
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        return "00:00";
    }

    char timeStringBuff[20]; //temporary buffer for storing time
    strftime(timeStringBuff, sizeof(timeStringBuff), "%H:%M %p", &timeinfo); //%H: hour, %M: minute, %p: AM or PM
    return String(timeStringBuff);

}

int getCurrentMinute(){
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        return -1;
    }
    return timeinfo.tm_min;
}
    