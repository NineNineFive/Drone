#include <Arduino.h>
#include <Controller.h>
#include <Drone.h>

Controller controller;
Drone drone;

void setup() {
    Serial.begin(115200);
    controller.setup();
    drone.setup();
}

void loop() {
    controller.loop();
    drone.loop();
}