#include <Arduino.h>
#include "ssr/AnalogIn.hpp"

ssr::AnalogIn::AnalogIn(ssr::PinType pin) : pin(pin) {}

void ssr::AnalogIn::begin() {
    pinMode(pin, INPUT_PULLUP);
}

uint16_t ssr::AnalogIn::read() {
    #ifdef    SSR_VERBOSE
    int v = analogRead(pin);
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::AnalogIn] read value %d\n"), v);
    Serial.print(buffer);
    return v;
    #else  /* SSR_VERBOSE */
    return analogRead(pin);
    #endif /* SSR_VERBOSE */
}
