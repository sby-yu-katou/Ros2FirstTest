cmake_minimum_required(VERSION 3.8)
project(first_test_messages)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

########################################
# 
# 参考 URL:
# 独自メッセージの作成
# https://qiita.com/NeK/items/26751b8ed12976ff977d
# 独自メッセージによるトピック通信
# https://qiita.com/NeK/items/cd00705f7e473f83ca44
# 
########################################
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

########################################
set(msg_files "msg/Point.msg")
# set(srv_files "srv/Point.srv")

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
#  ${srv_files}
)

########################################

ament_export_dependencies(rosidl_default_runtime)

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
