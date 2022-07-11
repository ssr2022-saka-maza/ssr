#include <Arduino.h>
#include "ssr/AnalogOut.hpp"

ssr::AnalogOut::AnalogOut(ssr::PinType pin, uint16_t value)
: _value(value), pin(pin) {}

void ssr::AnalogOut::setup() {
    pinMode(pin, OUTPUT);
    analogWrite(pin, _value);
}

void ssr::AnalogOut::setValue(uint16_t value) {
    _value = value;
    analogWrite(pin, _value);
}

uint16_t ssr::AnalogOut::getValue() {
    return _value;
}