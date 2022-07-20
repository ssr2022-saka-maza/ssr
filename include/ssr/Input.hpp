#pragma once

#ifndef SSR_INPUT_HPP
#define SSR_INPUT_HPP

// このライブラリが使う名前空間
namespace ssr {

/**
 * 入力を受け取るもの全般の抽象型
 * @tparam ResultT 読んだ値の型
 */
template<typename ResultT> class Input {
public:
    /**
     * 値を読む
     * @return ResultT 読み取った値
     */
    virtual ResultT read() = 0;
};

} /* namespace ssr */

#endif /* SSR_INPUT_HPP */
