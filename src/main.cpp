#include <Arduino.h>
#include <Controller.h>
#include <Drone.h>

Controller controller;
Drone drone;

void setup() {
    controller.connect();
}

void loop() {
}