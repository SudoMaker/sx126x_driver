cmake_minimum_required(VERSION 3.17)
project(sx126x_driver)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(sx126x_driver SX126x.cpp SX126x.hpp)
