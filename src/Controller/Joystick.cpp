#include <Arduino.h>
#include <Controller/Joystick.h>
#include <string.h>

Joystick::Joystick(){   
}

void Joystick::setup(){
    pinMode(xPin,INPUT);
    pinMode(yPin,INPUT);
    pinMode(swPin,INPUT_PULLUP);
}

void Joystick::loop(){
    joystickValue = (String)"xPos: " + xVal + " yPos: " + yVal + " stopButton: " + swVal;

    if(digitalRead(swPin)==LOW){
        swVal = true;
    } else {
        swVal = false;
    }

    int rawValueX= analogRead(xPin);
    xVal = map(rawValueX,0, 4095, 0,500);

    int rawValueY= analogRead(yPin);
    yVal = map(rawValueY,0, 4095, 0,500); 
}

String Joystick::print(){
    return joystickValue;
}

int Joystick::getXPosition(){
    return xVal;
}

int Joystick::getYPosition(){
    return yVal;
}

boolean Joystick::getStopButton(){
    return swVal;
}