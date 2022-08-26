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
    _servo1.write(value);
    _servo2.write(mirrored ? 180 - value : value);
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
