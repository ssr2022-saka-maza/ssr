#pragma once

#ifndef SSR_VECTOR_2D_HPP
#define SSR_VECTOR_2D_HPP

#include <math.h>

// このライブラリが使う名前空間
namespace ssr {

template<typename Value> class Vector2D {
public:
    Value x, y;

    Vector2D(Value x = 0, Value y = 0)
        : x(x), y(y) {}

    auto dot(const Vector2D<Value> v) -> decltype(x * v.x + y * v.y) {
        return x * v.x + y * v.y;
    }

    auto angle() -> decltype(atan2(y, x)) {
        return atan2(y, x);
    }

    auto magSq() -> decltype(x * x + y * y) {
        return x * x + y * y;
    }

    auto mag() -> decltype(sqrt(magSq())) {
        return sqrt(magSq());
    }
};

} // namespace ssr

template<typename Value>
bool operator == (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh) {
    return lh.x == rh.x && lh.y == rh.y;
}

template<typename Value>
bool operator != (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh) {
    return lh.x != rh.x && lh.y != rh.y;
}

template<typename Value>
ssr::Vector2D<Value> & operator += (ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh) {
    lh.x += rh.x;
    lh.y += rh.y;
    return lh;
}

template<typename Value>
ssr::Vector2D<Value> & operator -= (ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh) {
    lh.x -= rh.x;
    lh.y -= rh.y;
    return lh;
}

template<typename Value>
ssr::Vector2D<Value> operator + (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh) {
    return ssr::Vector2D<Value>{lh.x + rh.x, lh.y + rh.y};
}

template<typename Value>
ssr::Vector2D<Value> operator - (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh) {
    return ssr::Vector2D<Value>{lh.x - rh.x, lh.y - rh.y};
}

#endif /* SSR_VECTOR_2D_HPP */
