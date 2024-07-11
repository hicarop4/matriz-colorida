cmake_minimum_required(VERSION 3.28)
project(TRABALHO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TRABALHO src/main.cpp
        src/MyMatrix.h
        src/Input.cpp
        src/Input.h
        src/Pixel.cpp
        src/Pixel.h)
