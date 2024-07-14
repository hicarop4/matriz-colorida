//
// Created by Hícaro on 14/07/2024.
//

#ifndef GERADORIMAGEM_H
#define GERADORIMAGEM_H

#include "MyMatrix.h"
#include "Pixel.h"
#include "hsv2rgb.cpp"

class GeradorImagem {
public:
    static MyMatrix<Pixel>* gerarImagem(MyMatrix<Pixel> *matrix, MyMatrix<double> *distancias);
private:
    static int encontrarMaiorDistancia(const MyMatrix<double> *distancias);
};



#endif //GERADORIMAGEM_H
