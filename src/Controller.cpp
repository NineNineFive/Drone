#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>
#include <Drone/Drone.h>

Potentiometer potentiometer;
Joystick joystick;
Button button;
Drone drone("LarsAliDrone","ebbevang");


Controller::Controller(){
}

void Controller::setup(){
    potentiometer.setup(); 
    joystick.setup();
    button.setup();    
    drone.connect();
}

void Controller::loop(){
    delay(5000);
    potentiometer.loop();
    joystick.loop();
    button.loop();
    //potentiometer.print();
    //joystick.print();
    //button.print();

    if(button.getToggle()==true){
        drone.sendCommand("Command");
        Serial.println(drone.getCommandResponse());
    } else {
        Serial.println("false");
        //Serial.println("false");
    }

}
