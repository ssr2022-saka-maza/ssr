#include <Arduino.h>
#include "ssr/MotorDriver.hpp"

ssr::MotorDriver::MotorDriver(ssr::PinType dirPin, ssr::PinType pwmPin)
: pwm(pwmPin), dir(dirPin) {}

void ssr::MotorDriver::begin(int16_t power) {
    pwm.begin();
    dir.begin();
    setPower(power);
}

int16_t ssr::MotorDriver::getPower() {
    return (dir.getValue() ? 1 : -1) * pwm.getValue();
}

void ssr::MotorDriver::setPower(int16_t power) {
    dir.setValue(power >= 0);
    pwm.setValue(abs(power));
    #ifdef SSR_VERBOSE
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::MotorDriver] set motor power as %d\n"), power);
    Serial.print(buffer);
    #endif /* SSR_VERBOSE */
}

void ssr::MotorDriver::write(int16_t value) {
    setPower(value);
}
