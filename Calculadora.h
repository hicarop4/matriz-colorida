//
// Created by Hícaro on 13/07/2024.
//

#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <algorithm>

#include "src/MyVec.h"
#include "Pixel.h"
#include "MyMatrix.h"

// Classe para calcular a menor distancia entre
// duas células em uma MyMatrix
class Calculadora {
public:
    static double getDistancia(const int &linha1,
                                const int &coluna1,
                                const int &linha2,
                                const int &coluna2);
    static void contarPontosPretos(const MyMatrix<Pixel> *matrix, MyVec<std::pair<int, int>> &coords);

    static double getMenorDistanciaTrivial(int linha, int coluna, const MyMatrix<Pixel> *matrix);
    static double getMenorDistanciaTrivialMelhorado(int linha, int coluna, const MyVec<std::pair<int, int>> &coords);

    static MyMatrix<double> *gerarDistanciasTrivial(const MyMatrix<Pixel> *matrix);
    static MyMatrix<double> *gerarDistanciasTrivialMelhorado(const MyMatrix<Pixel> *matrix);

    static void testarCalculadora();
};



#endif //CALCULADORA_H
