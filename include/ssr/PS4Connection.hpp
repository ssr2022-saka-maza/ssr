/**
 * @file PS4Connection.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief PS4コントローラーとの接続方式を表現するenum型PS4Connection
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_PS4_CONNECTION_HPP

/**
 * @brief ssr/PS4Connection.hppがインクルードされていることを示すdefine
 */
#define SSR_PS4_CONNECTION_HPP

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief PS4コントローラーとの接続方式を表現するenum型
     */
    enum class PS4Connection {
        /**
         * @brief usbでの有線接続
         */
        usb = 0,
        /**
         * @brief bluetoothでの無線接続
         */
        bluetooth
    };
} // namespace ssr

#endif /* SSR_PS4_CONNECTION_HPP */