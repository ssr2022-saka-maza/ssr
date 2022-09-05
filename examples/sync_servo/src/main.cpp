#include <Arduino.h>
#include <ssr/SyncServo.hpp>

ssr::SyncServo syncServo{};
int d, v;

void setup() {
    syncServo.attach(23, 25);
    syncServo.mirrored = true;
    d = 0;
    v = 1;
}

void loop() {
    d += v;
    if (d <= 0 || 180 <= d) v *= -1;
    syncServo.write(d);
    delay(10);
}
