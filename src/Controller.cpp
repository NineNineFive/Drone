#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>

Potentiometer potentiometer;
Joystick joystick;
Button button;

Controller::Controller(){
}

void Controller::setup(){
    potentiometer.setup(); 
    joystick.setup();
    button.setup();    
}

void Controller::loop(){
    delay(500);3
    potentiometer.loop();
    joystick.loop();
    button.loop();
    potentiometer.print();
    joystick.print();
    button.print();
}
