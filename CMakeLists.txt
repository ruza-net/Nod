cmake_minimum_required(VERSION 3.12)
project(NodParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(NodParser main.cpp parse/Token.h parse/Lexer.cpp parse/Lexer.h)
