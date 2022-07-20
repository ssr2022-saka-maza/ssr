#include <Arduino.h>
#include <ssr/MotorDriver.hpp>

ssr::MotorDriver motor(5, 9);

void setup() {
    motor.begin();
    Serial.begin(9600);
}

void loop() {
    char str[256] = "";
    char * ptr = str;
    float t = millis() / 10000.0;
    int16_t power = (int)(256 * sin(t));
    ptr += sprintf(ptr, "%d", power);
    Serial.println(str);
    motor.setPower(power);
    delay(10);
}
