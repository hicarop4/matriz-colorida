cmake_minimum_required(VERSION 3.22.1)
project(TRABALHO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TRABALHO main.cpp
        MyMatrix.h
        Pixel.cpp
        Pixel.h
        Calculadora.cpp
        Calculadora.h
        Teste.h
        MyVec.h
        GeradorImagem.cpp
        GeradorImagem.h
        Impressora.cpp
        Impressora.h
)
