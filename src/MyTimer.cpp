#include <Arduino.h>
#include <MyTimer.h>

using namespace std;

long timer;
long timeSinceStart;
long frame;
boolean toggle;

MyTimer::MyTimer(long timer){
    MyTimer::timer = timer;
}

bool loop(){
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
