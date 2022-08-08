#pragma once

#ifndef SSR_PS4_OPERATION_HPP
#define SSR_PS4_OPERATION_HPP

#include "ssr/PS4Value.hpp"

// このライブラリが使う名前空間
namespace ssr {

// PS4のセンサー値から操作を行う
class PS4Operation {
private:
    // ID生成
    static uint8_t _generateID();

public:
    // オペレーションのID PS4Operationオブジェクト内でunique
    const uint8_t id;

    // 初期化子
    PS4Operation();

    // コピー禁止
    PS4Operation(const PS4Operation &) = delete;
    PS4Operation & operator=(const PS4Operation &) = delete;

    /**
     * センサー値から操作を行う
     * @param value const ssr::PS4Value & コントローラーのセンサー値
     * @note この関数はセンサーの値を取得するごとに呼び出される
     */
    virtual void operate(const PS4Value & value);
}; // class PS4Operation

} // namespace ssr

bool operator==(const ssr::PS4Operation & lh, const ssr::PS4Operation & rh);

#endif /* SSR_PS4_OPERATION_HPP */
