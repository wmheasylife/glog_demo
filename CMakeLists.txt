cmake_minimum_required(VERSION 3.12)
project(glog-example)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/glog)

add_executable(${PROJECT_NAME} "main.cpp")
add_executable(demo2 "demo2.cpp")
add_executable(demo3 "demo3.cpp")
add_executable(demo4 "demo4.cpp")
add_executable(demo5 "demo5.cpp")

# target_include_directories(${PROJECT_NAME} PRIVATE third_party/glog/)

target_link_libraries(${PROJECT_NAME} glog)
target_link_libraries(demo2 glog)
target_link_libraries(demo3 glog)
target_link_libraries(demo4 glog)
target_link_libraries(demo5 glog)
