#include <Arduino.h>
#include "LEDBlinker.h"

LEDBlinker led(26, 1000);  // GPIO 26, blink every 1000 ms (1 second)

void setup() {
    led.begin();
}

void loop() {
    led.update();  // non-blocking LED blinking
}