cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
project(advancedC)
#add_executable(${PROJECT_NAME} "main.cpp")


add_executable(lambda1 src/lambda1.cpp)
