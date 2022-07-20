#include <Arduino.h>
#include "ssr/AnalogOut.hpp"

ssr::AnalogOut::AnalogOut(ssr::PinType pin)
: _value(0), pin(pin) {}

void ssr::AnalogOut::begin(uint16_t value) {
    pinMode(pin, OUTPUT);
    setValue(value);
}

void ssr::AnalogOut::setValue(uint16_t value) {
    _value = value;
    analogWrite(pin, _value);
}

uint16_t ssr::AnalogOut::getValue() {
    return _value;
}

void ssr::AnalogOut::write(uint16_t value) {
    setValue(value);
}