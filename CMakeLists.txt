cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

set(CARTHAGE carthage)

project(${CARTHAGE} VERSION 1.0)
add_executable(${CARTHAGE} src/lexer/main.cpp)