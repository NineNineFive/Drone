#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>

Potentiometer potentiometer;
Joystick joystick;

Controller::Controller(){
}

void Controller::setup(){
    potentiometer.setup(); 
    joystick.setup();
}

void Controller::loop(){
    potentiometer.loop();
    joystick.loop();
    joystick.print();
    //potentiometer.print();
}
