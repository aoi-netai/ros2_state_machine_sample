#include "StateHeaders.hpp"

StateError StateB::init(StateContext& context) {

    return StateError::NONE;
}

StateResult StateB::update(StateContext& context) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;
    
    if(loop_counter > 1) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_C, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}
