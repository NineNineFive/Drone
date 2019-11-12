#include <Arduino.h>
#include <string.h>
#include "WiFi.h"
#include "AsyncUDP.h"

class Drone {
    public:
        Drone(String ssid , String password);
        void connect();
        void sendCommand(String commmand);
        void setIp(String ip);
        bool connected;
        String myIp;
        void loop();
        String getCommandResponse();
    private:
        String response;
        String ssid;
        String password;
        AsyncUDP udp;
        WiFiUDP udpSender;
        const int udpPort = 8889; 
        String droneIp = "192.168.1.146";
        bool flying = false;
};