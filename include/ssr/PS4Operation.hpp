/**
 * @file PS4Operation.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief PS4Controllerに追加するOperation型PS4Operation
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_PS4_OPERATION_HPP

/**
 * @brief ssr/PS4Operation.hppがインクルードされていることを示すdefine
 */
#define SSR_PS4_OPERATION_HPP

#include "ssr/PS4Value.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief PS4Controllerに追加する操作の型
     */
    class PS4Operation {
    private:
        /**
         * @brief PS4OperationのIDを生成する関数
         * @return uint8_t 新しく作られるPS4OperationオブジェクトのID
         */
        static uint8_t _generateID();

    public:
        /**
         * @brief オペレーションのID PS4Operationオブジェクト内でunique
         */
        const uint8_t id;

        /**
         * @brief Construct a new PS4Operation object
         */
        explicit PS4Operation();

        // コピーコンストラクタを禁止
        PS4Operation(const PS4Operation &) = delete;
        // コピー代入を禁止
        PS4Operation & operator=(const PS4Operation &) = delete;
        // ムーブコンストラクタを禁止
        PS4Operation(PS4Operation &&) = delete;
        // ムーブ代入を禁止
        PS4Operation & operator = (PS4Operation &&) = delete;

        /**
         * @brief センサー値から操作を行う
         * @param value const ssr::PS4Value& コントローラーのセンサー値
         * @note この関数はセンサーの値を取得するごとに呼び出される
         */
        virtual void operate(const PS4Value & value);
    }; // class PS4Operation
} // namespace ssr

/**
 * @brief PS4Operationでの同値定義
 * @param lh 左辺
 * @param rh 右辺
 * @return true lh.id == rh.id
 * @return false lh.id != rh.id
 */
bool operator==(const ssr::PS4Operation & lh, const ssr::PS4Operation & rh);

#endif /* SSR_PS4_OPERATION_HPP */
