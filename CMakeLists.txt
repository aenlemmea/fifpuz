cmake_minimum_required(VERSION 3.28)
project(fifpuz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(EXEC_NAME fifpuz)

add_executable(${EXEC_NAME} src/main.cpp src/board.cc src/controller.cc)
target_include_directories(${EXEC_NAME} PUBLIC include/)
target_include_directories(${EXEC_NAME} PRIVATE include/internal)
