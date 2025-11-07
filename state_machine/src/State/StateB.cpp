#include "common/StateHeaders.hpp"

StateResult StateB::onUpdate(StateContext& context) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;
    
    // State Bの処理（必要に応じて実装）
    // 例: context.instances.your_instance->someMethod();

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_C, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}

StateError StateB::onEnter(StateContext& context) {

    return StateError::NONE;
}

StateError StateB::onExit(StateContext& context) {
    return StateError::NONE;
}
