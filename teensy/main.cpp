//
// Created by Adam Keim on 6/28/20.
//
#include "Arduino.h"
const int led = LED_BUILTIN;

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
}

