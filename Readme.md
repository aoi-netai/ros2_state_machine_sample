cd /mnt/d/GitLocal/vscode/ros2_state_machine

# 新しいセットアップスクリプトを使用
source setup_all.bash

# パッケージが認識されているか確認
ros2 pkg list | grep -E 'state_machine|robot_arm|log_receiver|bringup'

# システムを起動
ros2 launch bringup system_bringup.launch.py