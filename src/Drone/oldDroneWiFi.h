#include <Arduino.h>
#include "AsyncUDP.h"
#include "WiFiUDP.h"
#include <string.h>
#include <WiFi.h>

class oldDroneWiFi {
    public:
        oldDroneWiFi();
        AsyncUDP udp;
        WiFiUDP udpSender;
        void setup();
        void loop();
        const int udpPort = 1995;
    private:
        const char * ssid = "995";
        const char * password = "idaernice";
        //const char * ssid = "flexlab2";
        //const char * password = "flexiwifi";
};