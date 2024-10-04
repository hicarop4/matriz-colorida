cmake_minimum_required(VERSION 3.22.1)
project(TRABALHO)

set(CMAKE_CXX_STANDARD 17)

add_executable(colorir main.cpp
        includes/MyMatrix.h
        src/Pixel.cpp
        includes/Pixel.h
        src/Calculadora.cpp
        includes/Calculadora.h
        assets/Teste.h
        includes/MyVec.h
        src/GeradorImagem.cpp
        includes/GeradorImagem.h
        src/Impressora.cpp
        includes/Impressora.h
        includes/Coords.h
)
