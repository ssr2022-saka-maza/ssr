/**
 * @file LowerBody.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 足回りを操作する型LowerBody
 * @version 0.1
 * @date 2022-08-24
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_LOWER_BODY_HPP

/**
 * @brief ssr/LowerBody.hppがインクルードされていることを示すdefine
 */
#define SSR_LOWER_BODY_HPP

#include <math.h>
#include <ssr/Vector2D.hpp>
#include <ssr/MotorDriver.hpp>

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 足回りを操作
     */
    class LowerBody {
    private:
        /**
         * @brief モーター1の方向
         */
        const Vector2D<float> _dir1;

        /**
         * @brief モーター2の方向
         */
        const Vector2D<float> _dir2;

        /**
         * @brief モーター3の方向
         */
        const Vector2D<float> _dir3;

        /**
         * @brief 正面のモーター
         */
        MotorDriver _motor1;

        /**
         * @brief 左後ろのモーター
         */
        MotorDriver _motor2;

        /**
         * @brief 右後ろのモーター
         */
        MotorDriver _motor3;

    public:
        // デフォルトコンストラクタを禁止
        LowerBody() = delete;
        // コピーコンストラクタを禁止
        LowerBody(const LowerBody &) = delete;
        // コピー代入を禁止
        LowerBody & operator=(const LowerBody &) = delete;
        // ムーブコンストラクタを禁止
        LowerBody(LowerBody&&) = delete;
        // ムーブ代入を禁止
        LowerBody & operator=(LowerBody&&) = delete;
        // デストラクタを定義
        ~LowerBody() = default;

        /**
         * @brief 初期化子
         * @param dir1 ssr::PinType モーター1につなげるDIRピンの番号
         * @param pwm1 ssr::PinType モーター1につなげるPWMピンの番号
         * @param dir2 ssr::PinType モーター2につなげるDIRピンの番号
         * @param pwm2 ssr::PinType モーター2につなげるPWMピンの番号
         * @param dir3 ssr::PinType モーター3につなげるDIRピンの番号
         * @param pwm3 ssr::PinType モーター3につなげるPWMピンの番号
         */
        explicit LowerBody(
            PinType dir1, PinType pwm1,
            PinType dir2, PinType pwm2,
            PinType dir3, PinType pwm3
        );

        /**
         * @note
         * # 各軸の設定など
         * x軸: 重心から正面の方向
         * y軸: 重心からx軸の正方向を向いて垂直に左方向
         *
         * # モーター配置の詳細
         *           正面
         * +----------^----------+
         * |        --1--        |
         * |                     |
         * |          x          |
         * |         y*          |
         * |  \               /  |
         * |   2             3   |
         * |    \           /    |
         * +---------------------+
         * 配置は上のAsciiArtの通り。真ん中の*が中心、軸はxyって書いてあるやつが各軸の正方向。各タイヤは反時計回りを正転方向で
         *
         * # 各変数名の定義
         * v_x := 並行速度x成分
         * v_y := 並行速度y成分
         * v_theta := 中心からタイヤまでの距離 * 角速度
         */

        /**
         * @brief 足回りの初期設定。全体のsetup()内でこれを呼び出すこと
         * @param v_x float 初期並行速度のx成分。デフォルトは0
         * @param v_y float 初期並行速度のy成分。デフォルトは0
         * @param v_theta float 中心からタイヤまでの距離*角速度 の初期値。デフォルトは0
         */
        void begin(float v_x = 0, float v_y = 0, float v_theta = 0) noexcept;

    private:
        /**
         * @brief モーターの速度をそのまま設定する
         * @param v1 float モーター1の速度
         * @param v2 float モーター2の速度
         * @param v3 float モーター3の速度
         */
        void _setPowers_raw(float v1, float v2, float v3) noexcept;

        /**
         * @brief モーターの速度を正規化して設定する
         * @param v1 float モーター1の速度
         * @param v2 float モーター2の速度
         * @param v3 float モーター3の速度
         */
        void _setPowers_normalized(float v1, float v2, float v3) noexcept;

    public:

        /**
         * @brief モーターの速度を設定する
         * @param v1 float モーター1の速度
         * @param v2 float モーター2の速度
         * @param v3 float モーター3の速度
         */
        void setPowers(float v1, float v2, float v3) noexcept;

        /**
         * @brief 並行移動と回転を同時に設定する
         * @param v_x float 並行速度のx成分
         * @param v_y float 並行速度のy成分
         * @param v_theta float 中心からタイヤまでの距離 * 角速度
         */
        void twist(float v_x, float v_y, float v_theta) noexcept;

        /**
         * @brief 回転なしの並行移動を設定する
         * @param v_x float 並行速度のx成分
         * @param v_y float 並行速度のy成分
         */
        inline void parallel(float v_x, float v_y) noexcept;

        /**
         * @brief 並行移動なしで回転を設定する
         * @param v_theta float 中心からタイヤまでの距離 * 角速度
         */
        inline void rotate(float v_theta) noexcept;
    }; // class LowerBody
} // namespace ssr

# endif /* SSR_LOWER_BODY_HPP */