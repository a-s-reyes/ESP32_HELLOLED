#include <Arduino.h>

const int ledPin = 26; 
int brightness = 0; 
int fadeAmount = 5; 
const int ledChannel = 0; 

void setup() {
  ledcSetup(ledChannel, 5000, 8);

  ledcAttachPin(ledPin, ledChannel);
}

void loop() {
  ledcWrite(ledChannel, brightness);

  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;  
  }

  delay(50); 
}
