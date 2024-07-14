cmake_minimum_required(VERSION 3.22.1)
project(TRABALHO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TRABALHO src/main.cpp
        src/MyMatrix.h
        src/Pixel.cpp
        src/Pixel.h
        src/Calculadora.cpp
        src/Calculadora.h
        src/Teste.h
        src/MyVec.h
        src/GeradorImagem.cpp
        src/GeradorImagem.h
        src/Impressora.cpp
        src/Impressora.h
)
