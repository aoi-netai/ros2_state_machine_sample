#!/usr/bin/env python3
"""
ROS2 State Machine System Bringup Launch File

このlaunchファイルは以下の3つのノードを同時に起動します:
1. state_machine_node - ステートマシンノード
2. robot_arm_node - ロボットアームモックノード
3. log_receiver_node - ログ受信ノード
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """3つのノードを同時に起動するLaunchDescriptionを生成"""
    
    return LaunchDescription([
        # State Machine Node
        Node(
            package='state_machine',
            executable='state_machine_node',
            name='state_machine_node',
            output='screen',
            parameters=[],
            remappings=[]
        ),
        
        # Robot Arm Node
        Node(
            package='robot_arm',
            executable='robot_arm_node',
            name='robot_arm_node',
            output='screen',
            parameters=[],
            remappings=[]
        ),
        
        # Log Receiver Node
        Node(
            package='log_receiver',
            executable='log_receiver_node',
            name='log_receiver_node',
            output='screen',
            parameters=[],
            remappings=[]
        ),
    ])
