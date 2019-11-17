#include <Arduino.h>
#include <Controller/Timer.h>

long waitingTime;
long timeSinceStart;
long frame = 0;
long iteratorTime;

Timer::Timer(long waitingTime){
    this->waitingTime = waitingTime;
}

long Timer::getTime(){
    return this->waitingTime;
}

boolean Timer::check(){
        this->frame = millis() - this->timeSinceStart;
        this->timeSinceStart = millis();
    if(this->iteratorTime>this->waitingTime){
        this->iteratorTime = 0;
        return true;
    } else {
        this->iteratorTime += this->frame;
        return false;
    }
}
