//
// Created by Hícaro on 13/07/2024.
//

#ifndef CALCULAMENORDISTANCIAPIXELPRETO_H
#define CALCULAMENORDISTANCIAPIXELPRETO_H
#include "Pixel.h"
#include <cmath>

#include "Calculadora.h"

class CalculaMenorDistanciaPixelPreto {
public:
    static double getMenorDistancia(int qtdLinhas, int qtdColunas, int linha, int coluna, Pixel **data) {
        double menorDistancia = std::numeric_limits<double>::max();
        bool ehPreto = false;
        // procura a menor distancia entre o pixel atual e os pixels pretos da matriz
        for (int i = 0; i < qtdLinhas; i++) {
            for (int j = 0; j < qtdColunas; j++) {
                ehPreto = data[i][j].ehPreto();
                if(ehPreto) {
                    menorDistancia = std::min(Calculadora::getDistancia(linha, coluna, i, j), menorDistancia);
                }
            }
        }
        return menorDistancia;
    }
};

#endif //CALCULAMENORDISTANCIAPIXELPRETO_H
