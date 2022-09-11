/**
 * @file AnalogOut.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief アナログ出力ピンを扱う型AnalogOut
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_ANALOG_OUT_HPP

/**
 * @brief ssr/AnalogOut.hppがインクルードされていることを示すdefine
 */
#define SSR_ANALOG_OUT_HPP

#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/Output.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief アナログ出力ピンを扱う型
     */
    class AnalogOut : public Output<uint16_t> {
    private:
        /**
         * @brief 最後にピンに出力した値
         */
        uint16_t _value;

    public:
        /**
         * @brief 接続するピン
         */
        const PinType pin;

        // デフォルトコンストラクタを禁止
        AnalogOut() = delete;
        // コピーコンストラクタを禁止
        AnalogOut(const AnalogOut &) = delete;
        // コピー代入を禁止
        AnalogOut & operator=(const AnalogOut &) = delete;
        // ムーブコンストラクタを禁止
        AnalogOut(AnalogOut&&) = delete;
        // ムーブ代入を禁止
        AnalogOut & operator=(AnalogOut&&) = delete;
        // デストラクタを定義
        ~AnalogOut() = default;

        /**
         * @brief 初期化子
         * @param pin ssr::PinType 接続ピン
         */
        explicit AnalogOut(PinType pin);

        /**
         * @brief ピンの初期設定。全体のsetup()内でこれを呼び出すこと
         * @param value uint16_t 初期値。デフォルトは0
         */
        void begin(uint16_t value = 0);

        /**
         * @brief 値を出力する
         * @param value uint16_t 出力値。範囲は0~255
         */
        void setValue(uint16_t value);

        /**
         * @brief 出力した値を得る
         * @return 最後に出力した値
         */
        uint16_t getValue();

        /**
         * @brief 値を出力する
         * @param value uint16_t 出力する値
         */
        void write(uint16_t value) override;
    }; // class AnalogOut
} // namespace ssr

#endif /* SSR_ANALOG_OUT_HPP */
