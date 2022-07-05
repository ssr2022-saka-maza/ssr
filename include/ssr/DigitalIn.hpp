#pragma once

#ifndef SSR_DIGITAL_IN_HPP
#define SSR_DIGITAL_IN_HPP

#include <Arduino.h>
#include "ssr/Types.hpp"

// このライブラリが使う名前空間
namespace ssr {

// デジタル入力ピンを扱う
class DigitalIn {
public:
    // 接続ピン
    const PinType pin;

    /**
     * 初期化子
     * @param PinType pin 接続ピン
     */
    DigitalIn(PinType pin);
    // 全体のsetup()内でこれを呼び出すこと
    void setup();
    /**
     * 接続したピンの値を読む
     * @return bool HIGHならtrue
     */
    bool read();
};

}

#endif /* SSR_DIGITAL_IN_HPP */
