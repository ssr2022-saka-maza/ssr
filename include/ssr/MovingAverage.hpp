/**
 * @file MovingAverage.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 移動平均を扱う型MovingAverage
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

#pragma once

#ifndef SSR_MOVING_AVERAGE_HPP

/**
 * @brief ssr/MovingAverage.hppがインクルードされていることを示すdefine
 */
#define SSR_MOVING_AVERAGE_HPP

#include <stdint.h>
#include <ssr/Input.hpp>
#include <ssr/Output.hpp>
#include <ssr/type_traits.hpp>

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 移動平均を扱う
     * @tparam T 扱う値の型 算術型でなければいけない
     */
    template<typename T>
    class MovingAverage : public Input<T>, public Output<T> {
        static_assert(is_arithmetic<T>::value, "template parameter of ssr::MovingAverage must be arithmetic");
    private:
        /**
         * @brief 次に更新する配列のインデックス
         */
        uint16_t _index;

        /**
         * @brief indexが配列を少なくとも1周したかどうか
         */
        bool _cycled;

        /**
         * @brief 平均をとる値の配列
         */
        T * _values;

        /**
         * @brief 現在の値の合計
         */
        T _values_sum;
    public:
        /**
         * @brief 保持する値の数
         */
        const uint16_t _capacity;

        /**
         * @brief Construct a new Moving Average object
         * @param capacity 保持する値の数
         */
        explicit MovingAverage(uint16_t capacity)
        : _index(0), _cycled(false), _values(nullptr), _values_sum(0), _capacity(capacity) {
            _values = new T[_capacity]{};
        }

        /**
         * @brief Destroy the Moving Average object
         */
        ~MovingAverage() {
            delete[] _values;
        }

        /**
         * @brief 平均値を取得する
         * @return T 現在保持している値の平均 値を1つも保持していない場合は0
         */
        virtual T read() override {
            if (_index == 0) {
                return static_cast<T>(0);
            }
            if (!_cycled) {
                return _values_sum / static_cast<T>(_index);
            }
            return _values_sum / static_cast<T>(_capacity);
        }

        /**
         * @brief 値を追加する
         * @param value 追加する値
         */
        virtual void write(T value) override {
            _values_sum += value - _values[_index];
            _values[_index] = value;
            _index++;
            if (_index == _capacity) {
                _index = 0;
                _cycled = true;
            }
        }
    }; // class MovingAverage
} // namespace ssr

#endif /* SSR_MOVING_AVERAGE_HPP */
