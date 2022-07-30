#pragma once

#ifndef SSR_ANALOG_OUT_HPP
#define SSR_ANALOG_OUT_HPP

#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/Output.hpp"

// このライブラリが使う名前空間
namespace ssr {

// アナログ出力ピンを扱う
class AnalogOut : public Output<uint16_t> {
private:
    // ピンに出力した値
    uint16_t _value;

public:
    // 接続ピン
    const PinType pin;

    /**
     * 初期化子
     * @param PinType pin 接続ピン
     */
    AnalogOut(PinType pin);

    /**
     * ピンの初期設定。全体のsetup()内でこれを呼び出すこと
     * @param uint16_t value 初期値。デフォルトは0
     */
    void begin(uint16_t value = 0);

    /**
     * 値を出力する
     * @param uint16_t value 出力値。範囲は0~255
     */
    void setValue(uint16_t value);

    /**
     * 出力した値を得る
     * @return 最後に出力した値
     */
    uint16_t getValue();

    /**
     * 値を出力する
     * @param uint16_t value 出力する値
     */
    void write(uint16_t value) override;
};

}

#endif /* SSR_ANALOG_OUT_HPP */