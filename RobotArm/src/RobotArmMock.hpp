#ifndef ROBOT_ARM_MOCK_HPP
#define ROBOT_ARM_MOCK_HPP

#include <vector>
#include <cmath>

enum class ArmCommand {
    INIT,
    HOME,
    MOVE,
    SHUTDOWN,
};

struct ArmState {
    bool initialized;
    bool at_home;
    std::vector<double> joint_angles;
};

class RobotArmMock {
public:
    RobotArmMock();
    ~RobotArmMock() = default;
    
    void executeCommand(ArmCommand cmd);
    void init();
    void goHome();
    void move(const std::vector<double>& target_angles);
    void shutdown();
    
    void forwardKinematics(double& x, double& y, double& z) const;
    
    ArmState getState() const { return state_; }
    bool isReady() const { return state_.initialized && state_.at_home; }
    
private:
    ArmState state_;
    static constexpr int NUM_JOINTS = 3;
    static constexpr double L1 = 0.3;
    static constexpr double L2 = 0.3;
    static constexpr double L3 = 0.2;
    
    std::vector<double> home_angles_ = {0.0, -1.57, 1.57};
};

#endif  // ROBOT_ARM_MOCK_HPP
