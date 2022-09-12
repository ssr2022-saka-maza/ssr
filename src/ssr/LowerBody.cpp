#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/LowerBody.hpp"

ssr::LowerBody::LowerBody(
    ssr::PinType dir1, ssr::PinType pwm1,
    ssr::PinType dir2, ssr::PinType pwm2,
    ssr::PinType dir3, ssr::PinType pwm3
) : _dir1(cos(PI / 2), sin(PI / 2)), _dir2(cos(PI * 7 / 6), sin(PI * 7 / 6)), _dir3(cos(PI * 11 / 6), sin(PI * 11 / 6)),
    _motor1(dir1, pwm1), _motor2(dir2, pwm2), _motor3(dir3, pwm3) {}

void ssr::LowerBody::begin(float v_x, float v_y, float v_theta) {
    _motor1.begin();
    _motor2.begin();
    _motor3.begin();
    twist(v_x, v_y, v_theta);
}

void ssr::LowerBody::_setPowers_raw(float v1, float v2, float v3) {
    int16_t p1 = static_cast<int16_t>(v1);
    int16_t p2 = static_cast<int16_t>(v2);
    int16_t p3 = static_cast<int16_t>(v3);
    _motor1.setPower(p1);
    _motor2.setPower(p2);
    _motor3.setPower(p3);
    #ifdef SSR_VERBOSE
    char buffer[256] = "";
    snprintf_P(buffer, 255, PSTR("[ssr::LowerBody] set motor powers as %4d, %4d, %4d\n"), p1, p2, p3);
    Serial.print(buffer);
    #endif /* SSR_VERBOSE */
}

void ssr::LowerBody::_setPowers_normalized(float v1, float v2, float v3) {
    float max_v = max(max(abs(v1), abs(v2)), abs(v3));
    float scale = 255.0 / max_v;
    _setPowers_raw(v1 * scale, v2 * scale, v3 * scale);
}

void ssr::LowerBody::setPowers(float v1, float v2, float v3) {
    float max_v = max(max(abs(v1), abs(v2)), abs(v3));
    if (max_v > 255.0) {
        _setPowers_normalized(v1, v2, v3);
    } else {
        _setPowers_raw(v1, v2, v3);
    }
}

void ssr::LowerBody::twist(float v_x, float v_y, float v_theta) {
    float v1 = _dir1.dot(v_x, v_y) + v_theta;
    float v2 = _dir2.dot(v_x, v_y) + v_theta;
    float v3 = _dir3.dot(v_x, v_y) + v_theta;
    setPowers(v1, v2, v3);
}

void ssr::LowerBody::parallel(float v_x, float v_y) {
    twist(v_x, v_y, 0.0);
}

void ssr::LowerBody::rotate(float v_theta) {
    twist(0.0, 0.0, v_theta);
}
