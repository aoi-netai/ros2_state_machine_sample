#include "StateManager.hpp"
#include "../State/common/StateHeaders.hpp"
#include <string>

// コンストラクタ
StateManager::StateManager(StateID init_state_id){

	// 移入された状態を current_state に設定
	current_state = createState(init_state_id);

	// enter を呼ぶ
	if (current_state) {

		current_state->enter(state_context);
	}

}
// 状態遷移
void StateManager::changeState(std::unique_ptr<StateInterface> new_state) {

	// 現在の状態の終了処理（exit関数の呼び出し）
	if (current_state) {

		current_state->exit(state_context);
	}

	// 新しい状態クラスのオブジェクトのポインタを代入
	current_state = std::move(new_state);

	// 新しい状態の開始処理（enter関数の呼び出し）
	if (current_state) {

		current_state->enter(state_context);

		state_context.state_change_count++;
	}
}

// メインループの更新処理
StateManagerStatus StateManager::update() {

	StateManagerStatus status;
	status.current_state = current_state ? current_state->getStateID() : StateID::STATE_A;
	status.has_state_changed = false;
	status.error_code = StateManagerErrorCode::SUCCESS;

	// ポインタが無効な場合は処理しない
	if(!current_state) {

		status.error_code = StateManagerErrorCode::CRITICAL_NULL_STATE;
		return status;
	}

	// 現在状態の更新処理
	StateResult result = current_state->update(state_context);

	// 状態遷移が発生した場合
	if (result.state_change == StateChange::STATE_CHANGE) {

		// 状態を変更
		changeState(createState(result.next_state));
		status.has_state_changed = true;
		status.current_state = current_state->getStateID();
	}

	return status;
}

// 状態IDから状態クラスのオブジェクトを生成
std::unique_ptr<StateInterface> StateManager::createState(StateID state_id) {

	switch (state_id) { 

		case StateID::STATE_A:
			return std::make_unique<StateA>();

		case StateID::STATE_B:
			return std::make_unique<StateB>();

		case StateID::STATE_C:
			return std::make_unique<StateC>();

		default:
			return nullptr;
	}
}