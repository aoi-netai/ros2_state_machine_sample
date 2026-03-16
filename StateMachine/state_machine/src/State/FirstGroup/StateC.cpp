#include "StateHeaders.hpp"

StateError StateC::init(StateContext& context) {
    
    return StateError::NONE;
}

StateResult StateC::update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_D, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_C, StateError::NONE};
}
