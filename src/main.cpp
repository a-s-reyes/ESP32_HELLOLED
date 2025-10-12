#include <Arduino.h>
#include "LEDBlinker.h"

LEDBlinker led(26, 1000);

void setup() {
    Serial.begin(115200);  
    led.begin();           
    Serial.println("ESP32 NodeMCU Red LED Blinker started!");
}

void loop() {
    led.update();
}