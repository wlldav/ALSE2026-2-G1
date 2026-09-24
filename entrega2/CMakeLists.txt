cmake_minimum_required(VERSION 3.10)
project(Entrega2_C++ CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. LeetCode Executables
add_executable(leetcode_355 leetcode/355_design_twitter.cpp)
add_executable(leetcode_3484 leetcode/3484_design_spreadsheet.cpp)

# 2. Exercism Libraries / Targets
add_library(robot_simulator_lib exercism/robot_simulator.cpp)
add_library(queen_attack_lib exercism/queen_attack.cpp)

# 3. Sphere Class Executable
add_executable(sphere_app sphere/sphere.cpp sphere/main.cpp)
