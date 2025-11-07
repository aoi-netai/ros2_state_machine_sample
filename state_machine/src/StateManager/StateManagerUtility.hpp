#ifndef STATE_MANAGER_UTILITY_HPP
#define STATE_MANAGER_UTILITY_HPP

#include <cstdint>
#include "../State/common/StateUtility.hpp"

// エラーコード（従来のStateManagerStatusの値を流用）
enum class StateManagerErrorCode : uint8_t {

    // 正常系
    SUCCESS = 0,                           // ✅ 正常に処理完了
    
    // 復旧可能な問題（処理は続行）
    WARNING_STATE_NOT_CHANGED = 100,        // ⚠️ 状態遷移が発生しなかった
    WARNING_INVALID_STATE = 101,            // ⚠️ 無効な状態ID
    
    // 致命的なエラー（システム停止すべき）
    CRITICAL_NULL_STATE = 200,             // 🔴 current_state が nullptr
    CRITICAL_STATE_CREATION_FAILED = 201,  // 🔴 状態生成に失敗
    CRITICAL_ENTER_FAILED = 202,           // 🔴 enter() が失敗
    CRITICAL_EXIT_FAILED = 203,            // 🔴 exit() が失敗
};

// StateManagerの実行結果を表す構造体
struct StateManagerStatus {
    
    StateID current_state;                  // 現在の状態ID
    bool has_state_changed = false;         // 状態遷移が発生したか
    StateManagerErrorCode error_code = StateManagerErrorCode::SUCCESS;  // エラーコード
};


// ステータスの重大度を判定するヘルパー関数
inline bool isCritical(StateManagerErrorCode error_code) {

    return static_cast<uint8_t>(error_code) >= 200;
}

inline bool isWarning(StateManagerErrorCode error_code) {

    uint8_t code = static_cast<uint8_t>(error_code);
    return code >= 10 && code < 200;
}

// エラーコードを文字列で取得するヘルパー関数
inline const char* StateManagerErrorCodeToString(StateManagerErrorCode error_code) {

    switch (error_code) {

        case StateManagerErrorCode::SUCCESS:
            return "SUCCESS";

        case StateManagerErrorCode::WARNING_STATE_NOT_CHANGED:
            return "WARNING_STATE_NOT_CHANGED";

        case StateManagerErrorCode::WARNING_INVALID_STATE:
            return "WARNING_INVALID_STATE";

        case StateManagerErrorCode::CRITICAL_NULL_STATE:
            return "CRITICAL_NULL_STATE";

        case StateManagerErrorCode::CRITICAL_STATE_CREATION_FAILED:
            return "CRITICAL_STATE_CREATION_FAILED";

        case StateManagerErrorCode::CRITICAL_ENTER_FAILED:
            return "CRITICAL_ENTER_FAILED";

        case StateManagerErrorCode::CRITICAL_EXIT_FAILED:
            return "CRITICAL_EXIT_FAILED";

        default:
            return "UNKNOWN";
    }
}

#endif // STATE_MANAGER_UTILITY_HPP