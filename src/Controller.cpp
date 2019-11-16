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

    if(timer.check()){
        drone.sendCommand("battery?");
                     
        

        //CONTROL DRONE HEIGHT
        Serial.println(potentiometer.print());
        if(potentiometer.getHeightValue() > 250){
            String ascend = "up ";
            ascend += 50;
            drone.sendCommand(ascend);
        } else if(potentiometer.getHeightValue() < 50){
            String descend = "down ";
            descend += 50;
            drone.sendCommand(descend);
        }

        //MOVE DRONE IN X AXIS, LEFT AND RIGHT
        Serial.println(joystick.print());
        if(joystick.getXPosition() < 150){
            String left = "left ";
            left += 50;
            drone.sendCommand(left);
        } else if(joystick.getXPosition() > 350){
            String right = "right ";
            right += 50;
            drone.sendCommand(right);
        }

        //TURBO SPEED DRONE IN X AXIS, LEFT AND RIGHT
        if(joystick.getXPosition() < 10){
            String turboLeft = "speed ";
            turboLeft += 80;
            drone.sendCommand(turboLeft);
        } else if(joystick.getXPosition() > 490){
            String turboRight = "speed ";
            turboRight += 80;
            drone.sendCommand(turboRight);
        }

        //MOVE DRONE IN Y AXIS, LEFT AND RIGHT
        if(joystick.getYPosition() > 350){
            String back = "back ";
            back += 50;
            drone.sendCommand(back);
        } else if(joystick.getYPosition() < 150){
            String forward = "forward ";
            forward += 50;
            drone.sendCommand(forward);
        }

        //TURBO SPEED DRONE IN Y AXIS, LEFT AND RIGHT
        if(joystick.getYPosition() > 490){
            String turboBack = "speed ";
            turboBack += 80;
            drone.sendCommand(turboBack);
        } else if(joystick.getYPosition() < 10){
            String turboForward = "speed ";
            turboForward += 80;
            drone.sendCommand(turboForward);
        }

         //EMERGENCY STOP BUTTON
        if(joystick.getStopButton()==true){
            drone.sendCommand("stop");   
        }

        //FLIPBUTTON
        Serial.println(button.getFlipButton());
        if(button.getFlipButton()==true){
            Serial.print(" flipButton pressed");
            drone.sendCommand("flip b");   
        }
    }
}