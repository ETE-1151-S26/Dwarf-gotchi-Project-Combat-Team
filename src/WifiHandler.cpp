#include "WiFi.h"
#include "WiFiCredentials.h"
#include "WifiHandler.h"
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include "config.h"

void initWifi(){
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    display.print("Connecting to Wifi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay (500);
        display.print(".");
    }
    display.println("\nConnected to Wifi!");
}

String getIPAddress(){
    return WiFi.localIP().toString();
}

bool isConnected(){
    return WiFi.status() == WL_CONNECTED;
}