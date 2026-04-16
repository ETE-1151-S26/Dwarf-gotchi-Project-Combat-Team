#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include "config.h"


void setup() {
 Serial.begin(115200);
    
    display.init(115200, true, 2, false);
    display.setRotation(DISPLAY_ROTATION);

    pinMode(ENC_CLK, INPUT_PULLUP);
    pinMode(ENC_DT,  INPUT_PULLUP);
    pinMode(ENC_SW,  INPUT_PULLUP);
    pinMode(EPD_PWR, OUTPUT);
    digitalWrite(EPD_PWR, HIGH);

    delay(100); 
     display.setRotation(1); // Landscape
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.drawRect(0, 0, 250, 122, GxEPD_BLACK);
        display.setCursor(50, 60);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(3);
        display.print("I love you!");
    } while (display.nextPage());
}