/**
 * @file AnalogIn.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief アナログ入力ピンを扱う型AnalogIn
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_ANALOG_IN_HPP

/**
 * @brief ssr/AnalogIn.hppがインクルードされていることを示すdefine
 */
#define SSR_ANALOG_IN_HPP

#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/Input.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief アナログ入力ピンを扱う型
     */
    class AnalogIn : public Input<uint16_t> {
    public:
        /**
         * @brief 接続ピン
         */
        const PinType pin;

        // デフォルトコンストラクタを禁止
        AnalogIn() = delete;
        // コピーコンストラクタを禁止
        AnalogIn(const AnalogIn &) = delete;
        // コピー代入を禁止
        AnalogIn & operator=(const AnalogIn &) = delete;
        // ムーブコンストラクタを禁止
        AnalogIn(AnalogIn&&) = delete;
        // ムーブ代入を禁止
        AnalogIn & operator=(AnalogIn&&) = delete;
        // デストラクタを定義
        ~AnalogIn() = default;

        /**
         * @brief 初期化子
         * @param pin ssr::PinType 接続ピン
         */
        explicit AnalogIn(PinType pin);

        /**
         * @brief ピンの初期設定。全体のsetup()内でこれを呼び出すこと
         */
        void begin();

        /**
         * @brief 接続したピンの値を読む
         * @return uint16_t 読んだ値
         */
        uint16_t read() override;
    }; // class AnalogIn
} // namespace ssr

#endif /* SSR_ANALOG_IN_HPP */