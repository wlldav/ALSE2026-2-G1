cmake_minimum_required(VERSION 3.10)
project(Entrega3_CPP CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. LeetCode Executables
add_executable(leetcode_1797 leetcode/1797_authentication_manager.cpp)
add_executable(leetcode_3709 leetcode/3709_exam_score_tracker.cpp)

# 2. Exercism Executables
add_executable(crypto_square_app 
    exercism/crypto_square/crypto_square.cpp 
    exercism/crypto_square/main.cpp
)

add_executable(bank_account_app 
    exercism/bank_account/bank_account.cpp 
    exercism/bank_account/main.cpp
)
