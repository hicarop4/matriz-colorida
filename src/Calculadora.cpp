//
// Created by Hícaro on 13/07/2024.
//

#include "Calculadora.h"

#include <cassert>
#include <cmath>
#include <iostream>

double Calculadora::getDistancia(const int &linha1,
                                 const int &coluna1,
                                 const int &linha2,
                                 const int &coluna2) {
    int a = abs(linha2 - linha1);
    int b = abs(coluna2 - coluna1);
    return sqrt(pow(a, 2) + pow(b, 2));
}

double Calculadora::getMenorDistanciaTrivial(int qtdLinhas, int qtdColunas, int linha, int coluna, Pixel **data){
    double menorDistancia = std::numeric_limits<double>::max();
    bool ehPreto = false;
    // procura a menor distancia entre o pixel atual e os pixels pretos da matriz
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            ehPreto = data[i][j].ehPreto();
            if(ehPreto) {
                menorDistancia = std::min(getDistancia(linha, coluna, i, j), menorDistancia);
            }
        }
    }
    return menorDistancia;
}

unsigned long long Calculadora::getSomaDistancias(int qtdLinhas, int qtdColunas, double **distancias) {
    unsigned long long soma = 0;
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            soma += std::round(distancias[i][j]);
        }
    }
    return soma;
}

void Calculadora::testarCalculadora() {
    assert(Calculadora::getDistancia(0, 0, 1, 1) == sqrt(2));
    std::cout << "Teste 1 passou!\n";
}
