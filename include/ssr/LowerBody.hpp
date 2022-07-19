#pragma once

#ifndef SSR_LOWER_BODY_HPP
#define SSR_LOWER_BODY_HPP

#include <ssr/MotorDriver.hpp>

// このライブラリが使う名前空間
namespace ssr {

// 足回りを操作
class LowerBody {
public:
    // 正面のモーター
    MotorDriver motor1;
    // 左後ろのモーター
    MotorDriver motor2;
    // 右後ろのモーター
    MotorDriver motor3;

    /**
     * 初期化子
     * @param PinType dir1 モーター1につなげるDIRピンの番号
     * @param PinType pwm1 モーター1につなげるPWMピンの番号
     * @param PinType dir2 モーター2につなげるDIRピンの番号
     * @param PinType pwm2 モーター2につなげるPWMピンの番号
     * @param PinType dir3 モーター3につなげるDIRピンの番号
     * @param PinType pwm3 モーター3につなげるPWMピンの番号
     */
    LowerBody(
        PinType di1, PinType pwm1,
        PinType di2, PinType pwm2,
        PinType di3, PinType pwm3
    );

    /**
     * 初期化子
     * @param MotorDriver motor1 モーター1
     * @param MotorDriver motor1 モーター2
     * @param MotorDriver motor1 モーター3
     */
    LowerBody(MotorDriver motor1, MotorDriver motor2, MotorDriver motor3);

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
     * 足回りの初期設定。全体のsetup()内でこれを呼び出すこと
     * @param float v_x 初期並行速度のx成分。デフォルトは0
     * @param float v_y 初期並行速度のy成分。デフォルトは0
     * @param float v_theta 中心からタイヤまでの距離*角速度 の初期値。デフォルトは0
     */
    void begin(float v_x = 0, float v_y = 0, float v_theta = 0);

    /**
     * 並行移動と回転を同時に設定する
     * @param float v_x 並行速度のx成分
     * @param float v_y 並行速度のy成分
     * @param float v_theta 中心からタイヤまでの距離 * 角速度
     */
    void twist(float v_x, float v_y, float v_theta);

    /**
     * 回転なしの並行移動を設定する
     * @param float v_x 並行速度のx成分
     * @param float v_y 並行速度のy成分
     */
    void parallel(float v_x, float v_y);

    /**
     * 並行移動なしで回転を設定する
     * @param float v_theta 中心からタイヤまでの距離 * 角速度
     */
    void rotate(float v_theta);
};

}

# endif /* SSR_LOWER_BODY_HPP */