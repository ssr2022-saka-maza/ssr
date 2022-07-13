#include <Arduino.h>
#include "ssr/DigitalIn.hpp"

ssr::DigitalIn::DigitalIn(ssr::PinType pin) : pin(pin) {}

void ssr::DigitalIn::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool ssr::DigitalIn::read() {
    return (bool)digitalRead(pin);
}
