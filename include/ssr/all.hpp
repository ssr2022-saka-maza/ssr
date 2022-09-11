/**
 * @file all.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief ライブラリ全てを一括でインクルードするためのヘッダファイル
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_ALL_HPP

/**
 * @brief ssr/all.hppがインクルードされていることを示すdefine
 */
#define SSR_ALL_HPP

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {}

#include "ssr/PinType.hpp"
#include "ssr/Vector2D.hpp"
#include "ssr/type_traits.hpp"
#include "ssr/MovingAverage.hpp"
#include "ssr/Input.hpp"
#include "ssr/Output.hpp"
#include "ssr/DigitalIn.hpp"
#include "ssr/DigitalOut.hpp"
#include "ssr/AnalogIn.hpp"
#include "ssr/AnalogOut.hpp"
#include "ssr/Solenoid.hpp"
#include "ssr/SyncServo.hpp"
#include "ssr/MotorDriver.hpp"
#include "ssr/LowerBody.hpp"
#include "ssr/PS4Value.hpp"
#include "ssr/PS4.hpp"
#include "ssr/PS4Connection.hpp"
#include "ssr/PS4Controller.hpp"
#include "ssr/PS4Operation.hpp"

#endif /* SSR_ALL_HPP */
