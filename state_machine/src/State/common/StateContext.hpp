#ifndef STATECONTEXT_HPP
#define STATECONTEXT_HPP

#include <cstdint>
#include <memory>
#include <optional>

// 使用するインスタンス
struct Instances{
    // 必要に応じてここにインスタンスを追加
    // 例: std::optional<YourClass> your_instance;
};

// 状態間で共有する変数
struct StateContext {
    
    uint16_t state_change_count = 0;
    Instances instances;
};

#endif // STATECONTEXT_HPP
