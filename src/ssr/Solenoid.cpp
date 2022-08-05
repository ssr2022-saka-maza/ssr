#include "ssr/Solenoid.hpp"

ssr::Solenoid::Solenoid(ssr::PinType pin) : _pin(pin) {}

void ssr::Solenoid::begin() {
    _pin.begin();
}

void ssr::Solenoid::update() {
    if (_pin.getValue()) {
        _pin.write(false);
    }
}

void ssr::Solenoid::fire() {
    _pin.write(true);
}
