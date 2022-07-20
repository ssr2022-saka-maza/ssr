#pragma once

#ifndef SSR_DIGITAL_IN_HPP
#define SSR_DIGITAL_IN_HPP

#include <Arduino.h>
#include "ssr/Types.hpp"
#include "ssr/Input.hpp"

// このライブラリが使う名前空間
namespace ssr {

// デジタル入力ピンを扱う
class DigitalIn : Input<bool> {
public:
    // 接続ピン
    const PinType pin;

    /**
     * 初期化子
     * @param PinType pin 接続ピン
     */
    DigitalIn(PinType pin);
    // ピンの初期設定。全体のsetup()内でこれを呼び出すこと
    void begin();
    /**
     * 接続したピンの値を読む
     * @return bool HIGHならtrue
     */
    bool read() override;
};

}

#endif /* SSR_DIGITAL_IN_HPP */
