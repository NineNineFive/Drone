#include <Arduino.h>
#include "AsyncUDP.h"
#include "WiFiUDP.h"
#include <string.h>
#include <WiFi.h>

class MyWIFI {
    public:
        MyWIFI();
        AsyncUDP udp;
        WiFiUDP udpSender;
        void sendMessage(String ip, int port, String message);
        void setup();
        void loop();
    private:
        const char * ssid;
        const char * password;
        static const int udpPort;
};