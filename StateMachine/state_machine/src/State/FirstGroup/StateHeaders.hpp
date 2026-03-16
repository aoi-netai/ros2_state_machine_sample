/* FirstGroup/StateHeaders.hpp
* 
* FirstGroup に属する状態（StateA, StateB, StateC）のヘッダーファイルをまとめたもの
*/

#ifndef FIRSTGROUP_STATEHEADERS_HPP
#define FIRSTGROUP_STATEHEADERS_HPP

#include "../../StateInterface/StateInterface.hpp"
#include "../../common/StateUtility.hpp"
#include "../../common/StateContext.hpp"

class StateA : public StateInterface {

    protected:
        StateError init(StateContext& context) override;
        StateResult update(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_A; }
};

class StateB : public StateInterface {

    protected:
        StateError init(StateContext& context) override;
        StateResult update(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_B; }
};

class StateC : public StateInterface {

    protected:
        StateError init(StateContext& context) override;
        StateResult update(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_C; }
};

#endif // FIRSTGROUP_STATEHEADERS_HPP
