
# ROS2 State Machine

## 最小限の実行コマンド

```bash
cd /workspaces/ros2_docker_test && source /opt/ros/humble/setup.bash && colcon build --packages-select state_machine && source install/setup.bash && ros2 run state_machine state_machine_node
```

## ステップバイステップ実行

### 1. ビルド
```bash
cd /workspaces/ros2_docker_test
source /opt/ros/humble/setup.bash
colcon build --packages-select state_machine
```

### 2. 環境セットアップ
```bash
source install/setup.bash
```

### 3. ノード実行
```bash
ros2 run state_machine state_machine_node
```

## クリーンビルド
```bash
cd /workspaces/ros2_docker_test && rm -rf build install log && source /opt/ros/humble/setup.bash && colcon build --packages-select state_machine
```

## 直接実行（ビルド後）
```bash
/workspaces/ros2_docker_test/install/state_machine/lib/state_machine/state_machine_node
```
