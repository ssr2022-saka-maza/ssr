/**
 * @file Vector2D.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 2次元ベクトル型Vector2D
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_VECTOR_2D_HPP

/**
 * @brief ssr/Vector2D.hppがインクルードされていることを示すdefine
 */
#define SSR_VECTOR_2D_HPP

#include <math.h>

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 2次元ベクトルを表現する型
     * @tparam T 成分の型
     */
    template<typename T> class Vector2D {
    public:
        /**
         * @brief 成分の型
         */
        using Value = decltype(T(0));

        /**
         * @brief x成分
         */
        T x;

        /**
         * @brief y成分
         */
        T y;

        /**
         * @brief Construct a new Vector 2 D object
         * @param x x成分
         * @param y y成分
         */
        Vector2D(T x = 0, T y = 0)
            : x(x), y(y) {}

        /**
         * @brief ベクトルとの内積
         * @param v 内積をとるベクトル
         * @return decltype(x * v.x + y * v.y) 内積の値
         */
        auto dot(const Vector2D<T> v) -> decltype(x * v.x + y * v.y) {
            return x * v.x + y * v.y;
        }

        /**
         * @brief ベクトルの偏角
         * @return decltype(atan2(y, x)) x軸から何ラジアン回転したか
         */
        auto angle() -> decltype(atan2(y, x)) {
            return atan2(y, x);
        }

        /**
         * @brief ベクトルの大きさの2乗
         * @return decltype(x * x + y * y) 大きさの2乗
         */
        auto magSq() -> decltype(x * x + y * y) {
            return x * x + y * y;
        }

        /**
         * @brief ベクトルの大きさ
         * @return decltype(sqrt(magSq())) ベクトルの大きさ
         */
        auto mag() -> decltype(sqrt(magSq())) {
            return sqrt(magSq());
        }
    }; // class Vector2D
} // namespace ssr

/**
 * @brief ベクトルが等しいかどうか
 * @tparam T 成分の型
 * @param lh 左辺
 * @param rh 右辺
 * @return true 2ベクトルの成分が全て等しい
 * @return false 2ベクトルの成分のいずれかが異なる
 */
template<typename T1, typename T2>
bool operator==(const ssr::Vector2D<T1> & lh, const ssr::Vector2D<T2> & rh) {
    return lh.x == rh.x && lh.y == rh.y;
}

/**
 * @brief ベクトルが異なるかどうか
 * @tparam T 成分の型
 * @param lh 左辺
 * @param rh 右辺
 * @return true 2ベクトルの成分のいずれかが異なる
 * @return false 2ベクトルの成分が全て等しい
 */
template<typename T1, typename T2>
bool operator!=(const ssr::Vector2D<T1> & lh, const ssr::Vector2D<T2> & rh) {
    return lh.x != rh.x || lh.y != rh.y;
}

/**
 * @brief ベクトルにincremental addする
 * @tparam T 成分の型
 * @param lh 左辺
 * @param rh 右辺
 * @return ssr::Vector2D<T>& incremental addしたベクトルの参照
 */
template<typename T1, typename T2>
ssr::Vector2D<T1> & operator+=(ssr::Vector2D<T1> & lh, const ssr::Vector2D<T2> & rh) {
    lh.x += rh.x;
    lh.y += rh.y;
    return lh;
}

/**
 * @brief ベクトルにincremental subtractする
 * @tparam T 成分の型
 * @param lh 左辺
 * @param rh 右辺
 * @return ssr::Vector2D<T>& incremental subtractしたベクトルの参照
 */
template<typename T1, typename T2>
ssr::Vector2D<T1> & operator-=(ssr::Vector2D<T1> & lh, const ssr::Vector2D<T2> & rh) {
    lh.x -= rh.x;
    lh.y -= rh.y;
    return lh;
}

/**
 * @brief ベクトルの足し算
 * @tparam T 成分の型
 * @param lh 左辺
 * @param rh 右辺
 * @return ssr::Vector2D<T>& 足し算したベクトル
 */
template<typename T1, typename T2>
auto operator+(const ssr::Vector2D<T1> & lh, const ssr::Vector2D<T2> & rh)
-> ssr::Vector2D<decltype(lh.x + rh.x)> {
    return ssr::Vector2D<decltype(lh.x + rh.x)>{lh.x + rh.x, lh.y + rh.y};
}

/**
 * @brief ベクトルの引き算
 * @tparam T 成分の型
 * @param lh 左辺
 * @param rh 右辺
 * @return ssr::Vector2D<T>& 引き算したベクトル
 */
template<typename T1, typename T2>
auto operator-(const ssr::Vector2D<T1> & lh, const ssr::Vector2D<T2> & rh)
-> ssr::Vector2D<decltype(T1(0) - T2(0))> {
    return ssr::Vector2D<decltype(T1(0) - T2(0))>{lh.x - rh.x, lh.y - rh.y};
}

#endif /* SSR_VECTOR_2D_HPP */
