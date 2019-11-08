#include <Arduino.h>
#include <Controller/Button.h>

Button::Button(){
}

void Button::setup(){
    pinMode(buttonPin,INPUT_PULLUP);
}

void Button::loop(){
    if(digitalRead(buttonPin)==LOW){
        buttonValue = (String)"Pushed";
    } else {
        buttonValue = (String)"Not Pushed";
    }
}

void Button::print(){
    Serial.println(buttonValue);
}