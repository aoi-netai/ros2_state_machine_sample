#include "StateHeaders.hpp"

StateError StateA::init(StateContext& context) {

    return StateError::NONE;
}

StateResult StateA::update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    // 処理を1回したら状態をBに変更
    return {StateChange::STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}
