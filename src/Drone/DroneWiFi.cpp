#include <Arduino.h>
#include <Drone/DroneWiFi.h>
#include <string.h>
#include <WiFi.h>
#include <AsyncUDP.h>

String ssid;
String password;

DroneWiFi::DroneWiFi(String ssid, String password){
    this->ssid = ssid;
    this->password = password; 
}

void DroneWiFi::connect(){
    Serial.println("drone begin");
    //Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(this->ssid.c_str(), this->password.c_str());
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        delay(2000);
        Serial.println("Trying to connect WiFi again");
        connect();
    }
    if(udp.listen(udpPort)) {
        this->myIp = WiFi.localIP().toString();
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
      
        udp.onPacket([this](AsyncUDPPacket packet) -> void {
            // make a string from the data
            String s((char*)packet.data());
            s = s.substring(0, packet.length()); 
            s.trim();
            // send string to method
            this->commandResponse(s);
        });
    }
}

void DroneWiFi::sendCommand(String command) {
    udpSender.beginPacket(this->droneIp.c_str(), udpPort);
    udpSender.printf(command.c_str());
    udpSender.endPacket();    
}

void DroneWiFi::setIp(String ip) {
    this->droneIp = ip;
}
        
void DroneWiFi::commandResponse(String response) {
    Serial.print("got following response: ");
    Serial.println(response.c_str());
    Serial.print("message length: ");
    Serial.println(response.length());
}
/*
void DroneWiFi::ButtonPressed(){
    if (flying == false) {
        this->flying = true;
        Serial.println("takeoff");
        this->sendCommand("takeoff");
    } else {
        Serial.println("land");
        this->sendCommand("land");
        this->flying = false;
    }
}
*/