#include <Arduino.h>
#include <ssr/all.hpp>

ssr::SyncServo syncServo{};

const int lower = 120, upper = 0;

int mapping(float t) {
    return int(upper * t + lower * (1 - t));
}

void setup() {
    syncServo.attach(23, 25);
    syncServo.mirrored = true;
}

// void loop() {
//     syncServo.write(0);
// }

void loop() {
    float v = millis() / 1000.0;
    int d = mapping((v + 1) / 2.0);
    syncServo.write(d);
    delay(10);
}
