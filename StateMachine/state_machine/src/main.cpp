#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>
#include <memory>
#include <cstdio>
#include "StateManager/StateManager.hpp"

// ROS2ノードクラス
class StateMachineNode : public rclcpp::Node {

    public:

        StateMachineNode() : Node("state_machine_node") {

            state_manager_ = std::make_unique<StateManager>(StateID::STATE_A);

            // ログパブリッシャーを作成
            log_publisher_ = this->create_publisher<std_msgs::msg::String>(
                "state_machine_log",
                rclcpp::SensorDataQoS()
            );

            timer_ = this->create_wall_timer(
                std::chrono::milliseconds(2000),
                std::bind(&StateMachineNode::timerCallback, this)
            );
        }

    private:

        void timerCallback() {

            // StateManagerの更新
            state_manager_->update();
        }

        std::unique_ptr<StateManager> state_manager_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr log_publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};

// メイン関数
int main(int argc, char* argv[]) {

    printf("Starting State Machine Node...\n");
    rclcpp::init(argc, argv);

    // ノードの作成と実行
    auto node = std::make_shared<StateMachineNode>();
    rclcpp::spin(node);

    // ROS2 のシャットダウン
    rclcpp::shutdown();

    return 0;
}