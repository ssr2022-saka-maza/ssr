/**
 * @file Output.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 出力モジュール/機能抽象型Output
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_OUTPUT_HPP

/**
 * @brief ssr/Output.hppがインクルードされていることを示すdefine
 */
#define SSR_OUTPUT_HPP

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 出力するもの全般の抽象型
     * @tparam ArgT 出力する値の型
     */
    template<typename ArgT> class Output {
    public:
        /**
         * 値を出力する
         * @param ArgT value 出力する値
         */
        virtual void write(ArgT value) = 0;
    }; // class Output
} // namespace ssr

#endif /* SSR_OUTPUT_HPP */
