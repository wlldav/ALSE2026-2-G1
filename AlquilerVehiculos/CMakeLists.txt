cmake_minimum_required(VERSION 3.10)
project(SistemaAlquilerVehiculos CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(sistema_alquiler
    src/main.cpp
    src/Vehiculo.cpp
    src/SistemaAlquiler.cpp
)
