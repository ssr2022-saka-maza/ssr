#include <Arduino.h>
#include "ssr/DigitalIn.hpp"

ssr::DigitalIn::DigitalIn(ssr::PinType pin) : pin(pin) {}

void ssr::DigitalIn::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool ssr::DigitalIn::read() {
    #ifdef SSR_VERBOSE
    bool v = digitalRead(pin);
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::DigitalIn] read value %d\n"), v);
    Serial.print(buffer);
    return v;
    #else  /* SSR_VERBOSE */
    return (bool)digitalRead(pin);
    #endif /* SSR_VERBOSE */
}
