/**
 * @file PS4Controller.hpp
 * @author H1rono (hronok66@gmail.com)
 * @brief 操作を登録できるPS4Controller
 * @version 0.1
 * @copyright Copyright (c) 2022 ssr2022-saka-maza
 */

#pragma once

#ifndef SSR_PS4_CONTROLLER_HPP

/**
 * @brief ssr/PS4Controller.hppがインクルードされていることを示すdefine
 */
#define SSR_PS4_CONTROLLER_HPP

#include "ssr/PS4.hpp"
#include "ssr/PS4Operation.hpp"

/**
 * @brief ssrライブラリが使う名前空間
 */
namespace ssr {
    /**
     * @brief 操作を登録できるPS4コントローラー
     * @tparam connection ssr::PS4Connection 接続方式の種類 ::usbまたは::bluetooth
     */
    template<ssr::PS4Connection connection> class PS4Controller {};

    /**
     * @brief 操作を登録できるPS4コントローラーの有線接続版
     * @tparam ssr::PS4Connection::usb USBケーブルでの有線接続
     * @note PS4Operation型のポインタを渡すことで新たな操作を登録する
     */
    template<> class PS4Controller<PS4Connection::usb> {
    public:
        /**
         * @brief 操作を表現するオブジェクトの型
         */
        using Operation = PS4Operation;

    private:
        /**
         * @brief 現在登録されている操作の数
         */
        uint8_t _operationCount;
        /**
         * @brief 現在登録されている操作の配列
         */
        Operation ** _operations;
        /**
         * @brief 使用するコントローラー
         */
        ssr::PS4<PS4Connection::usb> _ps4;

    public:
        /**
         * @brief 登録できる操作の最大数 最初に設定したら変更不可能
         */
        const uint8_t operationCapacity;

        /**
         * @brief 初期化子
         * @param operationCapacity uint8_t 登録できる操作の最大数 最初に設定したら変更不可能
         */
        PS4Controller(uint8_t operationCapacity = 16)
        : _operationCount(0), _operations(nullptr), _ps4(), operationCapacity(operationCapacity)
        {
            _operations = new Operation*[this->operationCapacity];
            for (uint8_t i = 0; i < this->operationCapacity; ++i) {
                _operations[i] = nullptr;
            }
        }

        /**
         * @brief Destroy the PS4Controller object
         */
        ~PS4Controller() {
            if (_operations == NULL || _operations == nullptr) return;
            delete[] _operations;
        }

        /**
         * @brief コントローラーを初期化する 必ずsetup()で呼び出して返り値を確認すること
         * @return int 初期化に成功したら0 失敗したら-1
         */
        int begin() {
            return _ps4.begin();
        }

        /**
         * @brief コントローラーに接続できているか確認する
         * @return true 接続できている
         * @return false 接続できていない
         */
        bool connected() {
            return _ps4.connected();
        }

        /**
         * @brief 最新の情報に更新して、登録された操作を実行する 毎loop()ごとに呼び出すこと
         */
        void update() {
            _ps4.update();
            if (!connected()) return;
            PS4Value value{};
            _ps4.read(&value);
            for (uint8_t i = 0; i < _operationCount; ++i) {
                _operations[i]->operate(value);
            }
        }

        /**
         * @brief 操作を追加する
         * @param operation Operation * 操作を表現するオブジェクトのポインタ あくまでポインタを登録するだけなので注意
         */
        void addOperation(Operation * operation) {
            _operations[_operationCount] = operation;
            ++_operationCount;
        }

        /**
         * @brief 操作を削除する
         * @param operation Operation * 削除する操作 deleteはしない
         * @return true 削除できた
         * @return false 削除できなかった
         */
        bool removeOperation(Operation * operation) {
            uint8_t removeIndex = _operationCount;
            for (uint8_t i = 0; i < _operationCount; ++i) {
                if (*_operations[i] == *operation) {
                    removeIndex = i;
                }
            }
            if (removeIndex == _operationCount) {
                return false;
            }
            for (uint8_t i = removeIndex; i < _operationCount - 1; ++i) {
                _operations[i] = _operations[i + 1];
            }
            _operations[_operationCount - 1] = nullptr;
            --_operationCount;
            return true;
        }
    }; // class PS4Controller<PS4Connection::usb>

