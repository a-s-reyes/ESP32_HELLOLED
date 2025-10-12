// LEDBlinker.h
#ifndef LEDBLINKER_H
#define LEDBLINKER_H

#include <Arduino.h>

class LEDBlinker {
private:
    int ledPin;
    unsigned long interval;
    unsigned long lastToggleTime;
    bool ledState;

public:
    // Constructor: set pin and blink interval (in milliseconds)
    LEDBlinker(int pin, unsigned long blinkInterval)
        : ledPin(pin), interval(blinkInterval), lastToggleTime(0), ledState(false) {}

    // Initialize the LED pin
    void begin() {
        pinMode(ledPin, OUTPUT);
    }

    // Update LED state based on time
    void update() {
        unsigned long currentMillis = millis();
        if (currentMillis - lastToggleTime >= interval) {
            ledState = !ledState;              // toggle state
            digitalWrite(ledPin, ledState);    // apply to LED
            lastToggleTime = currentMillis;    // reset timer
        }
    }
};

#endif