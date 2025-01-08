cmake_minimum_required(VERSION 3.5)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(rosbag_interface rosbag_interface.cpp)
target_link_libraries(rosbag_interface ${catkin_LIBRARIES})

