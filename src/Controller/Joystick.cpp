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
    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    swVal = digitalRead(swPin);
    joystickValue = (String)"x:" + xVal + " y:" + yVal + " sw:" + swVal;
}

void Joystick::print(){
    Serial.println(joystickValue);
}

int Joystick::getX(){
    return xVal;
}

int Joystick::getY(){
    return yVal;
}

int Joystick::getSW(){
    return swVal;
}