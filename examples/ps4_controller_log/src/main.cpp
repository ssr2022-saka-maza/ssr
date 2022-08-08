#include <Arduino.h>
#include <ssr/PS4Controller.hpp>

// 追加したい操作(Operation)はssr::PS4Operationクラスを次のようにオーバーライドする
class PS4LogOperation : public ssr::PS4Operation {
public:
    void operate(const ssr::PS4Value & value) override {
        char log[256] = "";
        sprintf(
            log,
            "(%3d %3d) (%3d %3d) [%d %d %d %d] [%d %d %d %d] [%d %d %d] [%d %3d %d] [%d %3d %d]\n",
            value.lstick.x, value.lstick.y, value.rstick.x, value.rstick.y,
            value.up, value.right, value.down, value.left,
            value.triangle, value.circle, value.cross, value.square,
            value.ps, value.share, value.options,
            value.l1, value.l2, value.l3,
            value.r1, value.r2, value.r3
        );
        Serial.print(log);
    }
};

// ssr::PS4Controller_USB ps4Controller(); // USBで有線接続する場合
ssr::PS4Controller_Bluetooth ps4Controller(true);

void setup() {
    Serial.begin(115200);
    if (ps4Controller.begin() == -1) {
        Serial.println("failed to initialize");
        while (1);
    }
    ssr::PS4Operation * logOperation = new PS4LogOperation();
    ps4Controller.addOperation(logOperation);
    // ps4Controller.removeOperation(logOperation); // 追加したOperationを取り消したいとき
    Serial.println("start");
}

void loop() {
    ps4Controller.update(); // この中でOperationが呼び出される
    if (!ps4Controller.connected()) { // 接続確認は別でする必要あり
        Serial.println("not connected");
    }
}
