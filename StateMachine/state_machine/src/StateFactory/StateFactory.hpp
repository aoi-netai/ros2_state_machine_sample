#ifndef STATE_FACTORY_HPP
#define STATE_FACTORY_HPP

#include <memory>
#include "../State/FirstGroup/StateHeaders.hpp"
#include "../State/SecondGroup/StateHeaders.hpp"

/* StateFactory.hpp
*
* 状態IDから状態クラスのオブジェクトを生成するファクトリクラス
* StateManager から状態生成ロジックを分離して、責任を明確にする
*/

class StateFactory {

    public:

        // 状態IDから状態クラスのオブジェクトを生成
        static std::unique_ptr<StateInterface> createState(StateID state_id) {

            switch (state_id) { 

                case StateID::STATE_A:
                    return std::make_unique<StateA>();

                case StateID::STATE_B:
                    return std::make_unique<StateB>();

                case StateID::STATE_C:
                    return std::make_unique<StateC>();

                case StateID::STATE_D:
                    return std::make_unique<StateD>();

                case StateID::STATE_E:
                    return std::make_unique<StateE>();

                default:
                    return nullptr;
            }
        }
};

#endif // STATE_FACTORY_HPP
