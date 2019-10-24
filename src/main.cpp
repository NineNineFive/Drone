#include <Arduino.h>
#include <LED.h>


LED led(27);

void setup() {
    Serial.begin(9600);
    led.setup();
}

void loop() {
  led.loop();
}