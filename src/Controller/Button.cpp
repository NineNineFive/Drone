#include <Arduino.h>
#include <Controller/Button.h>
#include <string.h>

Button::Button(){
}

void Button::setup(){
    pinMode(button1Pin,INPUT);
    pinMode(button2Pin, INPUT); 
    toggle = !digitalRead(button1Pin);
    lastToggle = !digitalRead(button1Pin);
    flipButton = !digitalRead(button2Pin);
}

void Button::loop(){
    if(toggle==lastToggle){
        if(digitalRead(button1Pin)==LOW){
            toggle = !toggle; // On Press
        }
    } else if(toggle != lastToggle){
        if(digitalRead(button1Pin)==LOW){
            lastToggle = !toggle; // set last toggle to the opposite of toggle (we hold finger on it)
        } else {
            lastToggle = toggle; // (we take finger away)
        }
    }

    if(digitalRead(button2Pin)==LOW){
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