cmake_minimum_required(VERSION 2.8.3)
project(demo)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  turtlesim
  geometry_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

catkin_package()

add_executable(${PROJECT_NAME}_node src/demo_node.cpp)
add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)




