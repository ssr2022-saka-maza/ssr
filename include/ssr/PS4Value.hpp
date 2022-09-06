/**
 * @file PS4Value.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief PS4コントローラーのセンサー値をまとめて扱う型PS4Value
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

#pragma once

#ifndef SSR_PS4_VALUE_HPP

/**
 * @brief ssr/PS4Value.hppがインクルードされていることを示すdefine
 */
#define SSR_PS4_VALUE_HPP

#include <stdint.h>
#include "ssr/Vector2D.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief PS4のセンサー値をまとめて表現する型
     */
    struct PS4Value {
    public:
        /**
         * @brief 左スティックのxy座標 センサー値そのまま
         */
        Vector2D<uint8_t> lstick;

        /**
         * @brief 右スティックのxy座標 センサー値そのまま
         */
        Vector2D<uint8_t> rstick;

        /**
         * @brief 上キーが押されているかどうか
         */
        bool up;

        /**
         * @brief 右キーが押されているかどうか
         */
        bool right;

        /**
         * @brief 下キーが押されているかどうか
         */
        bool down;

        /**
         * @brief 左キーが押されているかどうか
         */
        bool left;

        /**
         * @brief 三角ボタンが押されているかどうか
         */
        bool triangle;

        /**
         * @brief 丸ボタンが押されているかどうか
         */
        bool circle;

        /**
         * @brief バツボタンが押されているかどうか
         */
        bool cross;

        /**
         * @brief 四角ボタンが押されているかどうか
         */
        bool square;

        /**
         * @brief L1ボタンが押されているかどうか
         */
        bool l1;

        /**
         * @brief L2ボタンの押し込み量
         */
        uint8_t l2;

        /**
         * @brief 左スティックが押し込まれているかどうか
         */
        bool l3;

        /**
         * @brief R1ボタンが押されているかどうか
         */
        bool r1;

        /**
         * @brief R2ボタンの押し込み量
         */
        uint8_t r2;

        /**
         * @brief 右スティックが押し込まれているかどうか
         */
        bool r3;

        /**
         * @brief PSボタンが押されているかどうか
         */
        bool ps;

        /**
         * @brief SHAREボタンが押されているかどうか
         */
        bool share;

        /**
         * @brief OPTIONSボタンが押されているかどうか
         */
        bool options;

        /**
         * @brief タッチパッドに指1本目があるかどうか
         */
        bool finger1Touch;

        /**
         * @brief タッチパッドの指1本目の座標 指がない場合は原点(0, 0)
         */
        Vector2D<uint16_t> finger1Pos;

        /**
         * @brief タッチパッドに指2本目があるかどうか
         */
        bool finger2Touch;

        /**
         * @brief タッチパッドの指2本目の座標 指がない場合は原点(0, 0)
         */
        Vector2D<uint16_t> finger2Pos;

        /**
         * @brief コントローラーのpitch傾き
         */
        float pitch;

        /**
         * @brief コントローラーのroll傾き
         */
        float roll;

        /**
         * @brief 初期化子
         * @param lstick_x     uint8_t  左スティックのx座標 センサー値そのまま
         * @param lstick_y     uint8_t  左スティックのy座標 センサー値そのまま
         * @param rstick_x     uint8_t  右スティックのx座標 センサー値そのまま
         * @param rstick_y     uint8_t  右スティックのy座標 センサー値そのまま
         * @param up           bool     上キーが押されているかどうか
         * @param right        bool     右キーが押されているかどうか
         * @param down         bool     下キーが押されているかどうか
         * @param left         bool     左キーが押されているかどうか
         * @param triangle     bool     三角ボタンが押されているかどうか
         * @param circle       bool     丸ボタンが押されているかどうか
         * @param cross        bool     バツボタンが押されているかどうか
         * @param square       bool     四角ボタンが押されているかどうか
         * @param l1           bool     L1ボタンが押されているかどうか
         * @param l2           uint8_t  L2ボタンの押し込み量
         * @param l3           bool     左スティックが押し込まれているかどうか
         * @param r1           bool     R1ボタンが押されているかどうか
         * @param r2           uint8_t  R2ボタンの押し込み量
         * @param r3           bool     右スティックが押し込まれているかどうか
         * @param ps           bool     PSボタンが押されているかどうか
         * @param share        bool     SHAREボタンが押されているかどうか
         * @param options      bool     OPTIONSボタンが押されているかどうか
         * @param finger1Touch bool     タッチパッドに指1本目があるかどうか
         * @param finger1Pos_x uint16_t タッチパッドの指1本目のx座標 指がない場合は0
         * @param finger1Pos_y uint16_t タッチパッドの指1本目のy座標 指がない場合は0
         * @param finger2Touch bool     タッチパッドに指2本目があるかどうか
         * @param finger2Pos_x uint16_t タッチパッドの指2本目のx座標 指がない場合は0
         * @param finger2Pos_y uint16_t タッチパッドの指2本目のy座標 指がない場合は0
         * @param pitch        float    コントローラーのpitch傾き
         * @param roll         float    コントローラーのroll傾き
         */
        PS4Value(
            uint8_t lstick_x = 0, uint8_t lstick_y = 0, uint8_t rstick_x = 0, uint8_t rstick_y = 0,
            bool up       = false, bool right  = false, bool down  = false, bool left   = false,
            bool triangle = false, bool circle = false, bool cross = false, bool square = false,
            bool l1 = false, uint8_t l2 = 0, bool l3 = false,
            bool r1 = false, uint8_t r2 = 0, bool r3 = false,
            bool ps = false, bool share = false, bool options = false,
            bool finger1Touch = false, uint16_t finger1Pos_x = 0, uint16_t finger1Pos_y = 0,
            bool finger2Touch = false, uint16_t finger2Pos_x = 0, uint16_t finger2Pos_y = 0,
            float pitch = 0, float roll = 0
        );
    }; // struct PS4Value
} // namespace ssr

#endif /* SSR_PS4_VALUE_HPP */
