#include <Arduino.h>
#include "ssr/MotorDriver.hpp"

ssr::MotorDriver::MotorDriver(ssr::PinType dirPin, ssr::PinType pwmPin)
: _pwm(pwmPin), _dir(dirPin) {}

void ssr::MotorDriver::begin(int16_t power) {
    _pwm.begin();
    _dir.begin();
    setPower(power);
}

int16_t ssr::MotorDriver::getPower() const {
    return (_dir.getValue() ? 1 : -1) * _pwm.getValue();
}

void ssr::MotorDriver::setPower(int16_t power) {
    _dir.setValue(power >= 0);
    _pwm.setValue(abs(power));
    #ifdef SSR_VERBOSE
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::MotorDriver] set motor power as %d\n"), power);
    Serial.print(buffer);
    #endif /* SSR_VERBOSE */
}

void ssr::MotorDriver::write(int16_t value) {
    setPower(value);
}
