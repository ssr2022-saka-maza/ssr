/**
 * @file DigitalIn.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief デジタル入力ピンを扱う型DigitalIn
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_DIGITAL_IN_HPP

/**
 * @brief ssr/DigitalIn.hppがインクルードされていることを示すdefine
 */
#define SSR_DIGITAL_IN_HPP

#include <Arduino.h>
#include "ssr/PinType.hpp"
#include "ssr/Input.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief デジタル入力ピンを扱う
     */
    class DigitalIn : Input<bool> {
    public:
        /**
         * @brief 接続ピン
         */
        const PinType pin;

        // デフォルトコンストラクタを禁止
        DigitalIn() = delete;
        // コピーコンストラクタを禁止
        DigitalIn(const DigitalIn &) = delete;
        // コピー代入を禁止
        DigitalIn & operator=(const DigitalIn &) = delete;
        // ムーブコンストラクタを禁止
        DigitalIn(DigitalIn&&) = delete;
        // ムーブ代入を禁止
        DigitalIn & operator=(DigitalIn&&) = delete;
        // デストラクタを定義
        ~DigitalIn() = default;

        /**
         * @brief 初期化子
         * @param pin ssr::PinType 接続ピン
         */
        explicit DigitalIn(PinType pin);

        /**
         * @brief ピンの初期設定。全体のsetup()内でこれを呼び出すこと
         */
        void begin();

        /**
         * @brief 接続したピンの値を読む
         * @return bool HIGHならtrue
         */
        bool read() override;
    }; // class DigitalIn
} // namespace ssr

#endif /* SSR_DIGITAL_IN_HPP */
