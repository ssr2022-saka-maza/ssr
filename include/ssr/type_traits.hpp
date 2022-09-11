/**
 * @file type_traits.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 型判定のためのメタ関数群
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_TYPE_TRAITS_HPP

namespace ssr {
    /**
     * @brief ssr/type_traits.hppがインクルードされていることを示すdefine
     */
    #define SSR_TYPE_TRAITS_HPP

    /**
     * @brief trueを表す型
     */
    struct true_type {
        /**
         * @brief true
         */
        static constexpr bool value = true;
    };

    /**
     * @brief falseを表す型
     */
    struct false_type {
        /**
         * @brief false
         */
        static constexpr bool value = false;
    };

    /**
     * @brief 条件式が真の場合のみ有効な型
     * @tparam cond 条件式
     * @tparam T condがtrueの場合の型 enable_if<cond, T>::type で参照
     */
    template<bool cond, typename T>
    struct enable_if {};

    template<typename T>
    struct enable_if<true, T> {
        using type = T;
    };

    /**
     * @brief 2つの型が等しいかどうかを判定する型 is_same<T, U>::valueで真偽値を判定
     * @tparam T 比較対象の型1
     * @tparam U 比較対象の型2
     */
    template<typename T, typename U>
    struct is_same : false_type {};

    template<typename T>
    struct is_same<T, T> : true_type {};

    /**
     * @brief 算術型かを判定するロジック部分
     */
    struct is_arithmetic_impl {
    private:
        /**
         * @brief 加算可能かを判定する
         * @tparam T 判定する型
         * @param t T* サンプル値のポインタ
         * @return decltype(*t + 0, true_type()) or false_type
         */
        template<typename T> static auto check_add(T* t) -> decltype(*t + 0, true_type());
        template<typename T> static false_type check_add(...);

        /**
         * @brief 減算可能かを判定する
         * @tparam T 判定する型
         * @param t T* サンプル値のポインタ
         * @return decltype(*t - 0, true_type()) or false_type
         */
        template<typename T> static auto check_sub(T* t) -> decltype(*t - 0, true_type());
        template<typename T> static false_type check_sub(...);

        /**
         * @brief 乗算可能かを判定する
         * @tparam T 判定する型
         * @param t T* サンプル値のポインタ
         * @return decltype(*t * 1, true_type()) or false_type
         */
        template<typename T> static auto check_mul(T* t) -> decltype(*t * 1, true_type());
        template<typename T> static false_type check_mul(...);

        /**
         * @brief 除算可能かを判定する
         * @tparam T 判定する型
         * @param t T* サンプル値のポインタ
         * @return decltype(*t / 1, true_type()) or false_type
         */
        template<typename T> static auto check_div(T* t) -> decltype(*t / 1, true_type());
        template<typename T> static false_type check_div(...);

    public:
        /**
         * @brief 四則演算が可能かを判定する
         * @tparam T 判定する型
         * @param t サンプル値のポインタ
         * @return 四則演算可能であればtrue_type, 不可能であればfalse_type
         */
        template<typename T> static auto check(T* t) -> typename enable_if<
            decltype(check_add(t))::value &&
            decltype(check_sub(t))::value &&
            decltype(check_mul(t))::value &&
            decltype(check_div(t))::value,
            true_type
        >::type;
        template<typename T> static false_type check(...);
    };

    /**
     * @brief 算術型かを判定する
     * @tparam T 判定対象の型
     */
    template<typename T>
    struct is_arithmetic : decltype(is_arithmetic_impl::check<T>(nullptr)) {};
}

#endif /* SSR_TYPE_TRAITS_HPP */
