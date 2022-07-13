#include <Arduino.h>
#include <ssr/DigitalOut.hpp>

ssr::DigitalOut outPin(LED_BUILTIN);

void setup() {
    outPin.begin();
}

void loop() {
    outPin.toggle();
    delay(1000);
}

