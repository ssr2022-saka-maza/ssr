#include "ssr/SyncServo.hpp"

ssr::SyncServo::SyncServo(bool mirror)
: _servo1(), _servo2(), mirrored(mirror) {}

ssr::SyncServo::SyncServo(ssr::PinType pin1, ssr::PinType pin2, bool mirror)
: _servo1(), _servo2(), mirrored(mirror) {
    attach(pin1, pin2);
}

uint16_t ssr::SyncServo::attach(ssr::PinType pin1, ssr::PinType pin2) {
    return (_servo2.attach(pin2) << 8) | _servo1.attach(pin1);
}

void ssr::SyncServo::write(uint8_t value) {
    #ifdef SSR_VERBOSE
    uint8_t value2 = mirrored ? 180 - value : value;
    _servo1.write(value);
    _servo2.write(value2);
    char buffer[256] = "";
    snprintf_P(buffer, 200, PSTR("[ssr::SyncServo] wrote %d to servo1, %d to servo2"), value, value2);
    #else
    _servo1.write(value);
    _servo2.write(mirrored ? 180 - value : value);
    #endif /* SSR_VERBOSE */
}

int16_t ssr::SyncServo::read() {
    int v1 = _servo1.read(), v2 = _servo2.read();
    bool valid = false;
    if (mirrored) {
        valid = v1 + v2 == 180;
    } else {
        valid = v1 == v2;
    }
    if (!valid) return -1;
    return v1;
}
