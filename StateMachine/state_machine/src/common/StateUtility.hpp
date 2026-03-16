#ifndef STATE_ID_HPP
#define STATE_ID_HPP

#include <cstdint>

// 状態IDの定義
enum class StateID : uint8_t {

    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D,
    STATE_E,
};

// 状態エラー
enum class StateError : uint8_t {

    NONE = 0,
    SOME_CRITICAL_ERROR = 255,
};

// 状態遷移の有無
enum class StateChange : uint8_t {

    NO_STATE_CHANGE = 0,
    STATE_CHANGE = 1,
};

// 状態更新の結果を格納する構造体
struct StateResult {

    StateChange state_change = StateChange::NO_STATE_CHANGE;
    StateID next_state = StateID::STATE_A;
    StateError error = StateError::NONE;
};

// StateIDを文字列に変換するヘルパー関数
inline const char* StateIDToString(StateID state_id) {

    switch (state_id) {
        case StateID::STATE_A:
            return "STATE_A";
        case StateID::STATE_B:
            return "STATE_B";
        case StateID::STATE_C:
            return "STATE_C";
        case StateID::STATE_D:
            return "STATE_D";
        case StateID::STATE_E:
            return "STATE_E";
        default:
            return "UNKNOWN";
    }
}
    
#endif // STATE_ID_HPP
