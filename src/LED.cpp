#include <Arduino.h>
#include <LED.h>

using namespace std;
    int pin;

    LED::LED(int pin){
        LED::pin = pin;
    } 

    void LED::setup(){
        pinMode(pin,OUTPUT);
        LED::print();
    }

    void LED::turnOnLED(boolean state) 
    {
        Serial.println("Turn on...");
        digitalWrite(pin, state);
    }

    void LED::loop() 
    {
    }

    void LED::print(){
        Serial.println("Hej...");
    }