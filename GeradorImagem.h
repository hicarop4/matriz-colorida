//
// Created by Hícaro on 14/07/2024.
//

#ifndef GERADORIMAGEM_H
#define GERADORIMAGEM_H

#include "src/MyMatrix.h"
#include "src/Pixel.h"

class GeradorImagem {
public:
    static MyMatrix<Pixel>* gerarImagem(MyMatrix<double> *distancias);
private:
    static double encontrarMaiorDistancia(const MyMatrix<double> *distancias);
};



#endif //GERADORIMAGEM_H
