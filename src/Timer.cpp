#include <Arduino.h>
#include <Timer.h>

using namespace std;

long timer;
long timeSinceStart;
long frame;
boolean toggle;

Timer::Timer(long timer){
    Timer::timer = timer;
}

boolean loop(){


    frame = millis() - timeSinceStart;
    timeSinceStart = millis();

    if(timer > 1000){
        toggle = !toggle;
        //i++;
        timer = 0;    
        //Serial.println(i);
    } else {
        timer += frame;
    }

    if(toggle){
        return true;
    } else {
        return false;    
    }

}