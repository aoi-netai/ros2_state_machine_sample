

## ファイル（ノード）について

### 前提条件
- ROS2 Humble がインストール済みであること
- このリポジトリをクローン後、リポジトリルートから実行してください

### 実行方法

**注意: LogReceiver は StateManager よりも先に起動してください。**

#### 1. LogReceiver（ターミナル 1）StateManagerの現在状態を表示
```bash
cd ROS2_STATE_MACHINE/LogReceiver/log_receiver
. /opt/ros/humble/setup.bash
colcon build --build-base build --install-base install
source install/setup.bash
./install/log_receiver/lib/log_receiver/log_receiver_node
```

#### 2. StateManager（ターミナル 2）状態管理や処理を行う部分
```bash
cd ROS2_STATE_MACHINE/StateMachine/state_machine
. /opt/ros/humble/setup.bash
colcon build --build-base build --install-base install
source install/setup.bash
./install/state_machine/lib/state_machine/state_machine_node
```

#### 3. トピック確認（ターミナル 3 - オプション）
```bash
. /opt/ros/humble/setup.bash
ros2 topic list
ros2 topic echo /state_machine_log
```
