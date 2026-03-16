cmake_minimum_required(VERSION 3.5)
project(state_machine)

# C++ 標準の設定
set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# ソースファイルの集約
set(STATE_MACHINE_SOURCES
  src/main.cpp
  src/StateManager/StateManager.cpp
  src/State/FirstGroup/StateA.cpp
  src/State/FirstGroup/StateB.cpp
  src/State/FirstGroup/StateC.cpp
  src/State/SecondGroup/StateD.cpp
  src/State/SecondGroup/StateE.cpp
)

# ステートマシンノードの実行ファイル
add_executable(state_machine_node ${STATE_MACHINE_SOURCES})

ament_target_dependencies(state_machine_node rclcpp std_msgs)

# インクルードディレクトリを指定
target_include_directories(state_machine_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS
  state_machine_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
