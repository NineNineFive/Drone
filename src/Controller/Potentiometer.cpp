#include <Arduino.h>
#include <Controller/Potentiometer.h>

int freq;

Potentiometer::Potentiometer(){
    this->POT_PIN = 27;
}

void Potentiometer::setup(){
    pinMode(POT_PIN,INPUT);
}

void Potentiometer::loop(){
    int potValue= analogRead(POT_PIN);
    freq = map(potValue,0,4095, 0,7000 ); 
}

void Potentiometer::print(){
    Serial.println(freq);
}

