#pragma once

#ifndef SSR_ANALOG_IN_HPP
#define SSR_ANALOG_IN_HPP

#include <Arduino.h>
#include "ssr/Types.hpp"
#include "ssr/Input.hpp"

// このライブラリが使う名前空間
namespace ssr {

// アナログ入力ピンを扱う
class AnalogIn : public Input<uint16_t> {
public:
    // 接続ピン
    const PinType pin;

    /**
     * 初期化子
     * @param PinType pin 接続ピン
     */
    AnalogIn(PinType pin);
    // ピンの初期設定。全体のsetup()内でこれを呼び出すこと
    void begin();
    /**
     * 接続したピンの値を読む
     * @return uint16_t 読んだ値
     */
    uint16_t read() override;
};

}

#endif /* SSR_ANALOG_IN_HPP */