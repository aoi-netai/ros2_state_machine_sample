# ROS2 Log Receiver Node# ROS2 Log Receiver Node



## 概要## 前提条件

LogReceiverNode は、同じ LAN 内の state_machine ノードから `state_machine_log` トピック経由でログメッセージを受信し、ログとして出力するノードです。- ROS2 がインストール済み

- `colcon` がインストール済み

## 前提条件

- ROS2 がインストール済み## ビルド手順

- `colcon` がインストール済み

### 1. ワークスペースルートに移動

## ビルド手順```bash

cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine

### 1. LogReceiver ワークスペースルートに移動```

```bash

cd /mnt/d/GitLocal/vscode/ros2_state_machine/LogReceiver### 2. ビルド実行

``````bash

colcon build --packages-select log_receiver

### 2. ROS2 環境をセットアップ```

```bash

. /opt/ros/humble/setup.bash### 3. セットアップスクリプトを実行

``````bash

source install/setup.bash

### 3. ビルド実行```

```bash

colcon build --packages-select log_receiver## 実行

```

```bash

### 4. セットアップスクリプトを実行cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine

```bash. /opt/ros/humble/setup.bash

source install/setup.bash./install/log_receiver/lib/log_receiver/log_receiver_node

``````



## 実行## トラブルシューティング



```bash### `Package 'log_receiver' not found` エラーが出る場合

cd /mnt/d/GitLocal/vscode/ros2_state_machine/LogReceiver

. /opt/ros/humble/setup.bash1. **セットアップスクリプトが実行されているか確認**

./install/log_receiver/lib/log_receiver/log_receiver_node   ```bash

```   echo $ROS_PACKAGE_PATH

   ```

## 複数 PC での運用

2. **install ディレクトリが存在するか確認**

### PC1（State Machine ノード）   ```bash

```bash   ls -la install/

cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine   ```

. /opt/ros/humble/setup.bash

source install/setup.bash3. **新しいターミナルで実行（セットアップを再実行）**

./install/state_machine/lib/state_machine/state_machine_node   ```bash

```   cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine

   source install/setup.bash

### PC2（Log Receiver ノード）   ros2 run log_receiver log_receiver_node

```bash   ```

cd /mnt/d/GitLocal/vscode/ros2_state_machine/LogReceiver

. /opt/ros/humble/setup.bash4. **ビルドに失敗した場合はクリーンビルド**

source install/setup.bash   ```bash

./install/log_receiver/lib/log_receiver/log_receiver_node   cd /mnt/d/GitLocal/vscode/ros2_state_machine/StateMachine

```   rm -rf build install log

   colcon build --packages-select log_receiver

**注意:** 両 PC が同じ LAN に接続され、ROS_DOMAIN_ID が同じである必要があります。   source install/setup.bash

   ```

## トラブルシューティング

## プロジェクト構成

### `Package 'log_receiver' not found` エラーが出る場合- **パッケージ名**: log_receiver

- **実行ファイル**: log_receiver_node

1. **セットアップスクリプトが実行されているか確認**- **言語**: C++ (ROS2 / rclcpp)

   ```bash- **用途**: 同じ LAN 内のログを受信・管理

   echo $ROS_PACKAGE_PATH
   ```

2. **install ディレクトリが存在するか確認**
   ```bash
   ls -la install/
   ```

3. **クリーンビルド**
   ```bash
   cd /mnt/d/GitLocal/vscode/ros2_state_machine/LogReceiver
   rm -rf build install log
   . /opt/ros/humble/setup.bash
   colcon build --packages-select log_receiver
   source install/setup.bash
   ```

## プロジェクト構成
- **パッケージ名**: log_receiver
- **実行ファイル**: log_receiver_node
- **言語**: C++ (ROS2 / rclcpp)
- **機能**: `state_machine_log` トピックをサブスクライブしてログを受信・表示
