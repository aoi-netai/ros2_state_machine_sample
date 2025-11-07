cmake_minimum_required(VERSION 3.5)
project(robot_arm)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# アーム制御ノード
add_executable(robot_arm_node
  src/main.cpp
  src/RobotArmMock.cpp
)

ament_target_dependencies(robot_arm_node rclcpp std_msgs geometry_msgs)

target_include_directories(robot_arm_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS
  robot_arm_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
