#pragma once

#ifndef SSR_DIGITAL_OUT_HPP
#define SSR_DIGITAL_OUT_HPP

#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/Output.hpp"

// このライブラリが使う名前空間
namespace ssr {

// デジタル出力ピンを扱う
class DigitalOut : Output<bool> {
private:
    // 設定した値
    bool _value;
public:
    // 接続ピン
    const PinType pin;

    /**
     * 初期化子
     * @param PinType pin 接続ピン
     * @param bool value 初期値 デフォルトはfalse(LOW)
     */
    DigitalOut(PinType pin);

    /**
     * ピンの初期設定。全体のsetup()でこれを呼び出すこと
     * @param bool value 初期値 デフォルトはfalse(LOW)
     */
    void begin(bool value = false);

    /**
     * 最後に設定した値を返す
     * @return bool 最後に設定した値 HIGHはtrue
     */
    bool getValue();

    /**
     * 値を設定する
     * @param bool value 設定する値。trueでHIGH, falseでLOW
     */
    void setValue(bool value);

    /**
     * 値を出力する
     * @param bool value 出力する値
     */
    void write(bool value) override;

    // 最後に設定した値と逆の値を書き込む
    void toggle();
};

}

#endif /* SSR_DIGITAL_OUT_HPP */
