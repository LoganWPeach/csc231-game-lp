cmake_minimum_required(VERSION 3.20)

project(game)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-g -Wall -Wextra -pedantic -std=c++20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(engine)
add_subdirectory(content)

add_executable(game main.cpp
        content/actions/move.h
        content/actions/move.cpp)
target_link_libraries(game PUBLIC engine entities)
