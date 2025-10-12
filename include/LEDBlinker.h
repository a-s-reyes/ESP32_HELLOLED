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
    LEDBlinker(int pin, unsigned long blinkInterval)
        : ledPin(pin), interval(blinkInterval), lastToggleTime(0), ledState(false) {}

    void begin() {
        pinMode(ledPin, OUTPUT);
    }

    void update() {
        unsigned long currentMillis = millis();
        if (currentMillis - lastToggleTime >= interval) {
            ledState = !ledState;  
            digitalWrite(ledPin, ledState);
            lastToggleTime = currentMillis;
        }
    }
};

#endif