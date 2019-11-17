#include <Arduino.h>
#include <string.h>
#include <Controller.h>
#include <Controller/Potentiometer.h>
#include <Controller/Joystick.h>
#include <Controller/Button.h>
#include <Controller/Drone.h>
#include <Controller/Timer.h>

Timer timer(500);
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
    potentiometer.loop();
    joystick.loop();
    button.loop();

    //TURN DRONE ON AND OFF BUTTON
	if(button.getToggle()==true&&drone.flying==false){
	    drone.flying = true;
	    Serial.println("true");
	    drone.sendCommand("takeoff");
	} else if(button.getToggle()==false&&drone.flying==true) {
	    drone.flying = false;
	    Serial.println("false");
	    drone.sendCommand("land");
	}

    if(timer.check()){
        //CONTROL DRONE HEIGHT
        Serial.println(potentiometer.print());
        if(potentiometer.getHeightValue() > 250){
            String ascend = "up ";
            ascend += 20;
            drone.sendCommand(ascend);
        } else if(potentiometer.getHeightValue() < 50){
            String descend = "down ";
            descend += 20;
            drone.sendCommand(descend);
        }

        //MOVE DRONE IN X AXIS, LEFT AND RIGHT
        Serial.println(joystick.print()); // Prints xValue, yValue and stopButtonValue
        if(joystick.getXPosition() < 150){
            String left = "left ";
            left += 20;
            drone.sendCommand(left);
        } else if(joystick.getXPosition() > 350){
            String right = "right ";
            right += 20;
            drone.sendCommand(right);
        }

        //MOVE DRONE IN Y AXIS, BACK AND FORWARD
        if(joystick.getYPosition() > 350){
            String back = "back ";
            back += 20;
            drone.sendCommand(back);
        } else if(joystick.getYPosition() < 150){
            String forward = "forward ";
            forward += 20;
            drone.sendCommand(forward);
        }

         //EMERGENCY STOP BUTTON
        if(joystick.getStopButton()==true){
            drone.sendCommand("stop");   
        }

        //FLIPBUTTON
        Serial.println(button.getFlipButton());
        if(button.getFlipButton()==true){
            drone.sendCommand("flip b");   
        }
    }
}