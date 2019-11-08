#include <Arduino.h>
#include <Drone.h>
#include <Drone/DroneWiFi.h>

DroneWiFi wifi;

Drone::Drone(){
}

void Drone::setup(){
    wifi.setup();
}

void Drone::loop(){
    wifi.loop();
}
