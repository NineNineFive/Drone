#include <Arduino.h>
#include <string.h>
#include <WiFi.h>
#include <AsyncUDP.h>

class Drone {
    public:
        Drone(String ssid , String password);
        void connect();
        void sendCommand(String commmand);
        void setIp(String ip);
        bool connected;
        String myIp;
        void loop();
        void commandResponse(String response);
        void ButtonPressed();

        WiFiUDP udpSender;
        const int udpPort = 8889; 
        AsyncUDP udp;

        bool flying = false;

    private:
        String response;
        String ssid;
        String password;
        String droneIp = "192.168.10.1";
};