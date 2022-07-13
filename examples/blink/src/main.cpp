#include <Arduino.h>
#include <ssr/DigitalOut.hpp>

ssr::DigitalOut outPin(LED_BUILTIN);

void setup() {
    outPin.setup();
}

void loop() {
    outPin.toggle();
    delay(1000);
}

