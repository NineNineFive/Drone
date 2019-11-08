#include <Arduino.h>
#include <Controller/Potentiometer.h>

Potentiometer::Potentiometer(){
}

void Potentiometer::setup(){
    pinMode(potentiometerPin,INPUT);
}

void Potentiometer::loop(){
    int rawValue= analogRead(potentiometerPin);
    value = map(rawValue,0,4095, 0,7000 ); 
}

void Potentiometer::print(){
    Serial.println(value);
}

int Potentiometer::getValue(){
 return value;
}