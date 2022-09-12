cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

set(LEXER carthage-lex)
set(PARSER carthage-parse)
set(CODE_GEN carthage-code-gen)

project(${LEXER} VERSION 1.0)
add_executable(${LEXER} src/lexer/main.cpp)

project(${PARSER} VERSION 1.0)
add_executable(${PARSER} src/parser/main.cpp)

project(${CODE_GEN} VERSION 1.0)
add_executable(${CODE_GEN} src/code-gen/main.cpp)