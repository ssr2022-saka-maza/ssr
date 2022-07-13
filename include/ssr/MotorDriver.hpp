#pragma once

#ifndef SSR_MOTOR_DRIVER_HPP
#define SSR_MOTOR_DRIVER_HPP

#include <Arduino.h>
#include "ssr/AnalogOut.hpp"
#include "ssr/DigitalOut.hpp"

// このライブラリが使う名前空間
namespace ssr {

// モータードライバを使う MD10C R3(CYTRON TECHNOLOGY)対応
class MotorDriver {
public:
    // PWMピン
    AnalogOut pwm;
    // DIRピン
    DigitalOut dir;

    /**
     * 初期化子
     * @param PinType dirPin DIRにつなげるピンの番号
     * @param PinType pwmPin PWMにつなげるピンの番号
     */
    MotorDriver(PinType dirPin, PinType pwmPin);
    /**
     * 初期設定。全体のsetup()内でこれを呼び出すこと
     * @param int16_t power 初期パワー。デフォルトは0
     */
    void begin(int16_t power = 0);
    /**
     * 出力したパワーを得る
     * @return int16_t 最後に出力したパワー
     */
    int16_t getPower();
    /**
     * パワーを出力する
     * @param int16_t 出力するパワー。範囲は-255~255
     */
    void setPower(int16_t power);
};

}

#endif /* SSR_MOTOR_DRIVER_HPP */
