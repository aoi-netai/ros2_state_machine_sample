/* SecondGroup/StateHeaders.hpp
* 
* SecondGroup に属する状態（StateD, StateE）のヘッダーファイルをまとめたもの
*/

#ifndef SECONDGROUP_STATEHEADERS_HPP
#define SECONDGROUP_STATEHEADERS_HPP

#include "../../StateInterface/StateInterface.hpp"
#include "../../common/StateUtility.hpp"
#include "../../common/StateContext.hpp"

class StateD : public StateInterface {

    protected:
        StateError init(StateContext& context) override;
        StateResult update(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_D; }
};

class StateE : public StateInterface {

    protected:
        StateError init(StateContext& context) override;
        StateResult update(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_E; }
};

#endif // SECONDGROUP_STATEHEADERS_HPP
