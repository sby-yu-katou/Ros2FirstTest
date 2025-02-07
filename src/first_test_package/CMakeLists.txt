cmake_minimum_required(VERSION 3.8)
project(first_test_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

########################################
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(first_test_messages REQUIRED)

########################################
# for Publisher
add_executable(talker src/Publisher/TestPublisher.cpp src/Publisher/Worker1.cpp src/Publisher/Worker2.cpp)
ament_target_dependencies(talker rclcpp first_test_messages)

# インクルードファイルを検索する追加のパスを指定
# target_include_directories(talker PRIVATE ./include/)

########################################
# for Subscriber1
add_executable(listener1 src/Subscriber/TestSubscriber1.cpp)
ament_target_dependencies(listener1 rclcpp first_test_messages)

# インクルードファイルを検索する追加のパスを指定
# target_include_directories(listener1 PRIVATE ./include/)

########################################
# for Subscriber2
add_executable(listener2 src/Subscriber/TestSubscriber2.cpp)
ament_target_dependencies(listener2 rclcpp first_test_messages)

# インクルードファイルを検索する追加のパスを指定
# target_include_directories(listener2 PRIVATE ./include/)
########################################

########################################
# 実行可能なパッケージを追加した場合はこちらにも追加する

install(TARGETS
  talker
  listener1
  listener2
  DESTINATION lib/${PROJECT_NAME})

########################################
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
