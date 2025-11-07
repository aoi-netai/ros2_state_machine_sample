#!/bin/bash
# Robot Arm ノード起動スクリプト

WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 環境セットアップ
source /opt/ros/humble/setup.bash
source "$WORKSPACE_ROOT/setup_all.bash"

# Robot Arm ノードを起動
echo "Starting Robot Arm Node..."
ros2 run robot_arm robot_arm_node
