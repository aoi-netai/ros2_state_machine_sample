# Robot Arm Mock Node

独立したロボットアーム制御ノードのモック実装です。

## 機能

- **INIT**: アーム初期化
- **HOME**: ホーム位置へ移動
- **MOVE**: 指定位置へ移動
- **SHUTDOWN**: シャットダウン

## 実行方法

```bash
cd ROS2_STATE_MACHINE/RobotArm
. /opt/ros/humble/setup.bash
colcon build --build-base build --install-base install
source install/setup.bash
./install/robot_arm/lib/robot_arm/robot_arm_node
```

## トピック

- `/robot_arm/state` - アーム状態情報
- `/robot_arm/end_effector_pose` - エンドエフェクタ位置 (geometry_msgs/PoseStamped)

## デモ動作

3秒ごとに以下を実行します：

1. INIT (初期化)
2. HOME (ホーム位置へ)
3. MOVE (目標位置へ移動)
4. SHUTDOWN (終了)
