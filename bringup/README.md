
# ROS2 State Machine System - Bringup Package

このパッケージは、ROS2 State Machineシステムの3つのノードを同時に起動するためのbringupパッケージです。

## 概要

以下の3つのノードを一度に起動できます：

1. **state_machine_node** - ステートマシン制御ノード
2. **robot_arm_node** - ロボットアームモックノード
3. **log_receiver_node** - ログ受信ノード

## 前提条件

- ROS2 がインストール済み（Humble推奨）
- `colcon` がインストール済み
- 依存パッケージがビルド済み：
  - `state_machine`
  - `robot_arm`
  - `log_receiver`

## ビルド手順

### 1. ワークスペースルートに移動

```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
```

### 2. 全パッケージをビルド

```bash
# ROS2環境のセットアップ
. /opt/ros/humble/setup.bash

# 全パッケージをビルド（推奨）
colcon build

# または、bringupパッケージのみをビルド
# colcon build --packages-select bringup
```

### 3. セットアップスクリプトを実行

```bash
source install/setup.bash
```

## 実行方法

### 方法1: Launch ファイルを使用（推奨）

```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
. /opt/ros/humble/setup.bash
source install/setup.bash

# システム全体を起動
ros2 launch bringup system_bringup.launch.py
```

### 方法2: 各ノードを個別に起動

別々のターミナルで以下を実行：

**ターミナル1（State Machine）:**
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
. /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run state_machine state_machine_node
```

**ターミナル2（Robot Arm）:**
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
. /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run robot_arm robot_arm_node
```

**ターミナル3（Log Receiver）:**
```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
. /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run log_receiver log_receiver_node
```

## トピック構成

システム内で使用されるトピック：

- `/state_machine_log` (std_msgs/String) - ステートマシンのログメッセージ
- `/robot_arm/state` (std_msgs/String) - ロボットアームの状態
- `/robot_arm/end_effector_pose` (geometry_msgs/PoseStamped) - エンドエフェクタ位置

## トラブルシューティング

### ビルドエラーが発生する場合

依存パッケージが正しくビルドされているか確認：

```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
ls -la install/
```

`install/` ディレクトリに以下が存在することを確認：
- `state_machine/`
- `robot_arm/`
- `log_receiver/`

### クリーンビルド

問題が解決しない場合は、クリーンビルドを実行：

```bash
cd /mnt/d/GitLocal/vscode/ros2_state_machine
rm -rf build install log
. /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

### パッケージが見つからないエラー

セットアップスクリプトが正しく実行されているか確認：

```bash
echo $AMENT_PREFIX_PATH
```

正しくセットアップされていれば、ワークスペースのインストールパスが表示されます。

## プロジェクト構成

```
bringup/
├── CMakeLists.txt          # CMakeビルド設定
├── package.xml             # パッケージメタデータと依存関係
├── launch/
│   └── system_bringup.launch.py  # システム起動用launchファイル
└── README.md               # このファイル
```

## 開発者向け情報

### Launch ファイルのカスタマイズ

`launch/system_bringup.launch.py` を編集することで、以下のカスタマイズが可能：

- ノードの起動パラメータの変更
- トピックのリマッピング
- 追加ノードの起動
- 名前空間の設定

例：
```python
Node(
    package='state_machine',
    executable='state_machine_node',
    name='state_machine_node',
    output='screen',
    parameters=[{'param_name': 'value'}],
    remappings=[('old_topic', 'new_topic')]
)
```

## ライセンス

Apache-2.0

## メンテナー

Your Name (you@example.com)
