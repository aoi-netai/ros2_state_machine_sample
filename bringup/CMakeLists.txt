cmake_minimum_required(VERSION 3.5)
project(bringup)

# C++ 標準の設定
set(CMAKE_CXX_STANDARD 17)

# 依存パッケージの検索
find_package(ament_cmake REQUIRED)

# Launch ファイルのインストール
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# Ament パッケージの宣言
ament_package()
