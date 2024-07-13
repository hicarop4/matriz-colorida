//
// Created by Hícaro on 13/07/2024.
//

#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <algorithm>
#include <limits>

#include "Pixel.h"

// Classe para calcular a menor distancia entre
// duas células em uma MyMatrix
class Calculadora {
public:
    static double getDistancia(const int &linha1,
                                const int &coluna1,
                                const int &linha2,
                                const int &coluna2);
    static double getMenorDistanciaTrivial(int qtdLinhas, int qtdColunas, int linha, int coluna, Pixel **data);
    static unsigned long long getSomaDistancias(int qtdLinhas, int qtdColunas, double **distancias);
    static void testarCalculadora();
};



#endif //CALCULADORA_H
