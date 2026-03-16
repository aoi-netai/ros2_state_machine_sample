/* StateInterface.hpp
* 
* 各状態のインターフェース（基底クラス）を定義しています
*/

#ifndef INC_STATE_INTERFACE_HPP_
#define INC_STATE_INTERFACE_HPP_

#include "../common/StateUtility.hpp"
#include "../common/StateContext.hpp"

class StateManager;

// ステートのインターフェース
class StateInterface {

    public:

        virtual ~StateInterface() = default;

        // 状態初期化
        virtual StateError init(StateContext& context) = 0;

        // 状態更新用
        virtual StateResult update(StateContext& context) = 0;

        // 状態IDの取得
        virtual StateID getStateID() const = 0;
};

#endif // INC_STATE_INTERFACE_HPP_
