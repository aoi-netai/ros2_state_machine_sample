#include "common/StateHeaders.hpp"

StateResult StateC::onUpdate(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_B, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_C, StateError::NONE};
}

StateError StateC::onEnter(StateContext& context) {


    return StateError::NONE;
}

StateError StateC::onExit(StateContext& context) {

    return StateError::NONE;
}