    /**
     * @brief 操作を登録できるPS4コントローラーの無線接続版
     * @tparam ssr::PS4Connection::bluetooth Bluetooth通信での無線接続
     * @note PS4Operation型のポインタを渡すことで新たな操作を登録する
     */
    template<> class PS4Controller<PS4Connection::bluetooth> {
    public:
        /**
         * @brief 操作を表現するオブジェクトの型
         */
        using Operation = PS4Operation;

    private:
        /**
         * @brief 現在登録されている操作の数
         */
        uint8_t _operationCount;
        /**
         * @brief 現在登録されている操作の配列
         */
        Operation ** _operations;
        /**
         * @brief 使用するコントローラー
         */
        ssr::PS4<PS4Connection::bluetooth> _ps4;

    public:
        /**
         * @brief 登録できる操作の最大数 最初に設定したら変更不可能
         */
        const uint8_t operationCapacity;

        /**
         * @brief 初期化子
         * @param pair bool 最初の接続時にtrueを指定する デフォルトはfalse
         * @param operationCapacity uint8_t 登録できる操作の最大数 最初に設定したら変更不可能
         */
        PS4Controller(bool pair = false, uint8_t operationCapacity = 16)
        : _operationCount(0), _operations(nullptr), _ps4(pair), operationCapacity(operationCapacity)
        {
            _operations = new Operation*[this->operationCapacity];
            for (uint8_t i = 0; i < this->operationCapacity; ++i) {
                _operations[i] = nullptr;
            }
        }

        /**
         * @brief Destroy the PS4Controller object
         */
        ~PS4Controller() {
            if (_operations == NULL || _operations == nullptr) return;
            delete[] _operations;
        }

        /**
         * @brief コントローラーを初期化する
         * @return int 初期化に成功したら0 失敗したら-1
         * @warning 必ずsetup()で呼び出して返り値を確認すること
         */
        int begin() {
            return _ps4.begin();
        }

        /**
         * @brief コントローラーに接続できているか確認する
         * @return bool 接続できていたらtrue
         */
        bool connected() {
            return _ps4.connected();
        }

        /**
         * @brief 最新の情報に更新して、登録された操作を実行する
         * @warning 毎loop()ごとに呼び出すこと
         */
        void update() {
            _ps4.update();
            if (!connected()) return;
            PS4Value value{};
            _ps4.read(&value);
            for (uint8_t i = 0; i < _operationCount; ++i) {
                _operations[i]->operate(value);
            }
        }

        /**
         * @brief 操作を追加する
         * @param operation Operation * 操作を表現するオブジェクトのポインタ あくまでポインタを登録するだけなので注意
         */
        void addOperation(Operation * operation) {
            _operations[_operationCount] = operation;
            ++_operationCount;
        }

        /**
         * @brief 操作を削除する
         * @param operation Operation * 削除する操作
         * @return true 削除された
         * @return false 削除できなかった
         */
        bool removeOperation(Operation * operation) {
            uint8_t removeIndex = _operationCount;
            for (uint8_t i = 0; i < _operationCount; ++i) {
                if (*_operations[i] == *operation) {
                    removeIndex = i;
                }
            }
            if (removeIndex == _operationCount) {
                return false;
            }
            for (uint8_t i = removeIndex; i < _operationCount - 1; ++i) {
                _operations[i] = _operations[i + 1];
            }
            _operations[_operationCount - 1] = nullptr;
            --_operationCount;
            return true;
        }
    }; // class PS4Controller<PS4Connection::bluetooth>

    /**
     * @brief USB接続で操作を登録できるPS4コントローラー
     */
    using PS4Controller_USB = PS4Controller<PS4Connection::usb>;

    /**
     * @brief Bluetooth接続で操作を登録できるPS4コントローラー
     */
    using PS4Controller_Bluetooth = PS4Controller<PS4Connection::bluetooth>;
} // namespace ssr

#endif /* SSR_PS4_CONTROLLER_HPP */
