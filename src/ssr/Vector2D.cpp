#include <math.h>
#include "ssr/Vector2D.hpp"

template<typename Value>
ssr::Vector2D<Value>::Vector2D(Value x, Value y)
    : x(x), y(y) {}

template<typename Value>
auto ssr::Vector2D<Value>::dot(const ssr::Vector2D<Value> v) -> decltype(x * v.x + y * v.y) {
    return x * v.x + y * v.y;
}

template<typename Value>
auto ssr::Vector2D<Value>::angle() -> decltype(atan2(y, x)) {
    return atan2(y, x);
}

template<typename Value>
auto ssr::Vector2D<Value>::magSq() -> decltype(x * x + y * y) {
    return x * x + y * y;
}

template<typename Value>
auto ssr::Vector2D<Value>::mag() -> decltype(sqrt(magSq())) {
    return sqrt(magSq());
}

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