#!/bin/bash
# 全パッケージの環境をセットアップするスクリプト

# ROS2のベース環境をセットアップ
source /opt/ros/humble/setup.bash

# 各パッケージを個別にセットアップ
WORKSPACE_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 各パッケージのsetup.bashを順番にsource
if [ -f "$WORKSPACE_ROOT/install/log_receiver/share/log_receiver/package.bash" ]; then
    source "$WORKSPACE_ROOT/install/log_receiver/share/log_receiver/package.bash"
fi

if [ -f "$WORKSPACE_ROOT/install/robot_arm/share/robot_arm/package.bash" ]; then
    source "$WORKSPACE_ROOT/install/robot_arm/share/robot_arm/package.bash"
fi

if [ -f "$WORKSPACE_ROOT/install/state_machine/share/state_machine/package.bash" ]; then
    source "$WORKSPACE_ROOT/install/state_machine/share/state_machine/package.bash"
fi

if [ -f "$WORKSPACE_ROOT/install/bringup/share/bringup/package.bash" ]; then
    source "$WORKSPACE_ROOT/install/bringup/share/bringup/package.bash"
fi

# 手動でAMENT_PREFIX_PATHを設定
export AMENT_PREFIX_PATH="$WORKSPACE_ROOT/install/state_machine:$WORKSPACE_ROOT/install/robot_arm:$WORKSPACE_ROOT/install/log_receiver:$WORKSPACE_ROOT/install/bringup:$AMENT_PREFIX_PATH"

echo "環境セットアップ完了"
echo "AMENT_PREFIX_PATH=$AMENT_PREFIX_PATH"
