#include <Arduino.h>
#include <Controller/Potentiometer.h>

Potentiometer::Potentiometer(){
}

void Potentiometer::setup(){
    pinMode(potentiometerPin,INPUT);
}

void Potentiometer::loop(){
    int rawValue= analogRead(potentiometerPin);
    potValue = map(rawValue,0,4095, 0,300); 
}

String Potentiometer::print(){
    String text = "potVal: ";
    text += potValue;
    return text;
}

int Potentiometer::getHeightValue(){
    return potValue;
}