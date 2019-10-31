#include <Arduino.h>
#include "AsyncUDP.h"
#include "WiFiUDP.h"
#include <string.h>
using namespace std;

class ESPWiFi {
    public:
        const char * ssid;
        const char * password;
        const int udpPort;
        AsyncUDP udp;
        WiFiUDP udpSender;
        void sendMessage(String ip, int port, String message);
        void setup();
        void loop();
    private:
};