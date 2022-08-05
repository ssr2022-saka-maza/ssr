#include <Arduino.h>
#include <ssr/PS4.hpp>

ssr::PS4_Bluetooth ps4(true); // Bluetooth接続の場合 初期ペアリングの時trueを渡す
//ssr::PS4_USB ps4; // USB接続の場合 Bluetoothの行(上の1行)をコメントアウトすること

void setup() {
    Serial.begin(115200);
    if (ps4.begin() == -1) {
        Serial.println("failed to initialize");
        while (1); // Halt
    }
    Serial.println("start");
}

void loop() {
    ps4.update();
    if (!ps4.connected()) {
        Serial.println("not connected");
        return;
    }
    ssr::PS4Value value;
    ps4.read(&value);
    char log[256] = "";
    sprintf(
        log,
        "(%3d %3d) (%3d %3d) [%d %d %d %d] [%d %d %d %d] [%d %d %d] [%d %3d %d] [%d %3d %d]\n",
        value.lstick.x, value.lstick.y,
        value.rstick.x, value.rstick.y,
        value.up,       value.right,  value.down,  value.left,
        value.triangle, value.circle, value.cross, value.square,
        value.ps, value.share, value.options,
        value.l1, value.l2,    value.l3,
        value.r1, value.r2,    value.r3
    );
    Serial.print(log);
}
