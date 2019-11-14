#include <Arduino.h>
#include <Controller/Potentiometer.h>

Potentiometer::Potentiometer(){
}

void Potentiometer::setup(){
    pinMode(potentiometerPin,INPUT);
}

void Potentiometer::loop(){
    int rawValue= analogRead(potentiometerPin);
    potValue = map(rawValue,0,4095, 20,300); 
}

void Potentiometer::print(){
    Serial.println(potValue);
}

int Potentiometer::getHeightValue(){
    return potValue;
}