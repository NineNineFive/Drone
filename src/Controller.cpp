#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>

Potentiometer potentiometer;

Controller::Controller(){
}

void Controller::setup(){
    potentiometer.setup(); 
}

void Controller::loop(){
    potentiometer.loop();
}
