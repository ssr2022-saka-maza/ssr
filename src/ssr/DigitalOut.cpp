#include <Arduino.h>
#include "ssr/DigitalOut.hpp"

ssr::DigitalOut::DigitalOut(PinType pin)
: _value(false), pin(pin) {}

void ssr::DigitalOut::begin(bool value) {
    pinMode(pin, OUTPUT);
    setValue(value);
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
