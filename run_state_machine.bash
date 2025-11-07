#!/bin/bash
# State Machine ノード起動スクリプト

WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 環境セットアップ
source /opt/ros/humble/setup.bash
source "$WORKSPACE_ROOT/setup_all.bash"

# State Machine ノードを起動
echo "Starting State Machine Node..."
ros2 run state_machine state_machine_node
