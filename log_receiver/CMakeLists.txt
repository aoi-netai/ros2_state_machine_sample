cmake_minimum_required(VERSION 3.5)
project(log_receiver)

# C++ 標準の設定
set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# ログレシーバーノードの実行ファイル
add_executable(log_receiver_node
  src/main.cpp
)

ament_target_dependencies(log_receiver_node rclcpp std_msgs)

# インクルードディレクトリを指定
target_include_directories(log_receiver_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS
  log_receiver_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
