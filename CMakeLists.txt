project(TriggerSource)
cmake_minimum_required(VERSION 3.16)

add_executable(TriggerSource ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_include_directories(TriggerSource PRIVATE ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(TriggerSource glog pigpio)

