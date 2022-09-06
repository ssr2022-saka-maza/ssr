/**
 * @file SyncServo.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief サーボ同期用の型SyncServo
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_SYNC_SERVO_HPP

/**
 * @brief ssr/SyncServo.hppがインクルードされていることを示すdefine
 */
#define SSR_SYNC_SERVO_HPP

#include <Servo.h>
#include "ssr/PinType.hpp"
#include "ssr/Input.hpp"
#include "ssr/Output.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 2つのサーボモーターを同期させる
     * @details 実装の詳細仕様
     * Servo型のオブジェクトservo1, servo2を持つ(private)
     * write(uint8_t v)メソッドではservo1.write(v)が確定
     * if (mirrored) servo2.write(180 - v); else servo2.write(v);
     */
    class SyncServo : public Input<int16_t>, public Output<uint8_t> {
    private:
        /**
         * @brief 同期させるサーボ1つ目
         */
        Servo _servo1;
        /**
         * @brief 同期させるサーボ2つ目
         */
        Servo _servo2;

    public:
        /**
         * @brief サーボの角度を反転させるかどうか(trueで反転)
         */
        bool mirrored;

        /**
         * @brief Construct a new Sync Servo object
         * @param mirror bool サーボの角度を反転させるかどうか(trueで反転)
         */
        SyncServo(bool mirror = false);
        /**
         * @brief Construct a new Sync Servo object
         * @param pin1 ssr::PinType サーボ1のピン
         * @param pin2 ssr::PinType サーボ2のピン
         * @param mirror bool サーボの角度を反転させるかどうか(trueで反転)
         */
        SyncServo(PinType pin1, PinType pin2, bool mirror = false);

        /**
         * @brief サーボにピンを割り当てる
         * @param pin1 ssr::PinType サーボ1に割り当てるピン
         * @param pin2 ssr::PinType サーボ2に割り当てるピン
         * @return uint16_t (servo2.attach(pin2) << 8) | servo1.attach(pin1)
         */
        uint16_t attach(PinType pin1, PinType pin2);

        /**
         * @brief 角度を設定する
         * @param v uint8_t サーボ1に設定する角度 サーボ2の角度はmirroredの値次第で変わる
         */
        virtual void write(uint8_t value) override;

        /**
         * @brief 角度を読む
         * @return int サーボ1の角度 同期できていない場合は-1
         */
        virtual int16_t read() override;
    }; // class SyncServo
} // namespace ssr

#endif /* SSR_SYNC_SERVO_HPP */
