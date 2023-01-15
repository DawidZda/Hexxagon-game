cmake_minimum_required(VERSION 3.23)
project(Hexxagon)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Hexxagon main.cpp Crystal.cpp Crystal.h
        Player.cpp Player.h Board.cpp Board.h
        Move.cpp Move.h Shared.h
        Game.cpp Game.h AI.cpp AI.h
)


