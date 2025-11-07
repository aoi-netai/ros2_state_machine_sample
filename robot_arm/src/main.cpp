#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <chrono>
#include <memory>
#include "RobotArmMock.hpp"

class RobotArmNode : public rclcpp::Node {
public:
    RobotArmNode() : Node("robot_arm_node") {
        arm_ = std::make_unique<RobotArmMock>();
        
        // 状態パブリッシャー
        state_publisher_ = this->create_publisher<std_msgs::msg::String>(
            "robot_arm/state",
            rclcpp::SensorDataQoS()
        );
        
        // エンドエフェクタ位置パブリッシャー
        pose_publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(
            "robot_arm/end_effector_pose",
            rclcpp::SensorDataQoS()
        );
        
        // ライフサイクルコマンド実行
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(3000),
            std::bind(&RobotArmNode::timerCallback, this)
        );
        
        RCLCPP_INFO(this->get_logger(), "Robot Arm Node started");
    }
    
private:
    void timerCallback() {
        static int step = 0;
        
        switch (step) {
            case 0:
                RCLCPP_INFO(this->get_logger(), "Step 1: INIT");
                arm_->executeCommand(ArmCommand::INIT);
                break;
            case 1:
                RCLCPP_INFO(this->get_logger(), "Step 2: HOME");
                arm_->executeCommand(ArmCommand::HOME);
                break;
            case 2:
                RCLCPP_INFO(this->get_logger(), "Step 3: MOVE");
                arm_->executeCommand(ArmCommand::MOVE);
                break;
            case 3:
                RCLCPP_INFO(this->get_logger(), "Step 4: SHUTDOWN");
                arm_->executeCommand(ArmCommand::SHUTDOWN);
                rclcpp::shutdown();
                return;
        }
        
        step++;
        publishState();
        publishPose();
    }
    
    void publishState() {
        auto msg = std_msgs::msg::String();
        ArmState state = arm_->getState();
        msg.data = "[State] Initialized: " + std::string(state.initialized ? "true" : "false") +
                   ", At Home: " + std::string(state.at_home ? "true" : "false");
        state_publisher_->publish(msg);
    }
    
    void publishPose() {
        double x, y, z;
        ArmState state = arm_->getState();
        
        // 簡易的なFK計算
        double theta1 = state.joint_angles[0];
        double theta2 = state.joint_angles[1];
        double theta3 = state.joint_angles[2];
        double temp = theta1 + theta2 + theta3;
        x = 0.3 * cos(theta1) + 0.3 * cos(theta1 + theta2) + 0.2 * cos(temp);
        y = 0.3 * sin(theta1) + 0.3 * sin(theta1 + theta2) + 0.2 * sin(temp);
        z = 0.0;
        
        auto pose_msg = geometry_msgs::msg::PoseStamped();
        pose_msg.header.frame_id = "base_link";
        pose_msg.header.stamp = this->now();
        pose_msg.pose.position.x = x;
        pose_msg.pose.position.y = y;
        pose_msg.pose.position.z = z;
        pose_msg.pose.orientation.w = 1.0;
        
        pose_publisher_->publish(pose_msg);
    }
    
    std::unique_ptr<RobotArmMock> arm_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotArmNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
