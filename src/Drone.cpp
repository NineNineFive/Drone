#include <Arduino.h>
#include <Drone.h>
#include <Drone/DroneWiFi.h>

DroneWiFi wifi("995","idaernice");

Drone::Drone(){
}

void Drone::setup(){
    wifi.connect();
}

void Drone::loop(){
    //wifi.loop();
}
