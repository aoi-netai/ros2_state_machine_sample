#include "StateManager.hpp"
#include <string>

// コンストラクタ
StateManager::StateManager(StateID init_state_id){

	// 移入された状態を current_state に設定
	current_state = StateFactory::createState(init_state_id);

	// init を呼ぶ
	if (current_state) {

		current_state->init(state_context);
	}

	printf("[StateManager] Initialized with state: %s\n", StateIDToString(init_state_id));
}

// 状態遷移
void StateManager::changeState(std::unique_ptr<StateInterface> new_state) {

	// 新しい状態クラスのオブジェクトのポインタを代入
	current_state = std::move(new_state);

	// ログを出力
	printf("[StateManager] State changed to: %s\n", StateIDToString(current_state->getStateID()));

	// 新しい状態の初期化処理（init関数の呼び出し）
	if (current_state) {

		current_state->init(state_context);
		state_context.state_change_count++;
	}
}

// メインループの更新処理
void StateManager::update() {

	// ポインタが無効な場合は処理しない
	if(!current_state) {

		return;
	}

	// 現在状態の更新処理
	StateResult result = current_state->update(state_context);

	// 状態遷移が発生した場合
	if (result.state_change == StateChange::STATE_CHANGE) {

		// 状態を変更
		changeState(StateFactory::createState(result.next_state));
	}
}
