/**
 * @file MotorDriver.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief モータードライバ1つを扱う型MotorDriver
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_MOTOR_DRIVER_HPP

/**
 * @brief ssr/MotorDriver.hppがインクルードされていることを示すdefine
 */
#define SSR_MOTOR_DRIVER_HPP

#include <Arduino.h>
#include "ssr/AnalogOut.hpp"
#include "ssr/DigitalOut.hpp"
#include "ssr/Output.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief モータードライバを使う型 MD10C R3(CYTRON TECHNOLOGY)対応
     */
    class MotorDriver : public Output<int16_t> {
    public:
        /**
         * @brief PWMに接続するピン
         */
        AnalogOut pwm;
        /**
         * @brief DIRに接続するピン
         */
        DigitalOut dir;

        /**
         * @brief 初期化子
         * @param dirPin ssr::PinType DIRにつなげるピンの番号
         * @param pwmPin ssr::PinType PWMにつなげるピンの番号
         */
        explicit MotorDriver(PinType dirPin, PinType pwmPin);

        /**
         * @brief 初期設定。全体のsetup()内でこれを呼び出すこと
         * @param power int16_t 初期パワー。デフォルトは0
         */
        void begin(int16_t power = 0);

        /**
         * @brief 出力したパワーを得る
         * @return int16_t 最後に出力したパワー
         */
        int16_t getPower();

        /**
         * @brief パワーを出力する
         * @param power int16_t 出力するパワー。範囲は-255~255
         */
        void setPower(int16_t power);

        /**
         * @brief パワーを出力する
         * @param value int16_t 出力するパワー。範囲は-255~255
         */
        void write(int16_t value) override;
    }; // class MotorDriver
} // namespace ssr

#endif /* SSR_MOTOR_DRIVER_HPP */
