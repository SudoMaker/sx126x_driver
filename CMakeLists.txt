cmake_minimum_required(VERSION 3.17)
project(sx126x_driver)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(sx126x_driver SX126x.cpp SX126x.hpp)

add_executable(SX126x_ToA_Test ToA_Test.cpp)
target_link_libraries(SX126x_ToA_Test sx126x_driver)