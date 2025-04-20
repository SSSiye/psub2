cmake_minimum_required(VERSION 3.16)
project(psub2)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(include)

#build
add_executable(pub src/pub.cpp src/pmain.cpp)
ament_target_dependencies(pub rclcpp std_msgs)
add_executable(sub src/sub.cpp src/smain.cpp)
ament_target_dependencies(sub rclcpp std_msgs)

add_executable(psub2_1 src/psub2_1.cpp src/p2main.cpp)
ament_target_dependencies(psub2_1 rclcpp std_msgs)
add_executable(sub2 src/sub2.cpp src/s2main.cpp)
ament_target_dependencies(sub2 rclcpp std_msgs)

add_executable(psub2_2 src/psub2_2.cpp src/p2_2main.cpp)
ament_target_dependencies(psub2_2 rclcpp geometry_msgs)
add_executable(sub2_2 src/sub2_2.cpp src/s2_2main.cpp)
ament_target_dependencies(sub2_2 rclcpp geometry_msgs)

# Install
install(TARGETS
  pub
  sub
  psub2_1
  sub2
  psub2_2
  sub2_2
  DESTINATION lib/${PROJECT_NAME})

ament_package()
