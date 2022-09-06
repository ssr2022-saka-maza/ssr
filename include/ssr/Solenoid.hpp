/**
 * @file Solenoid.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief ソレノイドを扱う型Solenoid
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_SOLENOID_HPP

/**
 * @brief ssr/Solenoid.hppがインクルードされていることを示すdefine
 */
#define SSR_SOLENOID_HPP

#include <Arduino.h>
#include "ssr/DigitalOut.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief ソレノイドを扱う型
     */
    class Solenoid {
    private:
        /**
         * @brief ソレノイドを繋げたピン
         */
        DigitalOut _pin;

    public:
        /**
         * @brief 初期化子
         * @param pin ssr::PinType ソレノイドを繋げたピン
         */
        Solenoid(PinType pin);

        /**
         * @brief 初期化 全体のsetup()で呼ぶこと
         */
        void begin();

        /**
         * @brief 状態更新 定期的に呼ぶこと
         */
        void update();

        /**
         * @brief ソレノイドを発火させる
         */
        void fire();
    }; // class Solenoid
} // namespace ssr

#endif /* SSR_SOLENOID_HPP */
