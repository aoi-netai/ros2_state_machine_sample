#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <memory>

// ログレシーバーノードクラス
class LogReceiverNode : public rclcpp::Node {
public:
    LogReceiverNode() : Node("log_receiver_node") {
        RCLCPP_INFO(this->get_logger(), "LogReceiver initialized");

        // トピックのサブスクライバーを作成
        // "state_machine_log" トピックから std_msgs::msg::String メッセージを受信
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "state_machine_log",
            rclcpp::SensorDataQoS(),
            std::bind(&LogReceiverNode::topic_callback, this, std::placeholders::_1)
        );

        RCLCPP_INFO(this->get_logger(), "Subscribed to 'state_machine_log' topic");
    }

private:
    // トピックコールバック関数
    void topic_callback(const std_msgs::msg::String & msg) const {
        // 受信したメッセージをログに出力
        RCLCPP_INFO(this->get_logger(), "[STATE_MACHINE] %s", msg.data.c_str());
    }

    // サブスクリプション
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

// メイン関数
int main(int argc, char* argv[]) {
    
    // ROS2 の初期化
    rclcpp::init(argc, argv);

    // ノードの作成と実行
    auto node = std::make_shared<LogReceiverNode>();
    rclcpp::spin(node);

    // ROS2 のシャットダウン
    rclcpp::shutdown();

    return 0;
}
