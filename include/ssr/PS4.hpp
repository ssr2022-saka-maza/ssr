/**
 * @file PS4.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief PS4コントローラーとの接続を管理する
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_PS4_HPP

/**
 * @brief ssr/PS4.hppがインクルードされていることを示すdefine
 */
#define SSR_PS4_HPP

#include <Arduino.h>

#include <PS4Parser.h>

#include <PS4USB.h>
#include <PS4BT.h>
#include <usbhub.h>

#include <SPI.h>

#ifdef dobogusinclude
// https://github.com/stevenvo/arduino-libraries/tree/master/spi4teensy3
// Arduino Megaなので、多分消しても大丈夫
#include <spi4teensy3.h>
#endif /* dobogusinclude */

#include "ssr/Input.hpp"
#include "ssr/PS4Value.hpp"
#include "ssr/PS4Connection.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief PS4コントローラーとの接続を管理する
     * @tparam connection ssr::PS4Connection 接続方式の種類 ::usbまたは::bluetooth
     */
    template<PS4Connection connection> class PS4 : Input<PS4Value *> {};

    /**
     * @brief PS4コントローラーとのUSB接続を管理する
     */
    using PS4_USB = PS4<PS4Connection::usb>;

    /**
     * @brief PS4コントローラーとのBluetooth接続を管理する
     */
    using PS4_Bluetooth = PS4<PS4Connection::bluetooth>;

    /**
     * @brief PS4コントローラーとの接続を管理する型 USB版
     * @tparam PS4Connection::usb USB接続であることを示すenum
     */
    template<> class PS4<PS4Connection::usb> : Input<PS4Value *> {
    private:
        /**
         * @brief USBハブ
         */
        USB _usb;
        /**
         * @brief PS4とのUSB接続
         */
        PS4USB _ps4;

    public:
        /**
         * @brief Construct a new PS4 object
         */
        explicit PS4() : _usb(), _ps4(&_usb) {}

        /**
         * @brief Destroy the PS4 object
         */
        ~PS4() = default;

        PS4(const PS4 &) = delete;
        PS4 & operator = (const PS4 &) = delete;

        /**
         * @brief (USB)を初期化する 必ずsetup()で呼び出して返り値を確認すること
         * @return int 初期化に成功したら0 失敗したら-1
         */
        int begin() {
            return _usb.Init();
        }

        /**
         * @brief 最新の情報に更新する 毎loop()ごとに呼び出すこと
         */
        void update() {
            _usb.Task();
        }

        /**
         * @brief コントローラーに接続できているか確認する
         * @return bool 接続できていたらtrue
         */
        bool connected() {
            return _ps4.connected();
        }

        /**
         * @brief コントローラーのセンサー値を取得する
         * @param[out] output ssr::PS4Value * 取得した値を出力する先
         * @note 引数がnullptrあるいはNULLならば何もしない
         */
        void read(ssr::PS4Value * output) {
            if (output == nullptr || output == NULL) return;
            output->lstick.x = _ps4.getAnalogHat(LeftHatX);
            output->lstick.y = _ps4.getAnalogHat(LeftHatY);
            output->rstick.x = _ps4.getAnalogHat(RightHatX);
            output->rstick.y = _ps4.getAnalogHat(RightHatY);
            output->up = _ps4.getButtonPress(UP);
            output->right = _ps4.getButtonPress(RIGHT);
            output->down = _ps4.getButtonPress(DOWN);
            output->left = _ps4.getButtonPress(LEFT);
            output->triangle = _ps4.getButtonPress(TRIANGLE);
            output->circle = _ps4.getButtonPress(CIRCLE);
            output->cross = _ps4.getButtonPress(CROSS);
            output->square = _ps4.getButtonPress(SQUARE);
            output->l1 = _ps4.getButtonPress(L1);
            output->l2 = _ps4.getAnalogButton(L2);
            output->l3 = _ps4.getButtonPress(L3);
            output->r1 = _ps4.getButtonPress(R1);
            output->r2 = _ps4.getAnalogButton(R2);
            output->r3 = _ps4.getButtonPress(R3);
            output->ps = _ps4.getButtonPress(PS);
            output->share = _ps4.getButtonPress(SHARE);
            output->options = _ps4.getButtonPress(OPTIONS);
            output->finger1Touch = _ps4.isTouching(0);
            if (output->finger1Touch) {
                output->finger1Pos.x = _ps4.getX(0);
                output->finger1Pos.y = _ps4.getY(0);
            } else {
                output->finger1Pos.x = 0;
                output->finger1Pos.y = 0;
            }
            output->finger2Touch = _ps4.isTouching(1);
            if (output->finger2Touch) {
                output->finger2Pos.x = _ps4.getX(1);
                output->finger2Pos.y = _ps4.getY(1);
            } else {
                output->finger2Pos.x = 0;
                output->finger2Pos.y = 0;
            }
            output->pitch = _ps4.getAngle(Pitch);
            output->roll = _ps4.getAngle(Roll);
        }

        /**
         * @brief コントローラーのセンサー値を取得する
         * @return PS4Value * センサー値をまとめた構造体へのポインタ 必ずdeleteすること
         */
        PS4Value * read() override {
            ssr::PS4Value * value = new ssr::PS4Value(
                _ps4.getAnalogHat(LeftHatX),  _ps4.getAnalogHat(LeftHatY),
                _ps4.getAnalogHat(RightHatX), _ps4.getAnalogHat(RightHatY),
                _ps4.getButtonPress(UP),
                _ps4.getButtonPress(RIGHT),
                _ps4.getButtonPress(DOWN),
                _ps4.getButtonPress(LEFT),
                _ps4.getButtonPress(TRIANGLE),
                _ps4.getButtonPress(CIRCLE),
                _ps4.getButtonPress(CROSS),
                _ps4.getButtonPress(SQUARE),
                _ps4.getButtonPress(L1),
                _ps4.getAnalogButton(L2),
                _ps4.getButtonPress(L3),
                _ps4.getButtonPress(R1),
                _ps4.getAnalogButton(R2),
                _ps4.getButtonPress(R3),
                _ps4.getButtonPress(PS),
                _ps4.getButtonPress(SHARE),
                _ps4.getButtonPress(OPTIONS),
                _ps4.isTouching(0),
                0, 0,
                _ps4.isTouching(1),
                0, 0,
                _ps4.getAngle(Pitch),
                _ps4.getAngle(Roll)
            );
            if (value->finger1Touch) {
                value->finger1Pos.x = _ps4.getX(0);
                value->finger1Pos.y = _ps4.getY(0);
            }
            if (value->finger2Touch) {
                value->finger2Pos.x = _ps4.getX(1);
                value->finger2Pos.y = _ps4.getY(1);
            }
            return value;
        } // PS4Value * read()
    }; // template<> class PS4<PS4Connection::usb> : Input<PS4Value *>

    /**
     * @brief PS4コントローラーとの接続を管理する型 Bluetooth版
     * @tparam PS4Connection::bluetooth Bluetooth接続であることを示すenum
     */
    template<> class PS4<PS4Connection::bluetooth> : Input<PS4Value *> {
    private:
        /**
         * @brief USBハブ
         */
        USB _usb;
        /**
         * @brief Bluetoothドングル
         */
        BTD _btd;
        /**
         * @brief PS4とのBluetooth接続
         */
        PS4BT _ps4;

    public:
        /**
         * @brief 初期化子
         * @param pair bool 最初の接続時にtrueを指定する デフォルトはfalse
         */
        explicit PS4(bool pair = false) : _usb(), _btd(&_usb), _ps4(&_btd, pair) {}

        /**
         * @brief Destroy the PS4 object
         */
        ~PS4() = default;

        PS4(const PS4 &) = delete;
        PS4 & operator = (const PS4 &) = delete;

        /**
         * @brief コントローラー(USB)を初期化する 必ずsetup()で呼び出して返り値を確認すること
         * @return int 初期化に成功したら0 失敗したら-1
         */
        int begin() {
            return _usb.Init();
        }

        /**
         * @brief 最新の情報に更新する 毎loop()ごとに呼び出すこと
         */
        void update() {
            _usb.Task();
        }

        /**
         * @brief コントローラーに接続できているか確認する
         * @return bool 接続できていたらtrue
         */
        bool connected() {
            return _ps4.connected();
        }

        /**
         * @brief コントローラーのセンサー値を取得する
         * @param[out] output ssr::PS4Value * 取得した値を出力する先
         * @details 引数がnullptrあるいはNULLならば何もしない
         */
        void read(ssr::PS4Value * output) {
            if (output == nullptr || output == NULL) return;
            output->lstick.x = _ps4.getAnalogHat(LeftHatX);
            output->lstick.y = _ps4.getAnalogHat(LeftHatY);
            output->rstick.x = _ps4.getAnalogHat(RightHatX);
            output->rstick.y = _ps4.getAnalogHat(RightHatY);
            output->up = _ps4.getButtonPress(UP);
            output->right = _ps4.getButtonPress(RIGHT);
            output->down = _ps4.getButtonPress(DOWN);
            output->left = _ps4.getButtonPress(LEFT);
            output->triangle = _ps4.getButtonPress(TRIANGLE);
            output->circle = _ps4.getButtonPress(CIRCLE);
            output->cross = _ps4.getButtonPress(CROSS);
            output->square = _ps4.getButtonPress(SQUARE);
            output->l1 = _ps4.getButtonPress(L1);
            output->l2 = _ps4.getAnalogButton(L2);
            output->l3 = _ps4.getButtonPress(L3);
            output->r1 = _ps4.getButtonPress(R1);
            output->r2 = _ps4.getAnalogButton(R2);
            output->r3 = _ps4.getButtonPress(R3);
            output->ps = _ps4.getButtonPress(PS);
            output->share = _ps4.getButtonPress(SHARE);
            output->options = _ps4.getButtonPress(OPTIONS);
            output->finger1Touch = _ps4.isTouching(0);
            if (output->finger1Touch) {
                output->finger1Pos.x = _ps4.getX(0);
                output->finger1Pos.y = _ps4.getY(0);
            } else {
                output->finger1Pos.x = 0;
                output->finger1Pos.y = 0;
            }
            output->finger2Touch = _ps4.isTouching(1);
            if (output->finger2Touch) {
                output->finger2Pos.x = _ps4.getX(1);
                output->finger2Pos.y = _ps4.getY(1);
            } else {
                output->finger2Pos.x = 0;
                output->finger2Pos.y = 0;
            }
            output->pitch = _ps4.getAngle(Pitch);
            output->roll = _ps4.getAngle(Roll);
        } // void read(ssr::PS4Value * output)

        /**
         * @brief コントローラーのセンサー値を取得する
         * @return PS4Value * センサー値をまとめた構造体へのポインタ 必ずdeleteすること
         */
        PS4Value * read() override {
            ssr::PS4Value * value = new ssr::PS4Value(
                _ps4.getAnalogHat(LeftHatX),  _ps4.getAnalogHat(LeftHatY),
                _ps4.getAnalogHat(RightHatX), _ps4.getAnalogHat(RightHatY),
                _ps4.getButtonPress(UP),
                _ps4.getButtonPress(RIGHT),
                _ps4.getButtonPress(DOWN),
                _ps4.getButtonPress(LEFT),
                _ps4.getButtonPress(TRIANGLE),
                _ps4.getButtonPress(CIRCLE),
                _ps4.getButtonPress(CROSS),
                _ps4.getButtonPress(SQUARE),
                _ps4.getButtonPress(L1),
                _ps4.getAnalogButton(L2),
                _ps4.getButtonPress(L3),
                _ps4.getButtonPress(R1),
                _ps4.getAnalogButton(R2),
                _ps4.getButtonPress(R3),
                _ps4.getButtonPress(PS),
                _ps4.getButtonPress(SHARE),
                _ps4.getButtonPress(OPTIONS),
                _ps4.isTouching(0),
                0, 0,
                _ps4.isTouching(1),
                0, 0,
                _ps4.getAngle(Pitch),
                _ps4.getAngle(Roll)
            );
            if (value->finger1Touch) {
                value->finger1Pos.x = _ps4.getX(0);
                value->finger1Pos.y = _ps4.getY(0);
            }
            if (value->finger2Touch) {
                value->finger2Pos.x = _ps4.getX(1);
                value->finger2Pos.y = _ps4.getY(1);
            }
            return value;
        } // PS4Value * read()
    }; // class PS4<PS4Connection::bluetooth> : Input<PS4Value *>
} // namespace ssr

#endif /* SSR_PS4_HPP */
