#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include "config.h"
#include "WiFiHandler.h"
#include "view_clock.h"

//gemini suggested fix to my problems (also updated lines in conif.h):
GxEPD2_BW<GxEPD2_213_BN, GxEPD2_213_BN::HEIGHT>
    display(GxEPD2_213_BN(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void updateClock() {
    display.setRotation(1); // Landscape
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.drawRect(0, 0, 250, 122, GxEPD_BLACK);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(2);
        if (isConnected()){
            String currentTime = getCurrentTime();
            display.setCursor(10, 40);
            display.print("Current Time:");
            display.setCursor(10, 60);
            display.print(currentTime);
        }else{
            display.setCursor(10, 40);
            display.print("Wifi Connection Lost!");
        }
    } while (display.nextPage());
}


void setup() {
 Serial.begin(115200);
    
 //Initialize display
    display.init(115200, true, 2, false);
    display.setRotation(DISPLAY_ROTATION);

    //Pins and power
    pinMode(ENC_CLK, INPUT_PULLUP);
    pinMode(ENC_DT,  INPUT_PULLUP);
    pinMode(ENC_SW,  INPUT_PULLUP);
    pinMode(EPD_PWR, OUTPUT);
    digitalWrite(EPD_PWR, HIGH);

    // Initialize WiFi connection
    initWifi();

    delay(100); 
     display.setRotation(1); // Landscape
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.drawRect(0, 0, 250, 122, GxEPD_BLACK);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(2);
        if (isConnected()){
            initClock();
            display.setCursor(10, 40);
            display.print("Connected to Wifi!");
            display.setCursor(10,60);
            display.print("Time Synchronized.");
        }else{
            display.setCursor(10, 40);
            display.print("Wifi Connection Failed!");
        }
    } while (display.nextPage());

    delay(5000);

    updateClock();
}

int lastMinute = -1;
void loop() {
    int currentMinute = getCurrentMinute();
    if(currentMinute != lastMinute && currentMinute != -1) {
        lastMinute = currentMinute;
        updateClock();
    }

    delay (1000);
}