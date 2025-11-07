# ROS2 State Machine Node

## 前提条件
- ROS2 がインストール済み
- `colcon` がインストール済み

## ビルド手順

### 1. ワークスペースルートに移動
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine
```

### 2. ビルド実行
```bash
colcon build --packages-select state_machine
```

### 3. セットアップスクリプトを実行
```bash
source install/setup.bash
```

## 実行

```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine
. /opt/ros/humble/setup.bash
./install/state_machine/lib/state_machine/state_machine_node
```

## トラブルシューティング

### `Package 'state_machine' not found` エラーが出る場合

1. **セットアップスクリプトが実行されているか確認**
   ```bash
   echo $ROS_PACKAGE_PATH
   ```

2. **install ディレクトリが存在するか確認**
   ```bash
   ls -la install/
   ```

3. **新しいターミナルで実行（セットアップを再実行）**
   ```bash
   cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine
   source install/setup.bash
   ros2 run state_machine state_machine_node
   ```

4. **ビルドに失敗した場合はクリーンビルド**
   ```bash
   cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine
   rm -rf build install log
   colcon build --packages-select state_machine
   source install/setup.bash
   ```

## プロジェクト構成
- **パッケージ名**: state_machine
- **実行ファイル**: state_machine_node
- **言語**: C++ (ROS2 / rclcpp)
- **ロジック**: State Machine パターンで複数の状態を管理
