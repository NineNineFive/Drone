#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>
#include <Drone/Drone.h>

Potentiometer potentiometer;
Joystick joystick;
Button button;
Drone drone("995","idaernice");


Controller::Controller(){
}

void Controller::setup(){
    potentiometer.setup(); 
    joystick.setup();
    button.setup();    
    drone.connect();
}

void Controller::loop(){
    delay(500);
    potentiometer.loop();
    joystick.loop();
    button.loop();
    potentiometer.print();
    joystick.print();
    button.print();

delay(3000);
    if(button.getValue()){
        drone.sendCommand("command");
    }
    Serial.println(drone.getCommandResponse());
}
