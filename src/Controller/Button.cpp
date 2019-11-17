#include <Arduino.h>
#include <Controller/Button.h>
#include <string.h>

Button::Button(){
}

void Button::setup(){
    pinMode(toogleButtonPin,INPUT);
    pinMode(flipButtonPin, INPUT); 
    toggle = !digitalRead(toogleButtonPin);
    lastToggle = !digitalRead(toogleButtonPin);
    flipButton = !digitalRead(flipButtonPin);
}

void Button::loop(){
    if(toggle==lastToggle){
        if(digitalRead(toogleButtonPin)==LOW){
            toggle = !toggle; // On Press
        }
    } else if(toggle != lastToggle){
        if(digitalRead(toogleButtonPin)==LOW){
            lastToggle = !toggle; // set last toggle to the opposite of toggle (we hold finger on it)
        } else {
            lastToggle = toggle; // (we take finger away)
        }
    }

    if(digitalRead(flipButtonPin)==LOW){
        flipButton = true;
    } else {
        flipButton = false;
    }
}

void Button::print(){
    Serial.println(toggle);
    Serial.println(flipButton);
}

boolean Button::getToggle(){
    return toggle;
}

boolean Button::getFlipButton(){
    return flipButton;
}