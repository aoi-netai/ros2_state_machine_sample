#include "common/StateHeaders.hpp"
#include <memory>
#include <cstdio>

StateResult StateA::onUpdate(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    // 初期化処理（必要に応じて実装）
    // 例: context.instances.your_instance.emplace(初期値);

    // 処理を1回したら状態をBに変更
    return {StateChange::STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}

StateError StateA::onEnter(StateContext& context) {

    return StateError::NONE;
}

StateError StateA::onExit(StateContext& context) {

    return StateError::NONE;
}