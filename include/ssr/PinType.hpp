/**
 * @file PinType.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief ピンを表す型
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

#pragma once

#ifndef SSR_PIN_TYPE_HPP
#define SSR_PIN_TYPE_HPP

#include <stdint.h>

/**
 * @brief このライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief Arduino Megaのピン番号を表す型
     */
    using PinType = uint8_t;
} // namespace ssr

#endif /* SSR_PIN_TYPE_HPP */