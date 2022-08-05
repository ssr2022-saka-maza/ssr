#pragma once

#ifndef SSR_SOLENOID_HPP
#define SSR_SOLENOID_HPP

#include <Arduino.h>
#include "ssr/DigitalOut.hpp"

// このライブラリが使う名前空間
namespace ssr {

class Solenoid {
private:
    DigitalOut _pin;

public:
    /**
     * 初期化子
     * @param pin ssr::PinType ソレノイドを繋げたピン
     */
    Solenoid(PinType pin);

    /**
     * 初期化 全体のsetup()で呼ぶこと
     */
    void begin();

    /**
     * 状態更新 定期的に呼ぶこと
     */
    void update();

    /**
     * ソレノイドを発火させる
     */
    void fire();
};

} // namespace ssr

#endif /* SSR_SOLENOID_HPP */
