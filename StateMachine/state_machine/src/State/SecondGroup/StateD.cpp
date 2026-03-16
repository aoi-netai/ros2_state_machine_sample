#include "StateHeaders.hpp"

StateError StateD::init(StateContext& context) {
    
    return StateError::NONE;
}

StateResult StateD::update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_E, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_D, StateError::NONE};
}
