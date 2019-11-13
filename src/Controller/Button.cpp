#include <Arduino.h>
#include <Controller/Button.h>
#include <string.h>

Button::Button(){
}

void Button::setup(){
    pinMode(buttonPin,INPUT);
    toggle = !digitalRead(buttonPin);
    lastToggle = !digitalRead(buttonPin);
}

void Button::loop(){
    if(toggle==lastToggle){
        if(digitalRead(buttonPin)==LOW){
            toggle = !toggle; // On Press
        }
    } else if(toggle != lastToggle){
        if(digitalRead(buttonPin)==LOW){
            lastToggle = !toggle; // set last toggle to the opposite of toggle (we hold finger on it)
        } else {
            lastToggle = toggle; // (we take finger away)
        }
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