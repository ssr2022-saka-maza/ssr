#include "ssr/Solenoid.hpp"

ssr::Solenoid::Solenoid(ssr::PinType pin) : _pin(pin) {}

void ssr::Solenoid::begin() {
    _pin.begin();
}

void ssr::Solenoid::update() {
    if (_pin.getValue()) {
        _pin.write(false);
        #ifdef SSR_VERBOSE
        char buffer[256] = "";
        snprintf_P(buffer, 200, PSTR("[ssr::Solenoid] chill\n"));
        Serial.print(buffer);
        #endif /* SSR_VERBOSE */
    }
}

void ssr::Solenoid::fire() {
    _pin.write(true);
    #ifdef SSR_VERBOSE
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::Solenoid] fire\n"));
    Serial.print(buffer);
    #endif /* SSR_VERBOSE */
}
