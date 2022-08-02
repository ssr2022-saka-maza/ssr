#pragma once

#ifndef SSR_PS4_HPP
#define SSR_PS4_HPP

#include <Arduino.h>

#include <PS4Parser.h>
//USB Usb;

#include <PS4USB.h>
#include <PS4BT.h>
#include <usbhub.h>

#include <SPI.h>

#ifdef dobogusinclude
// https://github.com/stevenvo/arduino-libraries/tree/master/spi4teensy3
// Arduino Megaなので、多分消しても大丈夫
#include <spi4teensy3.h>
#endif /* dobogusinclude */

//BTD Btd(&Usb);

// 接続したことがない場合
// コントローラー側はPSとShareボタンを長押しする
//PS4BT PS4(&Btd, PAIR);

// 接続したことがある場合
//PS4BT PS4(&Btd);

#include "ssr/Input.hpp"
#include "ssr/PS4Value.hpp"
#include "ssr/PS4Connection.hpp"

// このライブラリが使う名前空間
namespace ssr {

template<PS4Connection connection> class PS4 : Input<PS4Value *> {};

template<> class PS4<PS4Connection::usb> : Input<PS4Value *> {
private:
    USB _usb;
    PS4USB _ps4;

public:
    PS4() : _usb(), _ps4(&_usb) {}
    ~PS4() = default;

    PS4(const PS4 &) = delete;
    PS4 & operator = (const PS4 &) = delete;

    int begin() {
        return _usb.Init();
    }

    void update() {
        _usb.Task();
    }

    bool connected() {
        return _ps4.connected();
    }

    void read(ssr::PS4Value * output) {
        if (output == nullptr || output == NULL) return;
        output->lstick.x = _ps4.getAnalogHat(LeftHatX);
        output->lstick.y = _ps4.getAnalogHat(LeftHatY);
        output->rstick.x = _ps4.getAnalogHat(RightHatX);
        output->rstick.y = _ps4.getAnalogHat(RightHatY);
        output->up = _ps4.getButtonClick(UP);
        output->right = _ps4.getButtonClick(RIGHT);
        output->down = _ps4.getButtonClick(DOWN);
        output->left = _ps4.getButtonClick(LEFT);
        output->triangle = _ps4.getButtonClick(TRIANGLE);
        output->circle = _ps4.getButtonClick(CIRCLE);
        output->cross = _ps4.getButtonClick(CROSS);
        output->square = _ps4.getButtonClick(SQUARE);
        output->l1 = _ps4.getButtonClick(L1);
        output->l2 = _ps4.getAnalogButton(L2);
        output->l3 = _ps4.getButtonClick(L3);
        output->r1 = _ps4.getButtonClick(R1);
        output->r2 = _ps4.getAnalogButton(R2);
        output->r3 = _ps4.getButtonClick(R3);
        output->ps = _ps4.getButtonClick(PS);
        output->share = _ps4.getButtonClick(SHARE);
        output->options = _ps4.getButtonClick(OPTIONS);
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

    PS4Value * read() override {
        ssr::PS4Value * value = new ssr::PS4Value(
            _ps4.getAnalogHat(LeftHatX),  _ps4.getAnalogHat(LeftHatY),
            _ps4.getAnalogHat(RightHatX), _ps4.getAnalogHat(RightHatY),
            _ps4.getButtonClick(UP),
            _ps4.getButtonClick(RIGHT),
            _ps4.getButtonClick(DOWN),
            _ps4.getButtonClick(LEFT),
            _ps4.getButtonClick(TRIANGLE),
            _ps4.getButtonClick(CIRCLE),
            _ps4.getButtonClick(CROSS),
            _ps4.getButtonClick(SQUARE),
            _ps4.getButtonClick(L1),
            _ps4.getAnalogButton(L2),
            _ps4.getButtonClick(L3),
            _ps4.getButtonClick(R1),
            _ps4.getAnalogButton(R2),
            _ps4.getButtonClick(R3),
            _ps4.getButtonClick(PS),
            _ps4.getButtonClick(SHARE),
            _ps4.getButtonClick(OPTIONS),
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
    }
};

template<> class PS4<PS4Connection::bluetooth> : Input<PS4Value *> {
private:
    USB _usb;
    BTD _btd;
    PS4BT _ps4;

public:
    PS4(bool pair = false) : _usb(), _btd(&_usb), _ps4(&_btd, pair) {}
    ~PS4() = default;

    PS4(const PS4 &) = delete;
    PS4 & operator = (const PS4 &) = delete;

    int begin() {
        return _usb.Init();
    }

    void update() {
        _usb.Task();
    }

    bool connected() {
        return _ps4.connected();
    }

    void read(ssr::PS4Value * output) {
        if (output == nullptr || output == NULL) return;
        output->lstick.x = _ps4.getAnalogHat(LeftHatX);
        output->lstick.y = _ps4.getAnalogHat(LeftHatY);
        output->rstick.x = _ps4.getAnalogHat(RightHatX);
        output->rstick.y = _ps4.getAnalogHat(RightHatY);
        output->up = _ps4.getButtonClick(UP);
        output->right = _ps4.getButtonClick(RIGHT);
        output->down = _ps4.getButtonClick(DOWN);
        output->left = _ps4.getButtonClick(LEFT);
        output->triangle = _ps4.getButtonClick(TRIANGLE);
        output->circle = _ps4.getButtonClick(CIRCLE);
        output->cross = _ps4.getButtonClick(CROSS);
        output->square = _ps4.getButtonClick(SQUARE);
        output->l1 = _ps4.getButtonClick(L1);
        output->l2 = _ps4.getAnalogButton(L2);
        output->l3 = _ps4.getButtonClick(L3);
        output->r1 = _ps4.getButtonClick(R1);
        output->r2 = _ps4.getAnalogButton(R2);
        output->r3 = _ps4.getButtonClick(R3);
        output->ps = _ps4.getButtonClick(PS);
        output->share = _ps4.getButtonClick(SHARE);
        output->options = _ps4.getButtonClick(OPTIONS);
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

    PS4Value * read() override {
        ssr::PS4Value * value = new ssr::PS4Value(
            _ps4.getAnalogHat(LeftHatX),  _ps4.getAnalogHat(LeftHatY),
            _ps4.getAnalogHat(RightHatX), _ps4.getAnalogHat(RightHatY),
            _ps4.getButtonClick(UP),
            _ps4.getButtonClick(RIGHT),
            _ps4.getButtonClick(DOWN),
            _ps4.getButtonClick(LEFT),
            _ps4.getButtonClick(TRIANGLE),
            _ps4.getButtonClick(CIRCLE),
            _ps4.getButtonClick(CROSS),
            _ps4.getButtonClick(SQUARE),
            _ps4.getButtonClick(L1),
            _ps4.getAnalogButton(L2),
            _ps4.getButtonClick(L3),
            _ps4.getButtonClick(R1),
            _ps4.getAnalogButton(R2),
            _ps4.getButtonClick(R3),
            _ps4.getButtonClick(PS),
            _ps4.getButtonClick(SHARE),
            _ps4.getButtonClick(OPTIONS),
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
    }
};

} // namespace ssr

#endif /* SSR_PS4_HPP */
