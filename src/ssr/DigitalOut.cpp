#include <Arduino.h>
#include "ssr/DigitalOut.hpp"

ssr::DigitalOut::DigitalOut(PinType pin)
: _value(false), pin(pin) {}

void ssr::DigitalOut::begin(bool value) {
    pinMode(pin, OUTPUT);
    setValue(value);
}

bool ssr::DigitalOut::getValue() const {
    return _value;
}

void ssr::DigitalOut::setValue(bool value) {
    _value = value;
    digitalWrite(pin, _value);
    #ifdef SSR_VERBOSE
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::DigitalOut] set value as %d\n"), _value);
    Serial.print(buffer);
    #endif /* SSR_VERBOSE */
}

void ssr::DigitalOut::write(bool value) {
    setValue(value);
}

void ssr::DigitalOut::toggle() {
    setValue(!_value);
}
