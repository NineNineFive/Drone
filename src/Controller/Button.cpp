#include <Arduino.h>
#include <Controller/Button.h>
#include <string.h>

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

String Button::getButtonValue(){
    return buttonValue;
}