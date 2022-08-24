/**
 * @file Input.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 入力モジュール抽象型Input
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_INPUT_HPP

/**
 * @brief ssr/Input.hppがインクルードされていることを示すdefine
 */
#define SSR_INPUT_HPP

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 入力を受け取るもの全般の抽象型
     * @tparam ResultT 読んだ値の型
     */
    template<typename ResultT> class Input {
    public:
        /**
         * @brief 値を読む
         * @return ResultT 読み取った値
         */
        virtual ResultT read() = 0;
    }; // class Input
} // namespace ssr

#endif /* SSR_INPUT_HPP */
