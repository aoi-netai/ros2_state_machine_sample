## コンパイル

### シンボリックリンクを使った高速ビルド（推奨）
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
source /opt/ros/humble/setup.bash
colcon build --symlink-install
```

### 特定のパッケージのみビルド
```bash
# state_machineのみ
colcon build --packages-select state_machine

# robot_armのみ
colcon build --packages-select robot_arm

# log_receiverのみ
colcon build --packages-select log_receiver

# bringupのみ
colcon build --packages-select bringup

# 複数パッケージを指定
colcon build --packages-select state_machine robot_arm
```

### クリーンビルド
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
rm -rf build install log
source /opt/ros/humble/setup.bash
colcon build --symlink-install
```

## 起動

### 一括起動
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
./run_bringup.bash
```

### state_machine
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
./run_state_machine.bash
```

### robot_arm
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
./run_robot_arm.bash
```

### log_reciever
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
./run_log_receiver.bash
```