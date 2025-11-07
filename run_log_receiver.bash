#!/bin/bash
# Log Receiver ノード起動スクリプト

WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 環境セットアップ
source /opt/ros/humble/setup.bash
source "$WORKSPACE_ROOT/setup_all.bash"

# Log Receiver ノードを起動
echo "Starting Log Receiver Node..."
ros2 run log_receiver log_receiver_node
