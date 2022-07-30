#pragma once

#ifndef SSR_VECTOR_2D_HPP
#define SSR_VECTOR_2D_HPP

// このライブラリが使う名前空間
namespace ssr {

template<typename Value> class Vector2D {
public:
    Value x, y;

    Vector2D(Value x = 0, Value y = 0);
    auto dot(const Vector2D<Value> v) -> decltype(x * v.x + y * v.y);
    auto angle() -> decltype(atan2(y, x));
    auto magSq() -> decltype(x * x + y * y);
    auto mag() -> decltype(sqrt(magSq()));
};

} // namespace ssr

template<typename Value> bool operator == (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh);
template<typename Value> bool operator != (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh);

template<typename Value> ssr::Vector2D<Value> & operator += (ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh);
template<typename Value> ssr::Vector2D<Value> & operator -= (ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh);

template<typename Value> ssr::Vector2D<Value> operator + (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh);
template<typename Value> ssr::Vector2D<Value> operator - (const ssr::Vector2D<Value> & lh, const ssr::Vector2D<Value> & rh);

#endif /* SSR_VECTOR_2D_HPP */
