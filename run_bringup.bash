#!/bin/bash
# Bringup - 全ノード同時起動スクリプト

WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 環境セットアップ
source /opt/ros/humble/setup.bash
source "$WORKSPACE_ROOT/setup_all.bash"

# 全ノードを同時起動
echo "Starting All Nodes via Bringup..."
ros2 launch bringup system_bringup.launch.py
