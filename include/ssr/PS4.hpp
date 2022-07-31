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

// このライブラリが使う名前空間
namespace ssr {

// PS4コントローラーを扱う
class PS4 final : Input<PS4Value *> {
private:
    USB _usb;
    BTD * _btd = nullptr;
    PS4USB * _ps4usb = nullptr;
    PS4BT * _ps4bt = nullptr;
    bool _connect_usb = false;

    PS4() = default;

    PS4Parser * _getParser();

public:
    // コピー、ムーブを禁止
    PS4(const PS4 &) = delete;
    PS4 & operator = (const PS4 &) = delete;
    PS4(PS4 &&) = delete;
    PS4 & operator = (PS4 &&) = delete;

    // デストラクタ
    ~PS4();

    /**
     * 初期化 全体のsetup()内でこれを呼ぶこと
     * @return int 初期化に失敗したら-1
     */
    int begin();

    // コントローラーの状態を更新
    void update();

    /**
     * 接続確認
     * @return 繋がっていたらtrue
     */
    bool connected();

    /**
     * コントローラーの値を読み取る
     * @param[out] output ssr::PS4Value * 読み取った値を書き込む先
     */
    void read(PS4Value * output);

    /**
     * コントローラーの値を読み取る
     * @return ssr::PS4Value * コントローラーの現在の値 使い終わったらdeleteすること
     */
    PS4Value * read() override;

    /**
     * USBで有線接続したコントローラーを取得する
     * @return ssr::PS4 * 取得したコントローラーのポインタ
     */
    static PS4 * usb();

    /**
     * Bluetoothで無線接続したコントローラーを取得する
     * @return ssr::PS4 * 取得したコントローラーのポインタ
     */
    static PS4 * bluetooth(bool pair = false);
};

} // namespace ssr

#endif /* SSR_PS4_HPP */
