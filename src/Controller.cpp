#include <Arduino.h>
#include <string.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>
#include <Controller/Drone.h>
#include <Controller/Timer.h>

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
    //drone.connect();
}

void Controller::loop(){
    potentiometer.loop();
    joystick.loop();
    button.loop();
    timer.check();
    joystick.print(); 

    if(timer.check()){
        Serial.println(button.getToggle());
        if(button.getToggle()==true&&drone.flying==false){
            drone.flying = true;
            Serial.println("true");
            drone.sendCommand("takeoff");
        } else if(button.getToggle()==false&&drone.flying==true) {
            drone.flying = false;
            Serial.println("false");
            drone.sendCommand("land");
        }

        Serial.println(potentiometer.getHeightValue());
        if(potentiometer.getHeightValue() > 200){
            String ascend = "up ";
            ascend += 20;
            drone.sendCommand(ascend);
            Serial.println(ascend);
        } else if(potentiometer.getHeightValue() < 100){
            String descend = "down ";
            descend += 20;
            Serial.println(descend);
            drone.sendCommand(descend);
        }

        Serial.println(joystick.getXPosition());
        if(joystick.getXPosition() < 200){
            String left = "left ";
            left += 20;
            drone.sendCommand(left);
        } else if(joystick.getXPosition() < 300){
            String right = "right ";
            right += 20;
            drone.sendCommand(right);
        }

        Serial.println(joystick.getYPosition());
        if(joystick.getYPosition() < 200){
            String back = "back ";
            back += 20;
            drone.sendCommand(back);
        } else if(joystick.getYPosition() < 300){
            String forward = "forward ";
            forward += 20;
            drone.sendCommand(forward);
        }

        Serial.println(button.getFlipButton());
        if(button.getFlipButton()==true){
            Serial.println("pressed");
            drone.sendCommand("flip b");   
        }

        Serial.println(joystick.getStopButton());
        if(joystick.getStopButton()==true){
            Serial.println("pressed");
            drone.sendCommand("stop");   
        }
    }
}