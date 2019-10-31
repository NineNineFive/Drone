#include <Arduino.h>
#include <Drone.h>

Drone::Drone(){
    this->x = 50;
    this->y = 40;
    this->pinX = 1;
    this->pinY = 2;
}

void Drone::connect(){
    this->x = 2;
}

void Drone::myloop(){
    
}
