#include <Arduino.h>
#include <LED.h>
#include <Timer.h>


using namespace std;
    //Timer timer(1);
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