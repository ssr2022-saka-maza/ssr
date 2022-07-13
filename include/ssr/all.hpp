#pragma once

#ifndef SSR_ALL_HPP
#define SSR_ALL_HPP

// このライブラリが使う名前空間
namespace ssr {}

// 基底型たち
#include "ssr/Types.hpp"
// デジタルinputのピン型
#include "ssr/DigitalIn.hpp"
// デジタルoutputのピン型
#include "ssr/DigitalOut.hpp"
// アナログinputのピン型
#include "ssr/AnalogIn.hpp"
// アナログoutputのピン型
#include "ssr/AnalogOut.hpp"
// モータードライバのハンドラ型
#include "ssr/MotorDriver.hpp"

#endif /* SSR_ALL_HPP */
