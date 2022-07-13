#include <Arduino.h>
#include "ssr/AnalogIn.hpp"

ssr::AnalogIn::AnalogIn(ssr::PinType pin) : pin(pin) {}

void ssr::AnalogIn::begin() {
    pinMode(pin, INPUT_PULLUP);
}

uint16_t ssr::AnalogIn::read() {
    return analogRead(pin);
}
