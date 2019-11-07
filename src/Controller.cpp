#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>


Controller::Controller(){
}

void Controller::setup(){
    Potentiometer.setup; 
}

void Controller::loop(){
    Potentiometer.loop;
}
