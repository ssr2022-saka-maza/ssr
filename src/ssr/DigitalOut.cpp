#include <Arduino.h>
#include "ssr/DigitalOut.hpp"

ssr::DigitalOut::DigitalOut(PinType pin, bool value)
: _value(value), pin(pin) {}

void ssr::DigitalOut::setup() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, _value);
}

bool ssr::DigitalOut::getValue() {
    return _value;
}

void ssr::DigitalOut::setValue(bool value) {
    _value = value;
    digitalWrite(pin, _value);
}

void ssr::DigitalOut::toggle() {
    setValue(!_value);
}
