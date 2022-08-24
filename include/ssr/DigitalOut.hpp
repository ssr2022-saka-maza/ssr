/**
 * @file DigitalOut.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief デジタル出力ピン型Digitalout
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_DIGITAL_OUT_HPP

/**
 * @brief ssr/DigitalOut.hppがインクルードされていることを示すdefine
 */
#define SSR_DIGITAL_OUT_HPP

#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/Output.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief デジタル出力ピンを扱う型
     */
    class DigitalOut : Output<bool> {
    private:
        /**
         * @brief 最後に出力した値
         */
        bool _value;
    public:
        /**
         * @brief 接続ピン
         */
        const PinType pin;

        /**
         * 初期化子
         * @param pin ssr::PinType 接続ピン
         * @param value bool 初期値 デフォルトはfalse(LOW)
         */
        DigitalOut(PinType pin);

        /**
         * @brief ピンの初期設定。全体のsetup()でこれを呼び出すこと
         * @param value bool 初期値 デフォルトはfalse(LOW)
         */
        void begin(bool value = false);

        /**
         * @brief 最後に設定した値を返す
         * @return bool 最後に設定した値 HIGHはtrue
         */
        bool getValue();

        /**
         * @brief 値を設定する
         * @param value bool 出力する値。trueでHIGH, falseでLOW
         */
        void setValue(bool value);

        /**
         * @brief 値を出力する
         * @param value bool 出力する値
         */
        void write(bool value) override;

        /**
         * @brief 出力を反転させる
         */
        void toggle();
    }; // class DigitalOut
} // namespace ssr

#endif /* SSR_DIGITAL_OUT_HPP */
