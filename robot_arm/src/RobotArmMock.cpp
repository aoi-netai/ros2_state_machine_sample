#include "RobotArmMock.hpp"
#include <cstdio>

RobotArmMock::RobotArmMock() {
    state_.initialized = false;
    state_.at_home = false;
    state_.joint_angles = std::vector<double>(NUM_JOINTS, 0.0);
}

void RobotArmMock::executeCommand(ArmCommand cmd) {
    switch (cmd) {
        case ArmCommand::INIT:
            init();
            break;
        case ArmCommand::HOME:
            goHome();
            break;
        case ArmCommand::MOVE:
            move({0.5, -1.0, 0.8});
            break;
        case ArmCommand::SHUTDOWN:
            shutdown();
            break;
    }
}

void RobotArmMock::init() {
    printf("[RobotArmMock] Initializing...\n");
    state_.initialized = true;
    state_.joint_angles = std::vector<double>(NUM_JOINTS, 0.0);
    printf("[RobotArmMock] Initialization complete\n");
}

void RobotArmMock::goHome() {
    printf("[RobotArmMock] Moving to home position...\n");
    state_.joint_angles = home_angles_;
    state_.at_home = true;
    
    double x, y, z;
    forwardKinematics(x, y, z);
    printf("[RobotArmMock] Home position reached: (%.2f, %.2f, %.2f)\n", x, y, z);
}

void RobotArmMock::move(const std::vector<double>& target_angles) {
    if (!state_.initialized) {
        printf("[RobotArmMock] ERROR: Arm not initialized\n");
        return;
    }
    
    printf("[RobotArmMock] Moving to target angles...\n");
    state_.joint_angles = target_angles;
    state_.at_home = false;
    
    double x, y, z;
    forwardKinematics(x, y, z);
    printf("[RobotArmMock] Move complete: (%.2f, %.2f, %.2f)\n", x, y, z);
}

void RobotArmMock::shutdown() {
    printf("[RobotArmMock] Shutting down...\n");
    state_.initialized = false;
    state_.at_home = false;
    state_.joint_angles = std::vector<double>(NUM_JOINTS, 0.0);
}

void RobotArmMock::forwardKinematics(double& x, double& y, double& z) const {
    double theta1 = state_.joint_angles[0];
    double theta2 = state_.joint_angles[1];
    double theta3 = state_.joint_angles[2];
    
    double temp = theta1 + theta2 + theta3;
    x = L1 * cos(theta1) + L2 * cos(theta1 + theta2) + L3 * cos(temp);
    y = L1 * sin(theta1) + L2 * sin(theta1 + theta2) + L3 * sin(temp);
    z = 0.0;
}
