#include <Arduino.h>
#include <Controller/Potentiometer.h>

Potentiometer::Potentiometer(){
}

void Potentiometer::setup(){
    pinMode(potentiometerPin,INPUT);
}

void Potentiometer::loop(){
    int potValue= analogRead(potentiometerPin);
    potentiometerValue = map(potValue,0,4095, 0,7000 ); 
}

void Potentiometer::print(){
    Serial.println(potentiometerValue);
}
