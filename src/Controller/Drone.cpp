#include <Arduino.h>
#include <Controller/Drone.h>
#include <string.h>
#include <WiFi.h>
#include <AsyncUDP.h>

String ssid;
String password;

String response = "";

Drone::Drone(String ssid, String password){
    this->ssid = ssid;
    this->password = password; 
}

void Drone::connect(){
    if(on){
    Serial.println("drone begin");
    WiFi.mode(WIFI_STA);
    WiFi.begin(this->ssid.c_str(), this->password.c_str());
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    
    if(udp.listen(udpPort)) {
        this->myIp = WiFi.localIP().toString();
        Serial.print("UDP Listening on IP: ");
        //Serial.println("localIP: "+WiFi.localIP());
        Serial.println(WiFi.localIP());
      
        Serial.println("onPacket");
        
        udp.onPacket(
            [this](AsyncUDPPacket packet) -> void
            {
                // make a string from the data
                String s((char*)packet.data());
                s = s.substring(0, packet.length()); 
                s.trim();
                // send string to method
                this->commandResponse(s);
            }
        );
        this->sendCommand("command");
    }
    }
}

void Drone::sendCommand(String command) {
    if(on){
    udpSender.beginPacket(this->droneIp.c_str(), udpPort);
    udpSender.printf(command.c_str());
    udpSender.endPacket();    
    }
}

void Drone::setIp(String ip) {
    this->droneIp = ip;
}
        
void Drone::commandResponse(String response) {
    Serial.print("got following response: ");
    Serial.println(response.c_str());
    Serial.print("message length: ");
    Serial.println(response.length());
}