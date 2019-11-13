#include <Arduino.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>
#include <Controller/Drone.h>
#include <Controller/Timer.h>
#include <string.h>

Timer timer(1000);

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
    
    
    //delay(500);
    potentiometer.loop();
    joystick.loop();
    button.loop();
    //potentiometer.print();
    //joystick.print();
    //button.print();
    

    timer.check();

    if(timer.check()){
        Serial.println("happened");
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
}
