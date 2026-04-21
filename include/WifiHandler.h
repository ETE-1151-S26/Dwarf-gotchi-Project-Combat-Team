#ifndef WIFI_H
#define WIFI_H

#include <WiFi.h>

void initWifi();
String getIPAddress();
bool isConnected();

#endif
