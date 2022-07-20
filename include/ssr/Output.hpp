#pragma once

#ifndef SSR_OUTPUT_HPP
#define SSR_OUTPUT_HPP

// このライブラリが使う名前空間
namespace ssr {

/**
 * 出力するもの全般の抽象型
 * @tparam ArgT 出力する値の型
 */
template<typename ArgT> class Output {
public:
    /**
     * 値を出力する
     * @param ArgT value 出力する値
     */
    virtual void write(ArgT value) = 0;
};

} /* namespace ssr */

#endif /* SSR_OUTPUT_HPP */
