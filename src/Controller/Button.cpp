#include <Arduino.h>
#include <Controller/Button.h>
#include <string.h>

Button::Button(){
}

void Button::setup(){
    pinMode(buttonPin,INPUT);
}

void Button::loop(){
    if(digitalRead(buttonPin)==HIGH){
        value = (String)"Pushed";
        toggle = !toggle;
    } else {
        value = (String)"Not Pushed";
    }
}

void Button::print(){
    Serial.println(value);
}

String Button::getValue(){
    return value;
}

boolean Button::getToggle(){
    return toggle;
}