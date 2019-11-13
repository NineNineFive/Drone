#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>
#include <Drone/Drone.h>
#include <string.h>

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
    //drone.setIp ("192.168.10.1");
}

void Controller::loop(){
    delay(500);
    potentiometer.loop();
    joystick.loop();
    button.loop();
    //potentiometer.print();
    //joystick.print();
    //button.print();

    if(button.getToggle()==true&&drone.flying==false){
        drone.flying = true;
        Serial.println("true");
        drone.sendCommand("takeoff");
    } else if(button.getToggle()==false&&drone.flying==true) {
        drone.flying = false;
        Serial.println("false");
        drone.sendCommand("land");
    }

}
