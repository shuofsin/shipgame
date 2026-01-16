cmake_minimum_required(VERSION 4.1)
project(shipgame)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(shipgame node.cpp node.h main.cpp
        node2d.cpp
        node2d.h
        character.cpp
        character.h)

target_link_libraries(shipgame PRIVATE raylib)
target_link_libraries(shipgame PRIVATE glfw)