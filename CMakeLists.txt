cmake_minimum_required(VERSION 3.17)
project(Chess_with_AI)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess_with_AI
        Board.cpp
        Board.h
        Chess.cpp
        Piece.cpp
        Piece.h colors.h)
