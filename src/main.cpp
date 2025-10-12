#include <Arduino.h>

const int ledPin = 26;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Starting LED test on GPIO 26");
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED ON");
  delay(500);
  digitalWrite(ledPin, LOW);
  Serial.println("LED OFF");
  delay(500);
}