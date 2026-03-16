#include "StateHeaders.hpp"

StateError StateE::init(StateContext& context) {
    
    return StateError::NONE;
}

StateResult StateE::update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_A, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_E, StateError::NONE};
}
