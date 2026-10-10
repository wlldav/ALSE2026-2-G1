cmake_minimum_required(VERSION 3.10)
project(SistemaBiblioteca CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(sistema_biblioteca
    src/main.cpp
    src/Libro.cpp
    src/Usuario.cpp
    src/Biblioteca.cpp
)
