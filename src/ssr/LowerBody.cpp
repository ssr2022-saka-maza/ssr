#include <Arduino.h>
#include "ssr/Types.hpp"
#include "ssr/LowerBody.hpp"

ssr::LowerBody::LowerBody(
    ssr::PinType dir1, ssr::PinType pwm1,
    ssr::PinType dir2, ssr::PinType pwm2,
    ssr::PinType dir3, ssr::PinType pwm3
) : motor1(dir1, pwm1), motor2(dir2, pwm2), motor3(dir3, pwm3) {}

ssr::LowerBody::LowerBody(
    ssr::MotorDriver motor1, ssr::MotorDriver motor2, ssr::MotorDriver motor3
) : motor1(motor1), motor2(motor2), motor3(motor3) {}

void ssr::LowerBody::begin(float v_x, float v_y, float v_theta) {
    motor1.begin();
    motor2.begin();
    motor3.begin();
    twist(v_x, v_y, v_theta);
}

void ssr::LowerBody::twist(float v_x, float v_y, float v_theta) {
    float v1 = cos(PI * 1 / 2) * v_x + sin(PI * 1 / 2) * v_y + v_theta;
    float v2 = cos(PI * 7 / 6) * v_x + sin(PI * 7 / 6) * v_y + v_theta;
    float v3 = cos(PI * 11 / 6) * v_x + sin(PI * 11 / 6) * v_y + v_theta;
    motor1.setPower((int16_t)v1);
    motor2.setPower((int16_t)v2);
    motor3.setPower((int16_t)v3);
}

void ssr::LowerBody::parallel(float v_x, float v_y) {
    twist(v_x, v_y, 0.0);
}

void ssr::LowerBody::rotate(float v_theta) {
    twist(0.0, 0.0, v_theta);
}
